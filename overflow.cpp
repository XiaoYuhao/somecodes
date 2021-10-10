#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int n = 2*1024*1024;
    int buf[n];
    printf("%d\n", n);
    printf("%d\n", sizeof(buf));
    return 0;
}