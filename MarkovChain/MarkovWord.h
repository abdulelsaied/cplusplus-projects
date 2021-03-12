// This program defines the MarkovWord class.

#ifndef MarkovWord_h
#define MarkovWord_h

#include <iostream>
#include <string>

using namespace std;

class MarkovWord{
    
private:
    
    string word;
    string *successors;
    int itemsUsed;
    int arrSize;
    
public:
    
    // constructors
    MarkovWord(string word);
    MarkovWord();
    
    // accessors
    string *getSuccessors() { return successors;}
    string getWord() { return word;}
    int getItemsUsed() {return itemsUsed;}
    
    // mutators
    void resizeArray();
    void addSuccessor(string word);
    void printSuccessors();
    
};



#endif /* MarkovWord_h */
