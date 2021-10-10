#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <immintrin.h>

#define LENGTH 1000000010

size_t strlen_base(const char *s)__attribute__((noinline));
size_t strlen_base2(const char *s)__attribute__((noinline));
size_t strlen_base3(const char *s)__attribute__((noinline));
size_t strlen_avx(const char *s)__attribute__((noinline));
size_t strlen_glibc(const char *s)__attribute__((noinline));


size_t strlen_base(const char *s)
{
        unsigned int i = 0;
        while (s[i++] != '\0');
        return --i;
}

size_t strlen_base2(const char *s)
{
        unsigned int i = 0;
        unsigned int a;
        unsigned int *p;

        p = (unsigned int *)s;
        a = *p;

        while (1) {
                if (!(a & 0x000000ff)) {
                        return i * 4;
                } else if (!(a & 0x0000ff00)) {
                        return i * 4 + 1;
                } else if (!(a & 0x00ff0000)) {
                        return i * 4 + 2;
                } else if (!(a & 0xff000000)) {
                        return i * 4 + 3;
                }
                a = p[++i];
        }
}

size_t strlen_base3(const char *s)
{
        unsigned int i = 0;
        unsigned long int a;
        unsigned long int *p;

        p = (unsigned long int *)s;
        a = *p;

        while (1) {
                if (!(a & 0x00000000000000ff)) {
                        return i * 8;
                } else if (!(a & 0x000000000000ff00)) {
                        return i * 8 + 1;
                } else if (!(a & 0x0000000000ff0000)) {
                        return i * 8 + 2;
                } else if (!(a & 0x00000000ff000000)) {
                        return i * 8 + 3;
                } else if (!(a & 0x000000ff00000000)){
                        return i * 8 + 4;
                } else if (!(a & 0x0000ff0000000000)){
                        return i * 8 + 5;
                } else if (!(a & 0x00ff000000000000)){
                        return i * 8 + 6;
                } else if (!(a & 0xff00000000000000)){
                        return i * 8 + 7;
                }
                a = p[++i];
        }
}

size_t strlen_avx(const char *s)
{
        unsigned int i = 0;
        const __m256i *p;
        __m256i mask, zero;

        p = (__m256i *) s;
        zero = _mm256_setzero_si256();

        while (1) {
                mask = _mm256_cmpeq_epi8(*p, zero);
                if (!_mm256_testz_si256(mask, mask)) {
                        return (i * 32) + strlen_base((char *)p);
                }
                i++;
                p++;
        }
}

size_t strlen_glibc(const char *str){
    const char *char_ptr;
    const unsigned long int *longword_ptr;
    unsigned long int longword, himagic, lomagic;

	char_ptr = str;
    /*for (char_ptr = str; ((unsigned long int) char_ptr & (sizeof (longword) - 1)) != 0; ++char_ptr){
        if (*char_ptr == '\0')
        return char_ptr - str;
    }*/

    longword_ptr = (unsigned long int *) char_ptr;

    himagic = 0x80808080L;
    lomagic = 0x01010101L;
    if (sizeof (longword) > 4){
      himagic = ((himagic << 16) << 16) | himagic;
      lomagic = ((lomagic << 16) << 16) | lomagic;
    }
    if (sizeof (longword) > 8)
        abort ();

    for (;;){
        longword = *longword_ptr++;

        if (((longword - lomagic) & ~longword & himagic) != 0){
	        const char *cp = (const char *) (longword_ptr - 1);

	        if (cp[0] == 0)
	            return cp - str;
	        if (cp[1] == 0)
	            return cp - str + 1;
	        if (cp[2] == 0)
	            return cp - str + 2;
	        if (cp[3] == 0)
	            return cp - str + 3;
	        if (sizeof (longword) > 4){
	            if (cp[4] == 0)
		            return cp - str + 4;
	            if (cp[5] == 0)
		            return cp - str + 5;
	            if (cp[6] == 0)
		            return cp - str + 6;
	            if (cp[7] == 0)
		            return cp - str + 7;
	        }
	    }
    }
}

size_t strlen_align(const char *str){
	int len = 0;
	const char *char_ptr;
	unsigned long int longword;
	for (char_ptr = str; ((unsigned long int) char_ptr & (sizeof (longword) - 1)) != 0; ++char_ptr){
        if (*char_ptr == '\0')
        return char_ptr - str;
    }
	len = strlen_base3(char_ptr);
	return char_ptr - str + len;
}


const int MAXN = 1024*1024*512;

int main(){
    char *str;
    str = (char *)calloc(MAXN, sizeof(char));
    for(int i=0;i<MAXN;i++){
        str[i] = 'a';
    }
	str[MAXN-1] = '\0';    

    clock_t c0, c1, c2, c3, c4, c5, c6, t;
    size_t len0, len1, len2, len3, len4, len5, len6;

    t = clock();
    len0 = strlen(str);
    c0 = clock() - t;

    t = clock();
    len1 = strlen_base(str);
    c1 = clock() - t;
    
    t = clock();
    len2 = strlen_base2(str);
    c2 = clock() - t;

    t = clock();
    len3 = strlen_base3(str);
    c3 = clock() - t;

    t = clock();
    len4 = strlen_glibc(str);
    c4 = clock() - t;

    t = clock();
    len5 = strlen_avx(str);
    c5 = clock() - t;

	t = clock();
    len6 = strlen_align(str);
    c6 = clock() - t;

    printf("strlen:       len = %d clock = %lld\n", len0, c0);
    printf("strlen_base:  len = %d clock = %lld\n", len1, c1);
    printf("strlen_base2: len = %d clock = %lld\n", len2, c2);
    printf("strlen_base3: len = %d clock = %lld\n", len3, c3);
    printf("strlen_glibc: len = %d clock = %lld\n", len4, c4);
    printf("strlen_avx:   len = %d clock = %d\n", len5, c5);
	printf("strlen_align: len = %d clock = %d\n", len6, c6);

    return 0;
}