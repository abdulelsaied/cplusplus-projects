// Name: Abdul-Rahman El-Saied
// CIS 25 Lab 4 Question 4 Parts 1 and 2
// Benjamin Allen
// 12/12/19
// This program defines the MarkovGenerator class.

#ifndef MarkovGenerator_h
#define MarkovGenerator_h

#include "MarkovWord.h"
#include <string>

using namespace std;

class MarkovGenerator{
    
private:
    
    MarkovWord *foundWords;
    int arrSize;
    int itemsUsed;
    
public:
    
    // constructor
    MarkovGenerator();
    
    // accessors
    int getArrSize(){ return arrSize;}
    int getItems(){ return itemsUsed;}
    MarkovWord *getFoundWords() {return foundWords;}
    void printArray();
    bool findWord(string word);
    int getMarkovWord(string word);
    
    // mutators
    MarkovWord addWord(string word);
    void resizeArray();
    
    //required methods
    string generateText(int numberOfWords);
    void readFile(ifstream &file);
};


#endif /* MarkovGenerator_h */
