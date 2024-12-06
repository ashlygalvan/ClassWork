/*
Ashly Galvan Perez
2419577
galvanperez@chapman.edu
CPSC 350-02
PA 5 - Scare Games
*/
#ifndef RUNSCAREGAMES_H
#define RUNSCAREGAMES_H
#include "TournamentTree.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

template <typename T>
class RunScareGames
{
    private:
    vector<T>parseMonsters(string& inputFile);//this is what we use to identify the Monster objects

    public:
    void runTournament(string& inputFile, string& outputFile, string& tournamentType);//this is what we use to generate the tree
};

template <typename T>
void RunScareGames<T>::runTournament(string& inputFile, string& outputFile, string& tournamentType)
{
    vector<T> monsters = parseMonsters(inputFile);//here we call for the file to be parsed through
    TournamentTree<T> tournament(monsters);//we call an instance this way we can call the functions for monsters easier

    if (tournamentType == "single")
    {
        tournament.singleTournament(monsters);//just goes through the first tree
        tournament.saveTreeAsDot(outputFile, tournament.getWinnerRoot());//gives us winner_bracket
    }else if (tournamentType == "double")
    {
        tournament.doubleTournament(monsters);//goes through both the loser bracket and the winner bracket
        tournament.saveTreeAsDot(outputFile, tournament.getWinnerRoot());//this one calls for winner_bracket
        outputFile = "loser_bracket.dot";
        tournament.saveTreeAsDot(outputFile, tournament.getLoserRoot());//and this one calls for loser_bracket
    }
}

template<typename T>
vector<T> RunScareGames<T>::parseMonsters(string& inputFile)
{
    vector<T> monsters;
    ifstream file(inputFile);
    string name;
    int power;

    while(file >> name >> power)
    {
        //BEGIN CODE FROM CHATGPT
        if (!name.empty() && name.back() == ',') 
        {
        name.pop_back();
        }
        monsters.push_back(T(name, power));
        //END CODE FROM CHATGPT
        //this section of code was to help ignore the comma in the monster's name
    }
    return monsters;
}


#endif