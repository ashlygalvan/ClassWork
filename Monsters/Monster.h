/*
Ashly Galvan Perez
2419577
galvanperez@chapman.edu
CPSC 350-02
PA 5 - Scare Games
*/
#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <iostream>

using namespace std;
class Monster
{
public:
    Monster();//constructor
    string name;//made the name public so the dot function can access it
    int screamPower;//made the name public so the dot function can access it
    Monster(const string& name, int power);
    virtual ~Monster();
    bool operator>(const Monster& other);//this is what we used to compare the screampower of each monster

};

Monster:: Monster()
{
    name = "";
    screamPower = 0;
}

Monster::Monster(const string& nameMonster, int powerlvl)
{
    name = nameMonster; 
    screamPower = powerlvl;

}

bool Monster::operator>(const Monster& other)
{
    return screamPower > other.screamPower;
}

Monster:: ~Monster()
{}

#endif