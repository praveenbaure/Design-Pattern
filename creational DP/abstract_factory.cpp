
//
// Created by praveen balure on 02/09/18.
//

#include <cstdio>
/*
 * this #define will only create object of class FactoryB and all its subclasses
 */
#define factoryB
class A{
public:
    virtual void c_name() = 0;
    virtual ~A(){}
};

class B: public A{
    void c_name() override {
        printf("In class B\n");
    }
    ~B(){
        printf("destructed B\n");
    }
};

class C: public A{
    void c_name() override {
        printf("In class C\n");
    }
};

class Factory{
public:
    virtual A * ret_obj() = 0;
    virtual ~Factory(){}
};

class FactoryB: public Factory{
public:
    A *  ret_obj() override {
        return new B;
    }
    ~FactoryB() override {
        printf("Destructed FactoryB\n");
    }
};

class FactoryC: public Factory{
public:
    A * ret_obj() override {
        return new C;
    }
};
int main(){
#ifdef factoryB
    Factory * f1 = new FactoryB;
#elif factoryC
    Factory * f2 = new FactoryC;
#endif
    A * obj = f1->ret_obj();
    obj->c_name();
    delete obj;
    delete f1;
    return 1;
}