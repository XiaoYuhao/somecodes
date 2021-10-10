#include<cstdlib>
#include<cstdio>

extern "C"{

void *mymalloc(size_t n){
    void *p = malloc(n);
    printf("%0x\n", p);
    return 0;
}

}