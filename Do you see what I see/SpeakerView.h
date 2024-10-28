/*
Ashly Galvan Perez
2419577
galvanperez@chapman.edu
CPSC 350 - 02
PA3: Do You See What I See?
*/
#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H
#include "MonoStack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> //this is going to be used to "setprecision" basically making the output nicely aligned 

class SpeakerView
{
    public:
        SpeakerView();
        SpeakerView(string inputFile);
        virtual ~SpeakerView();
        void FileProcessor(string inputFile);
        void visibility(); //this will determine the person sitting and their current visibility


    private:
        double** people; //this is 2D array that will see the heights of people
        int entries; //this is P; regarding the NxP grid
        int cols; //this is N; regarding the NxP grid
        int e_count; //counts how many entries there are
        int c_count; //counts how many columns there are
};
//BEGIN CODE FROM SOURCE: CHATGPT
SpeakerView :: SpeakerView( string input)
//END CODE FROM SOURSE CHATGPT
{
    people = nullptr; 
    e_count = 0;
    c_count = 0;
}

SpeakerView :: ~SpeakerView()
{
    for (int i = 0; i < e_count; ++i)
    {
        delete [] people [i];
    }
    delete [] people;
}

void SpeakerView :: FileProcessor(string inputFile) //this will read the file and determine the amount of things
{
    ifstream inFS(inputFile);
    string line;

    e_count = 0;

    while(getline(inFS, line))
    {
        e_count++;//here we will determine how many entries there are
        c_count = 0;
        for (int i = 0; i < line.length();i++)
        {
            if(line[i] == ' ')//here if there is a space in between then we won't count it as a column
            {
                c_count++;//we increment the column to determine how many there are
                cols = c_count;
            }
        }
    }
    entries = e_count;
    cols++; //TO TAKE INTO ACCOUNT OF LAST HEIGHT ENTRY


    people = new double*[e_count]; //allocate an array to store e_count aka each row
    for (int i = 0 ; i < e_count; i++)
    {
        people[i] = new double[cols];
    }

    inFS.clear();
    inFS.seekg(0, inFS.beg); //since we read through the file once this will allow us to read through it again from the top

    int tempEntries = 0; //we will use this temporary int to help store the doubles into the array

    while(getline(inFS, line))
    {
        int tempCols = 0; //this will help us keep track of the columns and reset it every line
        string token; //this temp string will be where we store the string of doubles from the input file for now
        
        for(int i = 0; i <= line.length(); i++)//this will allow us to iterate through every char within the string inside the txt file.
        {   
            if(line[i] == ' ' || i == line.length())//here we are checking if the char in the string inside the file has a space or reaches the end of that line meaning it is the end of the string
            {
                if (!token.empty())//so we don't input a token that is empty IT WILL CRASH THE PROGRAM IF EMPTY
                {
                    people[tempEntries][tempCols] = stod(token);//here we change the string token into a double using stod() **referenced from geeksforgeeks
                    ++tempCols;
                    token.clear();//we make the token empty for the next incoming string
                }
            }
            else
            {
                if(isdigit(line[i]) || line[i] == '.') //we have BEGIN and END to worry about so if the char in the line isn't either a digit or a decimal then it can't add itself to token
                {
                    token += line[i];
                }
            }
        }

        tempEntries ++;
    }
    inFS.close();
}

void SpeakerView :: visibility()
{
    //BEGIN CODE FROM CHATGPT
    cout << fixed << setprecision(2);
    //END CODE FROM CHATGPT
    for(int i = 0; i < cols; ++i)
    {
        MonoStack<double> stack(entries, 'd'); //we're going to hardcode in decreasing monotonic stack
        int count = 0; //here we are going to track who in the column could see
        string heights;

        for (int j = 0; j < e_count; ++j)
        {

            double height = people [j][i];//we define our array for the people's heights

            if (height == 0.0)//skip any empty space that may have snuck in
            {
                continue;
            }

            while(!stack.isEmpty() && stack.top() < height) //here we are ensuring the decreasing in monotonic flow
            {
                stack.pop();
            }
            if(stack.isEmpty() || height > stack.top())
            {
                count++;
                stack.push(height);
                
                heights += to_string(height) + " inches, ";//referenced from geeksforgeeks but this collects the heights and inputs it into a string
            }
        }
        cout << "In column " << i << " there are " << count << " that can see. Their heights are: " << heights << endl;
    }
}

#endif