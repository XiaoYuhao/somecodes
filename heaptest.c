#include<stdio.h>
#include<stdlib.h>

int main(){
    u_int8_t *buf = malloc(1024*1024);
    
    for(int i=0;;i++){
        buf[i] = 1;
        if(i%1000==0)
            printf("%d\n",i);
    }
    return 0;
}