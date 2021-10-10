#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int get_proc_rss(pid_t pid){
    char buf[128];
    sprintf(buf, "ps aux | awk \'{if ($2 == \"%d\") print $6}\'", pid);
    FILE *fp;
    fp = popen(buf, "r");
    char num_buf[16] = { 0 };
    fgets(num_buf, 16, fp);
    int res = atoi(num_buf);
    return res;
}

int get_proc_vsz(pid_t pid){
    char buf[128];
    sprintf(buf, "ps aux | awk \'{if ($2 == \"%d\") print $5}\'", pid);
    FILE *fp;
    fp = popen(buf, "r");
    char num_buf[16] = { 0 };
    fgets(num_buf, 16, fp);
    int res = atoi(num_buf);
    return res;
} 


void print_vsz_rss(const char *tag){
    pid_t pid;
    pid = getpid();
    printf("%s : VSZ = %dKB  RSS = %dKB\n", tag, get_proc_vsz(pid), get_proc_rss(pid));
}

int main(){
    print_vsz_rss("start");
    int *num = malloc((10*1024*1024)*sizeof(int));
    print_vsz_rss("malloc");
    for(int i=0;i<5*1024*1024;i++){
        num[i] = i;
    }
    print_vsz_rss("touch");
    return 0;
}