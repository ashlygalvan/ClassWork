/*
Ashly Galvan Perez
2419577
galvanperez@chapman.edu
CPSC 350-02
PA 5 - Scare Games
*/
#ifndef TOURNAMENTNODE_H
#define TOURNAMENTNODE_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Monster.h"
using namespace std;

template <typename T>
class TournamentNode
{
    private:
    T* monster;

    public:
    TournamentNode();
    TournamentNode (T* d);
    virtual ~TournamentNode();
    T* getMonster();

    TournamentNode<T>* right;
    TournamentNode<T>* left;
    T* winner;//since we need to access winner pointer in the tournamnettree I made it public

    template <typename S>
    friend class TournamentTree;
};
template <typename T>
TournamentNode<T>::TournamentNode()//default constructor
{
    monster = nullptr;
    right = nullptr;
    left= nullptr;
    winner = nullptr;
}

template <typename T>
TournamentNode<T>::TournamentNode(T* d)// constructor
{
    this->monster = d;//assigns the current object as a monster object.
    right = nullptr;
    left = nullptr;
    winner = nullptr;
}

template <typename T>
TournamentNode<T>:: ~TournamentNode()//deconstructor
{
}

template <typename T>
T* TournamentNode<T>::getMonster()//getter for monster object
{
    return monster;
}

#endif