// Name: Abdul-Rahman El-Saied
// CIS 25 Lab 4 Question 4 Parts 1 and 2
// Benjamin Allen
// 12/12/19
// This program implements the MarkovGenerator, including all required functions.

#include <iostream>
#include <fstream>
#include "MarkovGenerator.h"
#include <string>
#include <cstdlib>
#include "MarkovWord.h"

using namespace std;

const int STARTING_SIZE = 512;

MarkovGenerator::MarkovGenerator(){
    foundWords = new MarkovWord[STARTING_SIZE];
    arrSize = STARTING_SIZE;
    itemsUsed = 0;
}

// adds a new MarkovWord to foundWords, and sets its word value to the inputted word.
MarkovWord MarkovGenerator::addWord(string word){
    MarkovWord* addedObj = new MarkovWord(word);
    foundWords[itemsUsed] = *addedObj;
    itemsUsed++;
    return *addedObj;
}

// resizes the foundWords array by a factor of 2
void MarkovGenerator::resizeArray(){
    MarkovWord *tempArray = new MarkovWord[arrSize * 2];
    for(int i = 0; i < arrSize; i++){
        tempArray[i] = foundWords[i];
    }
    arrSize *= 2;
    delete[] foundWords;
    foundWords = tempArray;
}

// reads through each word in the file, and correctly places the words in a successor or foundWords array.
void MarkovGenerator::readFile(ifstream &file){
    bool dontRead = false;
    bool first = true;
    string nextWord;
    string firstWord;
    MarkovWord currentObj;
    while(!file.eof()){
        if(itemsUsed == arrSize){
            resizeArray();
        }
        if(dontRead){
            dontRead = false;
        }
        else{
            file >> nextWord;
        }
        if(first){
            firstWord = nextWord;
            first = false;
        }
        if(!findWord(nextWord)){
            MarkovWord toBeAdded = MarkovWord(nextWord);
            foundWords[itemsUsed] = toBeAdded;
            itemsUsed++;
            if(file >> nextWord){
                foundWords[itemsUsed - 1].addSuccessor(nextWord); 
                dontRead = true;
            }
        }
        else{
            string currentMarkovObj = nextWord;
            if(file >> nextWord){ // picking next word to be successor.
                foundWords[getMarkovWord(currentMarkovObj)].addSuccessor(nextWord);
                dontRead = true;
            }
        }
    }
    foundWords[getMarkovWord(nextWord)].addSuccessor(firstWord);
}

// returns true if word exists in the foundWords array.
bool MarkovGenerator::findWord(string word){
    for(int i = 0; i < itemsUsed; i++){
        if(foundWords[i].getWord() == word){
            return true;
        }
    }
    return false;
}

// returns the index of the MarkovWord associated with the given string.
int MarkovGenerator::getMarkovWord(string word){
    if(!findWord(word)){
        cout << "This word isn't associated with any Markov Word!" << endl;
    }
    for(int i = 0; i < itemsUsed; i++){
        if(foundWords[i].getWord() == word){
            return i;
        }
    }
    exit(1);
}

// generates a string with an inputted number of words. randomly extracts words from successor array, repeating until string length is reached.
string MarkovGenerator::generateText(int numberOfWords){
    string outputString = foundWords[0].getWord();
    int counter = 1;
    int successorCapacity;
    int randomSuccessorIndex;
    string randomWord;
    int markovIndex = 0; // started at first MarkovWord
    while(counter < numberOfWords){
        successorCapacity = foundWords[markovIndex].getItemsUsed();
        randomSuccessorIndex = rand() % successorCapacity;
        randomWord = foundWords[markovIndex].getSuccessors()[randomSuccessorIndex];
        outputString  = outputString + " " + randomWord;
        markovIndex = getMarkovWord(randomWord);
        counter++;
    }
    return outputString;
}

// prints each word and its successors
void MarkovGenerator::printArray(){
    for(int i = 0; i < itemsUsed; i++){
        cout << "Word: " << foundWords[i].getWord() << endl;
        cout << "Successors: " << endl;
        foundWords[i].printSuccessors();
    }
}
