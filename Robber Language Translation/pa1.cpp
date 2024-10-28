/**
1. Ashly Vanesa Galvan Perez
2. 2419577
3. galvanperez@chapman.edu
4. CPSC 350 - 02
5. Programming Assignment 1: Robber Language Translation
 */

#include "pa1.h"
#include <string>
#include <iostream>
#include <fstream>


Model::Model(){}

Model::~Model(){}

bool vowelIdentification(char c)
{
    return (c == 'a'||c == 'e'||c == 'i'||c == 'o'||c == 'u'||c == 'A'||c == 'E'||c == 'I'||c == 'O'||c == 'U');
}

bool punctuationIdentification(char c)
{
    return (c == '.' || c == '!' || c == '?');
}

std::string Model::translateSingleConsonant(char consonant)
{
    std::string translatedStringC;
    translatedStringC += consonant;
    translatedStringC += "o";
    translatedStringC += consonant;
    return translatedStringC;
}

std::string Model::translateSingleVowel(char vowel)
{
    //returns 1 letter of the char to one letter of string
    //referenced geeksforgeeks
    return std::string (1,vowel);
}

Translator::Translator(){}

Translator::~Translator(){}

std::string Translator::translateEnglishWord(std::string englishWord)
{
    Model model;
    std::string translatedWord;

    for (int i = 0; i < englishWord.length(); i++)
    {
        char letter = englishWord[i];
        if (vowelIdentification(letter))
        {
            translatedWord += model.translateSingleVowel(letter);
        }
        else if (punctuationIdentification(letter)){
            translatedWord += letter;
        }
        else
        { 
            translatedWord += model.translateSingleConsonant(letter);
        }
    }
    return translatedWord;
}

std::string Translator:: translateEnglishSentence(std::string englishSentence)
{
    std::string translatedSentence;
    std::string word;

    for (int i = 0; i < englishSentence.length(); i++)
    {
        //this will help check the punctuation of the text file so it doesn't operate the translation on it
        char letter = englishSentence[i];
        if (letter == ' ' ||punctuationIdentification(letter))
       {
            translatedSentence += translateEnglishWord(word);
            translatedSentence += letter;
            word = "";
        }
        else
        {
            word += letter;
        }
    }
    
    //since the top operation checks for any sort of punctuation it won't read words that may not have it, so 
    //this checks for any reminaing words that may not have it and translate it.
    if (!word.empty())
     {
         translatedSentence += translateEnglishWord(word);
     }


    return translatedSentence;

}

FileProcessor::FileProcessor(){}

FileProcessor::~FileProcessor(){}

void FileProcessor:: processFile(std::string inputFile, std::string outputFile)
{
    Translator translator;

    std::ifstream inFS(inputFile);
    std::ofstream outFS(outputFile);

    std::cout << "Opening file original.txt and output.html" << std::endl;

    //this is error catching in case the file can't open
    if (!inFS.is_open())
    {
        std::cout << "Could not open input file: " << inputFile << std::endl;
        return;
    }
    if (!outFS.is_open())
    {
        std::cout << "Could not open output file: " << outputFile << std::endl;
        return;
    }

    std::string sentences;
    std::string line;

    outFS << "<html><body>" << std::endl;

    while (std::getline (inFS, line))
    {
        outFS << "<p><b>" << line << "</b></p>" << std::endl;
        outFS << "<p><b>" << "\n" << "</b></p>" << std::endl;
    }

    //used stackoverflow for this; moves the cursor for the input file from the end of the file to the top again to reread it.
    //BEGIN CODE FROM SOURCE: https://stackoverflow.com/questions/16393583/how-to-read-same-file-twice-in-a-row
    inFS.clear();
    inFS.seekg(0, inFS.beg);
    ///END OF CODE FROM SOURCE: https://stackoverflow.com/questions/16393583/how-to-read-same-file-twice-in-a-row

    while (std::getline (inFS, sentences))
    {
        std::string translatedSentence = translator.translateEnglishSentence(sentences);

        //used the HTML website you provided on the assignment sheet
        outFS << "<p><b>" << translatedSentence << "</p></b>" << std::endl;
        outFS << "<p><b>" << "\n" << "</b></p>" << std::endl;
    }

    outFS << "</body></html>" << std::endl;

    //closes the files we opened; referenced from Zybooks
    inFS.close();
    outFS.close();

}

//used stackoverflow to help me set up the main function to read the text file and output file from the terminal instead of hard coding it

int main(int argc, char* argv[])
{
    FileProcessor fileprocessor;
    //BEGIN CODE FROM SOURCE:https://stackoverflow.com/questions/21789850/c-how-to-provide-the-input-filename-from-the-command-line-without-hardcoding
    if(argc !=3) //this is making sure there are 3 arguments inputted in
    {
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    //END CODE FROM SOURCE:https://stackoverflow.com/questions/21789850/c-how-to-provide-the-input-filename-from-the-command-line-without-hardcoding

    fileprocessor.processFile(inputFile, outputFile);

    return 0;
}
