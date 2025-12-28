/*
 * Ezra Addas
 * Program completed 10/19, 11:49AM
 *
 * This library contains functions for handling pointer arrays with the
 * functionality of a basic ArrayList. This includes functions for removing
 * and inserting the elements of a pointer array, effectively making any
 * pointer array a dynamic array.
 *
 * Input should come from the user or from file redirection and be limited to
 * integer and floating-point values (all pointer array cases handle an array
 * of double values).
 *
 * Output is limited to printing error messages in some functions and
 * non-visible changes to arrays.
 *
 * This file (Array.cpp) must be compiled with any main.cpp file or other
 * files that include the header file (Array.h)
 */

#include "Array.h"
#include <iostream>
#include <cmath>

using namespace std;

/* Prints all the elements of the passed pointer array in a neat manner.
 * Takes a pointer array and its size as the input and displays every
 * element in the array as output.
 */
void print(double *arr, int size) {

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

/* Initializes all the elements of the passed pointer array with
 * some kind of input (user or by file redirection). The function assumes
 * that the pointer array has already been allocated to some free space
 * before calling it. Takes a pointer array and its size as the input and
 * assigns every element with some meaningful value as output.
 */
void init(double *arr, int size) {

    cout << "Please enter the elements of the array: ";

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << endl;
}

/* Determines whether two given pointer arrays are equal based
 * on the elements they contain. Takes two pointer arrays and their
 * sizes (assuming size 1 corresponds to array 1 and similar with
 * size 2 and array 2) and returns a boolean operator representing
 * their equality as output.
 */
bool equals(double *arr1, int size1, double *arr2, int size2) {

    // Declare an epsilon value to compute floating-point equality
    double epsilon(0.01);

    // Initialize a boolean value to represent whether the arrays are
    // equal or not (assume true, potentially prove false)
    bool isEqual(true);

    // If the two arrays are different sizes, then they are
    // automatically unequal
    if (size1 != size2) {
        isEqual = false;
    } else {

        // If the sizes are the same, then iterate through the arrays
        // and compare each element at each index
        for (int i = 0; i < size1; i++) {

            // At the first instance of two different values at the
            // same index, the arrays are unequal and there is no
            // need to keep comparing
            if (abs(arr1[i] - arr2[i]) > epsilon) {
                isEqual = false;
                break;
            }
        }
    }

    // Return final boolean value
    return isEqual;
}

/* Searches in a pointer array until it finds the given target
 * value. The function uses an epsilon value to compare the
 * target value to the other floating-point values in the array.
 * Takes a floating-point target value, a pointer array and its
 * size as input and returns the index where the target value
 * was found (-1 if it does not exist) as output.
 */
int find(double num, double *arr, int size) {

    // Declare an epsilon value to compute floating-point equality
    double epsilon(0.01);

    // Initialize an integer value to represent the index where the
    // target value is (set to -1 by default)
    int index(-1);

    // Iterate through the contents of the passed pointer array in
    // search of the target value
    for (int i = 0; i < size; i++) {

        // Check if the element at the current index matches target
        if (abs(arr[i] - num) <= epsilon) {

            // If the element value matches, reassign index value to
            // the current value
            index = i;

            // No need to keep looping
            break;
        }
    }

    return index;
}

/* Clears the given pointer array so that no elements exist
 * in the array and there is no allocated space for it
 * anymore. Takes a pointer array and its size, passed via
 * call-by-reference, and deletes the current allocation
 * and updates the size to 0.
 */
void clear(double *&arr, int &size) {

    // Using the reference of the passed array, delete the current
    // allocation of the pointer space
    delete arr;

    // Now update the reference of size to be 0 so proper access
    // to the array reflects an empty array
    size = 0;
}

/* Retrieves the element at a given index in a pointer array.
 * Error-checking makes sure the given index is not out of
 * bounds for the array. Takes an integer index, a pointer
 * array and its size and returns (if index within bounds) the
 * element at that index.
 */
double get(int index, double *arr, int size) {

    // Initialize a double value to represent the element at
    // the given index
    double value(0.0);

    // If the given index is out of bounds for array indices,
    // print error message
    if ((index < 0) || (index >= size)) {
        cout << "Index out of bounds for size " << size << endl;
    } else {

        // Now return the element at the given index after
        // error checking
        value = arr[index];
    }

    return value;
}

/* Removes the element at a given index in a pointer array,
 * effectively resizing the array elements and its size.
 * Error-checking makes sure the given index is not out of bounds
 * for the array. Takes an integer index, a pointer array and its size
 * (passed via call-by-reference) and arbitrarily removes the
 * element at that index as output.
 */
void remove(int index, double *&arr, int &size) {

    // If given index is out of bounds for the array, print an
    // error message
    if ((index < 0) || (index >= size)) {
        cout << "Index out of bounds for size " << size << endl;
    } else {

        // After passing the error check, initialize a new,
        // temporary pointer array with size - 1
        double *tempArr;
        tempArr = new double[size - 1];

        // Now iterate through the contents of the old array up
        // until given index
        for (int i = 0; i < index; i++) {

            // Copy the contents of the old array into temp array
            tempArr[i] = arr[i];
        }

        // Then iterate through the contents of the old array
        // after given index (essentially skipping the element
        // at the given index, removing it from the array)
        for (int i = index + 1; i < size; i++) {

            // Copy the contents of the old array into temp array
            // at i - 1 (to account for the smaller size of temp)
            tempArr[i - 1] = arr[i];
        }

        // Update size to size - 1
        size -= 1;

        // Delete the old array allocation
        delete arr;

        // Assign the old array pointer to temp array
        arr = tempArr;
    }
}

/* Inserts the given element at a given index in a pointer array,
 * effectively resizing the array elements and its size. Error-checking
 * makes sure the given index is not out of bounds for the array;
 * however, for indices n, index can be n + 1 to append to the very
 * end of the array. Takes an integer index, a pointer array and its
 * size (passed via call-by-reference) and arbitrarily inserts the
 * element at that index as output.
 */
void insert(int index, double num, double *&arr, int &size) {

    // If given index is out of bounds for the array, print an
    // error message (index can be size itself, which essentially
    // appends to the very end of the list
    if ((index< 0) || (index > size)) {
        cout << "Index out of bounds for size " << size << endl;
    } else {

        // After passing the error check, initialize a new temp
        // pointer array with size + 1
        double *tempArr;
        tempArr = new double[size + 1];

        // Now iterate through the contents of the old array
        // until given index
        for (int i = 0; i < index; i++) {

            // Copy the contents of the old array into temp
            tempArr[i] = arr[i];
        }

        // At the given index, assign the array's element to
        // given num
        tempArr[index] = num;

        // If given index was not at the end of the old array,
        // finish iterating through the old array
        if (index < size) {

            for (int i = index; i < size; i++) {

                // Copy the contents of the old array into temp array
                // at i + 1 (to account for the larger size of temp)
                tempArr[i + 1] = arr[i];
            }
        }

        cout << endl;

        // Update the size to size + 1
        size += 1;

        // Delete the old array allocation
        delete arr;

        // Finally assign the old array to the temp array to
        // point to the new array
        arr = tempArr;
    }
}