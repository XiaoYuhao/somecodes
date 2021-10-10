#include<memory>
#include<iostream>

const int a = 1000;

class A{
public:
    int val;
    static const int con_val = 10;
    A(int _v){
        val = _v;
        std::cout<<"constructor val = "<<val<<std::endl;
    }
    ~A(){
        std::cout<<"deconstructor val = "<<val<<std::endl;
    }
};

int main(){
    /*
    auto p = std::make_shared<A>(523);
    auto r = std::make_shared<A>(123);
    std::cout<<"before assignment"<<std::endl;
    p = r;
    std::cout<<"after assignment"<<std::endl;
*/
    auto ptr = std::unique_ptr<A>(new A(523));
    std::cout<<&a<<std::endl;
    return 0;
}