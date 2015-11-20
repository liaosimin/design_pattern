#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MenuComponent
{
public:
    string name;
    string description;
    MenuComponent(string name, string description):name(name),description(description);
    {

    }
    virtual ~MenuComponent();
    virtual void print()=0;
    virtual bool hasChild()=0;
};

class Menu:public MenuComponent
{
public:
    Menu(string name,string description):MenuComponent(name,description);

    virtual void print()
    {
        printf("Menu: name:%s description:%s\n",name.c_str(),description.c_str());
        for(vector<MenuComponent>::iterator it=menuComponents.iterator;it!=menuComponents.end();it++)
        {
            if(it->hasChild())
            {
                it->print();
            }
        }
    }

    void Menu::addItem(MenuComponent menuComponent)
    {
        menuComponents.push_back(menuComponent);
    }

    virtual bool hasChild(){return true;}
    vector<MenuComponent> menuComponents;
};

class MenuItem:public MenuComponent
{
public:
    MenuItem(string name,string description):MenuComponent(name,description);
    virtual void print()
    {
        printf("MenuItem: name:%s description:%s\n",name.c_str(),description.c_str());
    }
    virtual bool hasChild(){return false;}
};


int main()
{
    MenuComponent menu();
    return 0;
}
