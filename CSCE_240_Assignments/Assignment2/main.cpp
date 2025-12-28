/*
 * Ezra Addas, CSCE 240
 * Created 9/30, 10:27AM
 * Project 2
 */

#include "myArray.h"
#include <iostream>

using namespace std;

/*
 * Function: This program will take any size array of integers
 * and sort them in ascending and descending order, printing them
 * in a formatted way. The arrays will be sorted by a bubble sort
 * algorithm and the argument for array size will be taken from the
 * command-line arguments, offering a usage statement if not given.
 */
int main(int argc, char** argv) {

    // Check if argument for array size given at command-line
    if (argc < 2) {
        cout << "usage: ./file <array size>" << endl;

        // Exit program if not given
        return 1;
    }

    // If argument for array size given, continue program and use input
    const int arraySize = atoi(argv[1]);
    int myArray[arraySize];

    // Call ReadData function to input all data into the array
    ReadData(myArray, arraySize);

    // Call BubbleSort to sort the array in ascending order
    BubbleSort(myArray, arraySize);

    // Call PrintData to show sorted array
    PrintData(myArray, arraySize);

    // Reverse the order of the array
    ReverseData(myArray, arraySize);

    // Print the data again
    PrintData(myArray, arraySize);

    return 0;
}