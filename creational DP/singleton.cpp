//
// Created by praveen balure on 01/09/18.
//

#include <cstdio>

class singleton_demo{
    static singleton_demo *class_obj;//unique_obj;
    singleton_demo():count{0}{}
    int count;
public:
    static singleton_demo *get_class_instance();
    void getCount();
    bool operator==( singleton_demo*);
};

singleton_demo * singleton_demo::class_obj = nullptr;

singleton_demo *singleton_demo::get_class_instance() {
    if(nullptr == class_obj)
        class_obj =  new singleton_demo();
    return class_obj;
}

void singleton_demo::getCount() {
    printf("Instance count %d\n",count);
}

bool singleton_demo::operator==(singleton_demo *rhs) {
    return this == rhs;
}

int main(){
    singleton_demo * obj1 = singleton_demo::get_class_instance();
    singleton_demo * obj2 = singleton_demo::get_class_instance();
    printf((obj1 == obj2)?"both objects are same":"Both objects are different");
    return 1;
}