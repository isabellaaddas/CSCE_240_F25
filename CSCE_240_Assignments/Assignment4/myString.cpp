/*
 * Ezra Addas
 * Program completed 10/31, 9:23AM
 *
 * This library contains all the code for a myString class that functions
 * like a standard String object. The class utilizes a pointer array of
 * char values that hold all the characters in a given string and a size
 * variable to keep track of the changing size as characters are inserted
 * and removed.
 *
 * Input should come from the user or from file redirection and be limited to
 * integer and character values (all pointer array cases handle an array of
 * char values).
 *
 * Output is limited to printing error messages in some functions and
 * non-visible changes to arrays.
 *
 * This file (myString.cpp) must be compiled with any main.cpp file or other
 * files that include the header file (myString.h)
 */

#include "myString.h"
#include <iostream>

using namespace std;

/* Default constructor setting size to 0 and initializing pointer array
 * with no content, taking no input.
 */
myString::myString() {
    size = 0;
    arr = new char;
}

/* Alternate constructor that sets size to the given size and initializes
 * pointer array with contents of given array. Takes a static array and
 * size variable as input.
 */
myString::myString(int userSize, char userArr[]) {

    size = userSize;
    arr = new char[userSize];

    for (int i = 0; i < userSize; i++) {
        arr[i] = userArr[i];
    }
}

/* Helper method designed to retrieve the size from any myString
 * object.
 */
int myString::getSize() {
    return size;
}

/* Insert method that inserts a given char value into myString object
 * at the given index. Takes an integer and char value as input,
 * printing an error message if index is out of bounds; resizes
 * the array and updates the size as output.
 */
void myString::insert(int index, char value) {

    // If index is negative or bigger than size (but not size itself,
    // allowing user to append at the very end of the string)
    if ((index < 0) || (index > size)) {
        cout << "Index is out of bounds." << endl;
    } else {

        // If error-checking passed, create a new temporary pointer
        // array with size + 1
        char *tempArr = new char[size + 1];

        // Loop through the contents of current array up until
        // index, copying content into temp array
        for (int i = 0; i < index; i++) {
            tempArr[i] = arr[i];
        }

        // Insert the given char value at the given index
        tempArr[index] = value;

        // If index was not the immediate end of the array, keep
        // looping to copy the rest of the old array
        if (index < size) {

            for (int i = index; i < size; i++) {
                // Add into temp array at i + 1 to account for the
                // bigger size
                tempArr[i + 1] = arr[i];
            }
        }

        // Increase size and delete the old array allocation
        size++;
        delete[] arr;

        // Make the old array point to the new array
        arr = tempArr;
    }
}

/* Remove method that removes the char value at the given index from
 * the array. Takes an integer value as input, printing an error message
 * if out of bounds; resizes the array and updates the size as output.
 */
void myString::remove(int index) {

    // If index is negative or bigger than the size (including size
    // itself, within range 0 through size - 1)
    if ((index < 0) || (index >= size)) {
        cout << "Index is out of bounds." << endl;
    } else {

        // If error-checking passed, create a new temporary pointer
        // array with size - 1
        char *tempArr = new char[size - 1];

        // Loop through the current array up until given index,
        // copying contents into temp array
        for (int i = 0; i < index; i++) {
            tempArr[i] = arr[i];
        }

        // Loop through the remaining contents of the old array,
        // skipping over the given index (thereby removing it from
        // the array)
        for (int i = index + 1; i < size; i++) {
            // Add into temp array at i - 1 to account for the smaller
            // size
            tempArr[i - 1] = arr[i];
        }

        // Decrease size and delete the old array's allocation
        size--;
        delete[] arr;

        // Make the old array point to the new array
        arr = tempArr;
    }
}

/* Get method returns the char at the given index. Checks if given
 * index is valid before returning a char value as output.
 */
char myString::get(int index) {

    // Create empty char value
    char value(' ');

    // If index is negative or out of bounds for valid range of
    // indices
    if ((index < 0) || (index >= size)) {
        cout << "Index is out of bounds." << endl;
    } else {
        // If error-checking passed, update value to arr[index]
        value = arr[index];
    }

    return value;
}

/* Find method returns the index where the given char value is
 * first found. Takes a char value as input and returns an integer
 * representing the index as output.
 */
int myString::find(char value) {

    // Create integer value with -1 (assuming char value not in array)
    int index(-1);

    // Loop through contents of array, checking the value of every index
    for (int i = 0; i < size; i++) {
        // If target value is found, update index and break the loop
        // (no need to keep checking)
        if (arr[i] == value) {
            index = i;
            break;
        }
    }

    return index;
}

/* Equals method returns a boolean value based on whether the passed
 * myString object is equal to the myString object it is being called on.
 * Takes a myString object as input and returns the boolean representing
 * equality as output.
 */
bool myString::equals(myString userString) {

    // Create boolean value with default value of true
    bool isEqual(true);

    // If the size of the other string is not the same as this size,
    // not equal
    if (size != userString.getSize()) {
        isEqual = false;
    } else {

        // Otherwise, loop through the contents of both arrays
        // and compare each char value at the index
        for (int i = 0; i < size; i++) {
            // At the first instance of unequal char values,
            // isEqual is false and break the loop
            if (arr[i] != userString.get(i)) {
                isEqual = false;
                break;
            }
        }
    }

    return isEqual;
}

/* Clear method deletes everything in the current pointer array so
 * that the myString object is empty. Takes no input and creates an
 * empty object as output.
 */
void myString::clear() {
    delete arr;
    size = 0;
    // Re-initialize arr to a single allocated char value to avoid
    // undefined behavior in the destructor method (via attempting
    // to delete a null pointer)
    arr = new char;
}

/* Print method prints the entire myString object. */
void myString::print() {

    // Loop through the contents of the pointer array and add to
    // output stream
    for (int i = 0; i < size; i++) {
        cout << arr[i];
    }
}

/* Default destructor method */
myString::~myString() = default;