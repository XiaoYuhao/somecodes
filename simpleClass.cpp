
extern "C"{

int printf(const char * format, ...);
long unsigned strlen(const char *str);

}


class Mystream{
public:
    int size;
    char *ptr;
    explicit Mystream(int _size){
        size = _size;
    }
    Mystream(const char *str){
        //memcpy...
        size = strlen(str);
    }
};
 

int main(){
    Mystream s1("hello world.");
    printf("%d\n", s1.size);
    Mystream s2 = "This is a funny thing.";
    printf("%d\n", s2.size);
    Mystream s3(10);
    printf("%d\n", s3.size);
    Mystream s4 = 5;
    printf("%d\n", s4.size);
    Mystream s5 = 'x';
    printf("%d\n", s5.size);
    return 0;
}