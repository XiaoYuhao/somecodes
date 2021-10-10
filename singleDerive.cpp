//#pragma pack(4)
#include<iostream>
class Base{
    int x, y;
};
class Derive1: virtual public Base{
    int a;
    virtual int fun(){
        return a;
    }
};

class Derive2: virtual public Base{
    int b;
    virtual int foo(){
        return b;
    }
};

class Derive: virtual public Derive1, virtual public Derive2{
    int z;
    virtual int fun(){
        return z;
    }
    virtual int foo(){
        return z;
    }
};

int main(){
    Derive* ptr = new Derive;
    /*ptr->x = 1;
    ptr->y = 2;
    ptr->z = 3;
    */
    /*
    std::cout<<&ptr->x<<" - "<<ptr<<std::endl;
    std::cout<<&ptr->y<<" - "<<ptr<<std::endl;
    std::cout<<&ptr->a<<" - "<<ptr<<std::endl;
    std::cout<<&ptr->b<<" - "<<ptr<<std::endl;
    std::cout<<&ptr->z<<" - "<<ptr<<std::endl;
    std::cout<<sizeof(Derive)<<std::endl;*/
    Derive1 *p1;
    p1 = ptr;
    Derive2 *p2;
    p2 = ptr;
    std::cout<<p1<<" - "<<ptr<<std::endl;
    std::cout<<p2<<" - "<<ptr<<std::endl;
    return 0;
}