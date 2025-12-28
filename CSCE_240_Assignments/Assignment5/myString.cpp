/*
 * Ezra Addas
 * Program completed 11/16 10:01PM, edited 11/17 3PM
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
    arr = nullptr;
}

/* Alternate constructor that sets size to the given size and initializes
 * pointer array with contents of given array. Takes a static array and
 * size variable as input.
 */
myString::myString(int userSize, char userArr[]) {
    size = userSize;
    arr = new char[userSize];

    for (int i = 0; i < size; i++) {
        arr[i] = userArr[i];
    }
}

/* Copy constructor that takes another string and copies it to the new
 * myString object. Takes another myString object as input and returns
 * the new myString object copied from the other string as output.
 */
myString::myString(const myString &other) {
    // Set size to the other string's size and re-allocate
    // the char array
    size = other.size;
    arr = new char[other.size];

    // Perform deep copy of other string's array contents
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
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

/* Set method that changes a single char value at a given index in
 * a myString object. Takes an integer value for the index and a
 * char value to replace the char value at that index. A changed
 * myString object is the output.
 */
void myString::set(int index, char value) {
    // Check if index is out of bounds and print an error if so
    if ((index < 0) || (index >= size)) {
        cout << "Index is out of bounds." << endl;
    } else {
        // Otherwise, change the value at index
        arr[index] = value;
    }
}

/* Boolean method that simply tells if a myString object is
 * empty or not. Takes no input and returns a boolean value
 * representing emptiness as output.
 */
bool myString::isEmpty() const {
    // If size of the string is 0, then it's empty
    if (size == 0) return true;

    // Otherwise, it isn't empty
    return false;
}

/* Find method that looks for the given substring value
 * (another myString object) in the string the method is being
 * performed on. Takes a myString object via call-by-value as input
 * and returns an integer value of the first instance where the
 * substring was found (-1 if not found) as output.
 */
int myString::find(myString value) const {
    int index(-1);

    // If the other value is a bigger string, it's not possible for
    // it to be in this string
    if (value.size <= size) {

        // Loop through the difference between this string's size
        // and the substring's size (0 inclusive for same-size strings)
        for (int i = 0; i <= size - value.size; i++) {

            // Every time outer loop body is called, create boolean
            // value representing equality with a value of "true"
            bool isMatch = true;

            // Create inner loop to iterate through the contents of
            // the substring
            for (int j = 0; j < value.size; j++) {
                // If the value at this string's char array[i + j]
                // (shift to account for substring's smaller size),
                // is not the same as the value at the substring's
                // index j, isMatch is false and inner loop must quit
                if (arr[i + j] != value.arr[j]) {
                    isMatch = false;
                    break;
                }
            }

            // After inner loop execution, if isMatch is still true,
            // then the substring exists in this string and index is
            // i, and outer loop can be exited
            if (isMatch) {
                index = i;
                break;
            }
        }
    }

    return index;
}

/* Clear method deletes everything in the current pointer array so
 * that the myString object is empty. Takes no input and creates an
 * empty object as output.
 */
void myString::clear() {
    delete[] arr;
    size = 0;

    // Re-initialize arr to a nullptr to avoid
    // undefined behavior in the destructor method
    arr = nullptr;
}

/* Print method prints the entire myString object. */
void myString::print() {
    // Loop through the contents of the pointer array and add to
    // output stream
    for (int i = 0; i < size; i++) {
        cout << arr[i];
    }
}

/* Overloaded operator [] method retrieves the char value at the given
 * index (like a get method). Takes an integer value for the index
 * as input and returns the char value found at the index (if valid)
 * as output.
 */
char myString::operator[](int index) {
    // Create empty char value (terminator character)
    char value('\0');

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

/* Overloaded operator == method returns a boolean value based on
 * whether the passed myString object is equal to the myString object
 * on the left side of the operator. Takes a myString object as input
 * and returns the boolean representing equality as output.
 */
bool myString::operator==(const myString& other) const {
    // Create boolean value with default value of true
    bool isEqual(true);

    // If the size of the other string is not the same as this size,
    // not equal
    if (size != other.size) {
        isEqual = false;
    } else {
        // Otherwise, loop through the contents of both arrays
        // and compare each char value at the index
        for (int i = 0; i < size; i++) {

            // At the first instance of unequal char values,
            // isEqual is false and break the loop
            if (arr[i] != other.arr[i]) {
                isEqual = false;
                break;
            }
        }
    }

    return isEqual;
}

/* Overloaded operator != operator method returns a boolean
 * value based on whether the passed myString object is not equal
 * to the myString object on the left side of the operator.
 * Takes a myString object as input and returns the boolean representing
 * inequality as output.
 */
bool myString::operator!=(const myString& other) const {
    return !(*this == other);
}

/* Overloaded operator + operator method returns a new
 * myString object with no name that contains the concatenation of
 * the left side myString object with the right side myString object.
 * Takes a myString object as input and returns a myString object
 * of the result as output.
 */
const myString myString::operator+(const myString& other) const {
    // Set up the result myString object with private constructor
    myString result = myString((size + other.size), '\0');

    // Loop through the operated on string contents and add them to
    // the result string array
    for (int i = 0; i < size; i++) {
        result.arr[i] = arr[i];
    }

    // Then, loop through the other string's contents and add them to
    // the rest of the result string array
    for (int i = 0; i < other.size; i++) {
        result.arr[i + size] = other.arr[i];
    }

    return result;
}

/* Overloaded operator = method effectively reassigns this string's
 * char array to a deep copy of the other string's, performing the
 * same operations as the copy constructor. Takes another myString
 * object as input and returns a newly allocated array and size
 * that is assigned to this string as output.
 */
myString& myString::operator=(const myString& other) {
    // If this string is the same address as the passed string, do
    // not copy
    if (this != &other) {
        // Delete the current array allocation
        delete[] arr;

        // Set size to the other string's size and re-allocate
        // the char array
        size = other.size;
        arr = new char[other.size];

        // Perform deep copy of other string's array contents
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }

        return *this;
    } else {
        return myString();
    }
}

/* Private constructor method */
myString::myString(int newSize, char value) {
    size = newSize;
    arr = new char[newSize];

    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
}

/* Default destructor method */
myString::~myString() {
    delete[] arr;
}