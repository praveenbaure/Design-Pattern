//
// Created by praveen balure on 02/09/18.
//
/*
 * In below example menu_factory::getmenu is the factory method and create
 * objects for client
 */
#include <cstdio>

class meal{
public:
    virtual void staple_food() = 0;
};

class breakfast{
public:
    virtual void common_breakfast() = 0;
};
class punjabi: public meal{
public:
    void staple_food() override {
        printf("chicken and daru\n");
    }
};

class marathi: public meal{
public:
    void staple_food() override {
        printf("zunka and bhakar\n");
    }
};

class andra: public meal{
public:
    void staple_food() override {
        printf("sambar and rice");
    }
};

class punjabi_breakfast: public breakfast{
public:
    void common_breakfast() override {
        printf("chole bhature\n");
    }
};

class marathi_breakfast: public breakfast{
public:
    void common_breakfast() override {
        printf("vada pow\n");
    }
};

class andra_breakfast: public breakfast{
public:
    void common_breakfast() override {
        printf("idili chutny\n");
    }
};

class menu_factory{
public:
    virtual meal *get_meal() = 0;
    virtual breakfast *get_breakfast() = 0;
    static menu_factory* getmenu(int );
    virtual ~menu_factory(){
        printf("Deleting menu factory\n");
    }
};

class punjabi_menu: public menu_factory{
    meal * get_meal() override {
        return new  punjabi;
    }
    breakfast *get_breakfast() override {
        return new punjabi_breakfast;
    }
};

class marathi_menu:public menu_factory{
    meal *get_meal() override {
        return new marathi;
    }
    breakfast *get_breakfast() override{
        return  new marathi_breakfast;
    }
    ~marathi_menu() override {
        printf("Deleting marathi menu\n");
    }
};

class andra_menu:  public menu_factory{
    meal * get_meal() override {
        return new andra;
    }
    breakfast  *get_breakfast() override {
        return new andra_breakfast;
    }
};
menu_factory* menu_factory::getmenu(int choice) {
    switch(choice){
        case 1:
            return new punjabi_menu;
            break;
        case 2:
            return new marathi_menu;
            break;
        case 3:
            return new andra_menu;
            break;
        default:
            printf("Not Available\n");
            return nullptr;
    }
}
int main(){
    menu_factory * menu = menu_factory::getmenu(2);
    if(nullptr == menu){
        printf("Unable to fetch menu\n");
        return 0;
    }
    menu->get_breakfast()->common_breakfast();
    menu->get_meal()->staple_food();
    delete menu;
    return 1;
}