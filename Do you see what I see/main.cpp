/*
Ashly Galvan Perez
2419577
galvanperez@chapman.edu
CPSC 350 - 02
PA3: Do You See What I See?
*/
#include <iostream>
#include "SpeakerView.h"

int main (int argc, char* argv[]) //this was referemced from a past PA, specifically the main cpp file from PA1
{
    string file;
    if (argc < 2)
    {
        cout << "Provide the input file: " << endl;
        cin >> file;
    }else
    {
        file = argv[1];
    }

    SpeakerView speakerView(file); //created an instance of the Speakerview class
    speakerView.FileProcessor(file);
    speakerView.visibility();

    return 0;

}