#include "myArray.h"
#include <iostream>

using namespace std;

// Loop for variable arrSize and populate the passed array with the input
void ReadData(int array[], int arrSize) {
    cout << "Input array elements: " << endl;

    for (int i = 0; i < arrSize; i++) {
        cin >> array[i];
    }

    cout << endl;
}

// Use the bubble sort method to re-arrange array elements in ascending order
void BubbleSort(int array[], int arrSize) {

    // Outer loop starts at first element and goes to second-to-last element
    for (int i = 0; i < arrSize - 1; i++) {

        // Inner loop starts at the next element and goes to last element
        for (int j = i; j < arrSize; j++) {

            // If the neighboring element is smaller, swap with current element
            if (array[i] > array[j]) {
                int temp = array[i];    // Temp holds current element for swap
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

// Print the sorted array in a formatted way
void PrintData(int array[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << array[i] << " ";

        // Print in rows of 5
        if ((i + 1) % 5 == 0) {
            cout << endl;
        }
    }

    cout << endl;
}

// Sort the array in reverse order
void ReverseData(int array[], int arrSize) {

    // Use bubble sort algorithm, but make comparisons the opposite
    for (int i = 0; i < arrSize - 1; i++) {

        // Inner loop starts at the next element and goes to last element
        for (int j = i; j < arrSize; j++) {

            // If the neighboring element is smaller, swap with current element
            if (array[i] < array[j]) {
                int temp = array[i];    // Temp holds current element for swap
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}