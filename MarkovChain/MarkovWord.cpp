// This program implements the MarkovWord, and includes all required methods.

#include <iostream>
#include "MarkovWord.h"
#include <string>

using namespace std;

const int STARTING_SIZE = 8;

MarkovWord::MarkovWord(string word){
    this->word = word;
    successors = new string[STARTING_SIZE];
    arrSize = STARTING_SIZE;
    itemsUsed = 0;
}

MarkovWord::MarkovWord(){
    successors = new string[STARTING_SIZE];
    arrSize = STARTING_SIZE;
    itemsUsed = 0;
}

// resizes the array by a factor of 2
void MarkovWord::resizeArray(){
    arrSize *= 2;
    string *tempArray = new string[arrSize];
    for(int i = 0; i < itemsUsed; i++){
        tempArray[i] = successors[i];
    }
    delete[] successors;
    successors = tempArray;
}

// adds an inputted word to the successor list of a MarkovWord
void MarkovWord::addSuccessor(string word){
    if(arrSize == itemsUsed){
        resizeArray();
    }
    successors[itemsUsed] = word;
    itemsUsed++;
}

//  displays the successors of a MarkovWord
void MarkovWord::printSuccessors(){
    for(int i = 0; i < itemsUsed; i++){
        cout << successors[i] << endl;
    }
}
