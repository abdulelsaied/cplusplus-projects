// Name: Abdul-Rahman El-Saied
// CIS 25 Lab 4 Question 4 Parts 1 and 2
// Benjamin Allen
// 12/12/19
// This program tests the implementation of the MarkovGenerator, and outputs a generated string of variable length.

#include <iostream>
#include <fstream>
#include <string>
#include "MarkovWord.h"
#include "MarkovGenerator.h"

using namespace std;

const string FILE_NAME = "luciddreams.txt";

int main(){

    MarkovGenerator testGenerator;
    ifstream file;
    file.open(FILE_NAME);
    if(file.is_open()){
        testGenerator.readFile(file);
    }
    else{
        cout << "Couldn't open file!" << endl;
        return 0;
    }
    
    file.close();
    //testGenerator.printArray();
    cout << testGenerator.generateText(500) << endl;
    return 0;
}
