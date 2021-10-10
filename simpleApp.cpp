extern "C"{
    int printf(const char * format, ...);
}

#include<iostream>
#include<string>

class Text{
public:
    Text(const std::string &newstr):str(newstr)
    {
        std::cout<<"lval copy constructor"<<std::endl;
    }
    Text(const char *buf):str(buf)
    {   
        std::cout<<"const char * constructor"<<std::endl;
    }
    Text(std::string &&newstr):str(std::move(newstr))
    {
        std::cout<<"rval move constructor"<<std::endl;
    }
private:
    std::string str;
};

class Object{
public:
    /*template<typename T>
    Object(T&& newtext):text(std::forward<T>(newtext))
    {
       
    }*/
    Object(const Text& newtext):text(newtext){
        std::cout<<"Constructor 1."<<std::endl;
    }
    /*Object(Text&& newtext):text(newtext){
        std::cout<<"Constructor 2."<<std::endl;
    }*/
private:
    Text text;
};

class A{
public:
    A(const A& obj):val(obj.val){
        std::cout<<"A copy constructor."<<std::endl;
    }
    A(A&& obj):val(std::move(obj.val)){
        std::cout<<"A move constructor."<<std::endl;
    }
    A(int _val):val(_val){
        std::cout<<"A common constructor."<<std::endl;
    }
    ~A(){
        std::cout<<"A destructor."<<std::endl;
    }
private:
    int val;
};

class B{
public:
    /*B(const A &obj):a(obj){
        std::cout<<"B copy constructor."<<std::endl;
    }
    B(A&& obj):a(std::move(obj)){
        std::cout<<"B move constructor."<<std::endl;
    }
    B(int _val):a(_val){

    }*/

    template<typename T>
    B(T&& param):a(std::forward<T>(param)){
        std::cout<<"B constructor."<<std::endl;
    }
private:
    A a;
};

int main(){
    /*std::string str = "Hello World!";
    Object obj1(str);
    Object obj2(std::move(str));
    Object obj3("Hello World!");*/
    /*
    A obj1(5);
    A obj2(obj1);
    A obj3(std::move(obj1));*/
    A obj1(5);
    B obj2(obj1);
    B obj3(std::move(obj1));
    B obj4(5);
    return 0;
}