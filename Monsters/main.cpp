/*
Ashly Galvan Perez
2419577
galvanperez@chapman.edu
CPSC 350-02
PA 5 - Scare Games
*/
#include <iostream>
#include <string>
#include "RunScareGames.h"
#include "Monster.h"
using namespace std;

int main(int argc, char* argv[])
{
    string inputFile;
    string tournamentType;
    string outputFile;
    if (argc < 2)
    {
        cout << "Provide the input file: " << endl;
        cin >> inputFile;//user enters the name of the file in this case the user needs to enter input.txt
    }else
    {
        inputFile = argv[1];//first argument is the file name
        tournamentType = argv[2];//second argument is the tournamnet type
    }

    ifstream file(inputFile);

    if (!file)
    {
        cout << "Error: Could not open file." << endl;
        return 1;
    }

    outputFile = "winner_bracket.dot";//default dot file name

    RunScareGames<Monster> game;
    
    game.runTournament(inputFile, outputFile, tournamentType);//we run the code

    return 0;
    
}
