
int foo(int a, int b);

int bar(int a, int b){
    static int val;
    return a + b;
}

int global_var;
int var;

int main(){
    static int static_val;
    int local;
    foo(0, 1);
    return 0;
}