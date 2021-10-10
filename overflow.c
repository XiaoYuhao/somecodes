#include<stdio.h>
#include<stdlib.h>

const int N = 4*1024*1024;

int func(){
    int buf[8];
    printf("%d\n", N);
    printf("%d\n", sizeof(buf));
    return 0;
}

int main(){
    /*
    int bytes = 32*1024*1024;
    void *stack_top = malloc(bytes);
    void *stack_bottom = stack_top + bytes - 1;
    */
    void *rsp;
    __asm__("movq %%rsp, %0":"=m"(rsp)::);
    printf("%lx\n", rsp);
    void *rbp;
    __asm__("movq %%rbp, %0":"=m"(rbp)::);
    printf("%lx\n", rbp);
    /*
    __asm__("movq %0, %%rsp"::"m"(stack_bottom):);
    func();
    __asm__("movq %0, %%rsp"::"m"(rsp):);
    */
    return 0;
}