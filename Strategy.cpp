#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

class FlyBehavior
{
public:
    virtual void fly()=0;
};
class FlyWithWings:public FlyBehavior
{
public:
    virtual void fly()
    {
        cout<<"I am flying!!\n";
    }
};
class FlyNoWay:public FlyBehavior
{
public:
    virtual void fly()
    {
        cout<<"I can't fly!!\n";
    }
};
class FlyRocketPowered:public FlyBehavior
{
public:
    virtual void fly()
    {
        cout<<"I am flying with a rocket\n";
    }
};


class QuackBehavior
{
public:
    virtual void quack()=0;
};
class Quack:public QuackBehavior
{
public:
    virtual void quack()
    {
        cout<<"Quack\n";
    }
};
class MuteQuack:public QuackBehavior
{
public:
    virtual void quack()
    {
        cout<<"<< Silence >>\n";
    }
};
class Squeak:public QuackBehavior
{
public:
    virtual void quack()
    {
        cout<<"Squeak\n";
    }
};


class Duck
{
    FlyBehavior* flyBehavior;
    QuackBehavior* quackBehavior;
public:
    Duck(FlyBehavior* fb, QuackBehavior* qb):flyBehavior(fb),quackBehavior(qb){}
    void setFlyBehavior(FlyBehavior* fb)
    {
        flyBehavior = fb;
    }
    void setQuackBehavior(QuackBehavior* qb)
    {
        quackBehavior = qb;
    }
    void performFly()
    {
        flyBehavior->fly();
    }
    void performQuack()
    {
        quackBehavior->quack();
    }
    void swim()
    {
        printf("All ducks float,even decoys");
    }
};
class ModelDuck:public Duck
{
public:
    void display()
    {
        cout<<"I am a modelDuck\n";
    }
};

int main()
{
    FlyNoWay flynoway;
    Squeak squeak;
    Duck duck(&flynoway,&squeak);
    duck.performFly();
    duck.performQuack();
    FlyRocketPowered flyro;
    duck.setFlyBehavior(&flyro);
    duck.performFly();
}
