/**
1. Ashly Vanesa Galvan Perez
2. 2419577
3. galvanperez@chapman.edu
4. CPSC 350 - 02
5. Programming Assignment 1: Robber Language Translation
 */
#ifndef PA1_H
#define PA1_H
#include <string>
class Model
{
    public:
        Model();
        virtual ~Model();
        std::string translateSingleConsonant(char c);
        std::string translateSingleVowel(char a);
    private:
        bool vowelIdentification(char c);
        bool punctuationIdentification(char c);
};

class Translator
{
    public:
        Translator();
        virtual ~Translator();
        std::string translateEnglishWord(std::string word);
        std::string translateEnglishSentence(std::string w);
};

class FileProcessor
{
    public: 
        FileProcessor();
        virtual ~FileProcessor();
        void processFile(std::string processF, std::string processG);
};

#endif //PA1_H