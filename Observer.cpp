#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Observer
{
public:
    virtual void update(float temp, float humidity, float pressure)=0;
};

class Subject
{
public:
    virtual void registerObserver(Observer* o)=0;
    virtual void removeObserver(Observer* o)=0;
    virtual void notifyObservers()=0;
};

class DisplayElement
{
    virtual void display()=0;
};

class WeaterData:public Subject
{
    vector<Observer*> observers;
    float temperature;
    float humidity;
    float pressure;
public:
    virtual void registerObserver(Observer* o)
    {
        observers.push_back(o);
    }
    virtual void removeObserver(Observer* o)
    {
        vector<Observer*>::iterator it = find(observers.begin(), observers.end(), o); //查找
        if(it!=observers.end())observers.erase(it);
    }
    virtual void notifyObservers()
    {
        for(vector<Observer*>::iterator it=observers.begin();it!=observers.end();it++)
        {
            (*it)->update(temperature, humidity, pressure);
        }
    }
    void measurementChange()
    {
        notifyObservers();
    }
    void setMeasurement(float temp, float humidity, float pressure)
    {
        this->temperature=temp;
        this->humidity = humidity;
        this->pressure = pressure;
        measurementChange();
    }
};

class CurrentConditionsDisplay:public Observer, DisplayElement
{
    float temperature;
    float humidity;

    virtual void update(float temp, float humidity, float pressure)
    {
        this->temperature = temp;
        this->humidity = humidity;
        display();
    }

    virtual void display()
    {
        cout<<"Current Conditions: "<<temperature<<"F degrees and "<<humidity<<"% humidity\n";
    }
};

class StatisticsDisplay:public Observer, DisplayElement
{
    float temperature;
    float humidity;
    float pressure;

    virtual void update(float temp, float humidity, float pressure)
    {
        this->temperature = temp;
        this->humidity = humidity;
        this->pressure = pressure;
        display();
    }

    virtual void display()
    {
        cout<<"Statistics: "<<temperature<<"F degrees and "<<humidity<<"% humidity and "<<pressure<<" pressure\n";
    }
};


int main()
{
    WeaterData weaterData;

    CurrentConditionsDisplay CurrentDisplay;
    weaterData.registerObserver(&CurrentDisplay);
    weaterData.setMeasurement(30,13,22);

    StatisticsDisplay statistics;
    weaterData.registerObserver(&statistics);
    weaterData.setMeasurement(100,13.1,220);

    weaterData.removeObserver(&CurrentDisplay);
    weaterData.setMeasurement(100.1,14.1,320);
}
