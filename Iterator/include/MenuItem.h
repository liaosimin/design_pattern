#ifndef MENUITEM_H
#define MENUITEM_H
#include <string.h>

class MenuItem
{
    public:
        MenuItem(string name,string description,bool isvegetarian,double price):m_name(name),m_description(description),m_isvegetarian(isvegetarian),m_price(price);
        virtual ~MenuItem();
        string Getname() { return m_name; }
        string GetDescription() { return m_description; }
        bool isVegetarian(){return m_isvegetarian;}
        double GetPrice(){return m_price;}
    protected:
    private:
        string m_name;
        string m_description;
        bool m_isvegetarian;
        double m_price;
};

#endif // MENUITEM_H
