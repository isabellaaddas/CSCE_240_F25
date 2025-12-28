/*
 * iaddas, created 9/29
 */

#include "sept_29.h"
#include <iostream>

// Best practice: make a .h file for prototypes, .cpp for definitions (include
// same header file), then use #include to attach header file and add .cpp file
// of definitions when compiling main.cpp so they all compile together

// Also best to put #include <iostream> and using namespace std only in
// necessary files

using namespace std;

// argc tells how many things in command-line
// argv is the array of arrays of each argument in command-line
// ( To take int from second argument at command-line, atoi(argv[index]) )
// ** Use this for BubbleSort program **

// Error-checking: include if statement to make sure arguments are included
// at command-line (usage statement)
int main(int argc, char** argv) {
    const int arrSize = 10;
    int myArray[arrSize];

    initArray(myArray, arrSize);
    printArray(myArray, arrSize);
}

// Every time you pass array to function, you MUST pass size alongside with it
// Passing arrays is ALWAYS call-by-reference
void initArray(int array[], int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        array[i] = i;
    }
}

void printArray(int array[], int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        cout << "Index [" << i << "]: " << array[i] << endl;
    }
}