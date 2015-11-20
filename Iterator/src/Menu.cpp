#include "Menu.h"

Menu::Menu()
{
    //ctor
}

DinerMenu::DinerMenu()
{

}
void DinerMenu::addItem(string name,string description,bool isvegetarian,double price)
{
    MenuItem menuItem = new MenuItem(name,description,isvegetarian,price);
    menuitens.push_back(menuItem);
}
