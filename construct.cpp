#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

class A{
public:
    int val;
    char *buffer;
    A(int n){
        val = n;
        buffer = new char[val];
        cout<<"A construct function."<<endl;
    }
    A(const A &a){
        val = a.val;
        buffer = new char[val];
        memcpy(buffer, a.buffer, val);
        cout<<"A copy construct function."<<endl;
    }
    A& operator=(const A &a){
        val = a.val;
        buffer = new char[val];
        memcpy(buffer, a.buffer, val);
        cout<<"A operator function."<<endl;
        return *this;
    }
    /*A(A &&a) noexcept {
        val = a.val;
        buffer = a.buffer;
        a.buffer = NULL;
        cout<<"A move construct function"<<endl;
    }*/
    ~A(){
        delete buffer;
        cout<<"A destory function."<<endl;
    }
};

A foo(int a, int b){
    int c = a + b;
    return A(c);
}

int main(){
    //vector<A> vec;
    //A a(0);
    A &&a;
    a = A(4+5);
    cout<<a.val<<endl;
    //vec.emplace_back(9);
    //vec.push_back(9);
    //cout<<vec[0].val<<endl;
    return 0;
}