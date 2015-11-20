#ifndef MENU_H
#define MENU_H
#include <MenuItem.h>
#include <vector>

class Menu
{
    public:
        Menu();
        virtual Iterator createIterator();
    protected:
    private:
};

class DinerMenu:public Menu
{
    vector<MenuItem> menuitens;
    public:
        DinerMenu();
        void addItem(string name,string description,bool isvegetarian,double price);
}

#endif // MENU_H
