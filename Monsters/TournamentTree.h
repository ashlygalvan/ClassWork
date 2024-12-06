/*
Ashly Galvan Perez
2419577
galvanperez@chapman.edu
CPSC 350-02
PA 5 - Scare Games
*/
#ifndef TOURNAMNETTREE_H
#define TOURNAMENTTREE_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "TournamentNode.h"
using namespace std;

template <typename T>
class TournamentTree
{
    private:
    TournamentNode<T>* winnerRoot;//points to the winner root node
    TournamentNode<T>* loserRoot;//points to the loser root node
    vector<TournamentNode<T>*> loserBracket;//collects all monster nodes that lost in the first tree

    public:
    TournamentTree();//default constructor
    TournamentTree(vector<T> monsters);//constructor
    virtual ~TournamentTree();//deconstructor
    TournamentNode<T>* singleTournament(vector<T>& monsters); //this is the winnner bracket where all monsters will be fighting for the first round
    TournamentNode<T>* loserTree(vector<TournamentNode<T>*> losers);//this is the loser bracket where all the loser monsters have a chance to fight
    void doubleTournament(vector<T>& monsters);//this is the final match where the winner of the first and loser bracket compete
    void saveTreeAsDot(const std::string& filename, TournamentNode<T>* rootNode);//dot file
    void saveTreeAsDotHelper(TournamentNode<T>* node, std::ofstream& file, int& nodeID);
    TournamentNode<T>* getWinnerRoot();//getter for the winner root node used in the runscaregames header
    TournamentNode<T>* getLoserRoot();//getter for the loser root node used in the runscaregames header

};

template <typename T>
TournamentTree<T>::TournamentTree()
{}


template <typename T>
TournamentTree<T>::TournamentTree(vector<T> monsters)//making sure nothing is left behind as it, no floating pointer
{
    winnerRoot = nullptr;
    loserRoot = nullptr;
    loserBracket.clear();
}

template <typename T>
TournamentTree<T>::~TournamentTree()
{
    if (loserRoot != nullptr)//deletion of loser and winner root nodes if they are not a null pointer
    {
        delete loserRoot;
    }
    if(winnerRoot != nullptr)
    {
        delete winnerRoot;
    }
}

template <typename T>
TournamentNode<T>* TournamentTree<T>::singleTournament(vector<T>& monsters)
{
    if (monsters.size()==1)//here is where in best case scenario the monster vector only has one monster so automatically make them the winneroot
    {
        winnerRoot = new TournamentNode<T>(&monsters[0]);//we create a node for the monster object
        return winnerRoot;
    }

    vector<TournamentNode<T>*> currentRound;//this will help us determine what monster nodes are still in the tournamnet

    for(int i = 0; i < monsters.size(); i++)
    {
        TournamentNode<T>* monsterCompetitor = new TournamentNode<T>(&monsters[i]);//we parse through the monster object vector and create nodes for all monsters
        currentRound.push_back(monsterCompetitor);//then we add it to the currentRound
    }

    while (currentRound.size() > 1)
    {
        vector<TournamentNode<T>*> nextRound;//we create this to help us keep track of which monsters are still in the bracket

        for(int j = 0; j < currentRound.size(); j += 2)//we do j += 2 since we are going through two monsters at a time to compete aginst each other
        {
            if(j + 1 < currentRound.size())
            {
                if(currentRound[j]->getMonster()->screamPower > currentRound[j+1]->getMonster()->screamPower)//comparison of screamPower
                {
                    currentRound[j]->winner = currentRound[j]->getMonster();//here we use the winner pointer to determien who was the winner
                    loserBracket.push_back(currentRound[j+1]);//and we push the losing monster into the loserBracket
                }else
                {
                    currentRound[j+1]->winner = currentRound[j + 1]->getMonster();//same applies here
                    loserBracket.push_back(currentRound[j]);
                }

                TournamentNode<T>* match;//here we create a new node specfically for the winning monster
                if (currentRound[j]->winner->screamPower > currentRound[j + 1]->winner->screamPower)//based off who won we create a node using currentRound[j] or [j+1]
                {
                    match = new TournamentNode<T>(currentRound[j]->winner);
                }else 
                {
                    match = new TournamentNode<T>(currentRound[j + 1]->winner);
                }

                match->left = currentRound[j];//here we assign the left child node
                match->right = currentRound[j+1];//here we assing the right child node

                nextRound.push_back(match);//then we push the winning node into the nextRound
            }else
            {
                nextRound.push_back(currentRound[j]);//this occurs when there is an off number of monster, it automatically gets pushed to the nextRound
            }
        }
        currentRound = nextRound;//then we assign the currentRound with the monsternodes that are in the nextRound and iterate through again
    }
    winnerRoot = currentRound[0];//once we reach the winner we assing the winnerRoot of this tree
    return winnerRoot;
}

template <typename T>
TournamentNode<T>* TournamentTree<T>::loserTree(vector<TournamentNode<T>*> losers)//same thing as the single tournamnet, but this handles just the losersmonsters
{
   //best case scenario where there is only one monster left
   if (losers.size() == 1)
   {
    loserRoot = losers[0];
    return loserRoot;
   }

   vector<TournamentNode<T>*> currentRound = losers;//since the losers are coming from the singleTournamnet function they are already in nodes so we assign currentRound with losers

   while (currentRound.size() > 1)//everything is identical to the process in singleTournament
   {
        vector<TournamentNode<T>*> nextRound;

        for(int i = 0; i < currentRound.size(); i += 2)
        {
            if(i + 1 < currentRound.size())
            {
                if (currentRound[i]->getMonster()->screamPower > currentRound[i + 1]->getMonster()->screamPower) 
                {
                    currentRound[i]->winner = currentRound[i]->getMonster();//only difference is that we removed the loserbracket
                } else 
                {
                    currentRound[i + 1]->winner = currentRound[i + 1]->getMonster();
                }

                // Create a new node for the match winner
                TournamentNode<T>* matchNode;
                if (currentRound[i]->winner->screamPower > currentRound[i + 1]->winner->screamPower) 
                {
                    matchNode = new TournamentNode<T>(currentRound[i]->winner);
                } else {
                matchNode = new TournamentNode<T>(currentRound[i + 1]->winner);
                }

                matchNode->left = currentRound[i];//left child node
                matchNode->right = currentRound[i + 1];//right child node

                nextRound.push_back(matchNode);
                
            }else
            {
                //this is when the tree has an odd numbers of competitors, they'll get pushed to the next round automatically.
                nextRound.push_back(currentRound[i]);
            }
        }
        currentRound = nextRound;
   }
    loserRoot = currentRound[0];//we assign the loserRoot
    return loserRoot;
}

template <typename T>
void TournamentTree<T>::doubleTournament(vector<T>& monsters)
{
    singleTournament(monsters);//here we iterate through the monsters vector into the singleTournament
    loserTree(loserBracket);//then we iterate through the bracket we set up inside th singleTournament

    //BEGIN CODE FROM GEMINI
    T* ultimateWinner;
    if (winnerRoot->getMonster()->screamPower > loserRoot->getMonster()->screamPower) {
        ultimateWinner = winnerRoot->getMonster();
    } else {
        ultimateWinner = loserRoot->getMonster();
    }

    // Create a final match node to represent the ultimate winner
    TournamentNode<T>* finalMatch = new TournamentNode<T>(ultimateWinner);
    //END CODE FROM GEMINI

    finalMatch->left = winnerRoot;//left child node
    finalMatch->right = loserRoot;//right child node

    winnerRoot = finalMatch;//final winner
}

template <typename T>//code provided by assignment
void TournamentTree<T>::saveTreeAsDot(const std::string& filename, TournamentNode<T>* rootNode) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file for DOT output: " << filename << "\n";
        return;
    }

    file << "digraph TournamentTree {\n";
    int nodeID = 0;
    saveTreeAsDotHelper(rootNode, file, nodeID);
    file << "}\n";
    file.close();
}

// Recursive helper function for DOT file generation
template <typename T>
void TournamentTree<T>::saveTreeAsDotHelper(TournamentNode<T>* node, std::ofstream& file, int& nodeID) {
    if (node == nullptr) return;

    int currentID = nodeID++;
    file << "    node" << currentID << " [label=\"" << node->winner->name
         << " (Power: " << node->winner->screamPower << ")\"];\n";

    if (node->left) {
        int leftID = nodeID;
        saveTreeAsDotHelper(node->left, file, nodeID);
        file << "    node" << currentID << " -> node" << leftID << ";\n";
    }

    if (node->right) {
        int rightID = nodeID;
        saveTreeAsDotHelper(node->right, file, nodeID);
        file << "    node" << currentID << " -> node" << rightID << ";\n";
    }
}

template <typename T>
TournamentNode<T>* TournamentTree<T>::getWinnerRoot() //getter for winner root
{
    return winnerRoot;
}

template <typename T>
TournamentNode<T>* TournamentTree<T>::getLoserRoot()//getter for loser root
{
    return loserRoot;
}


#endif