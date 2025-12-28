/*
 * File: sept_17.cpp
 * Author: iaddas
 * Created 9/17/25
 */

#include <iostream>

using namespace std;

// Array Lecture
int main(int argc, char** argv) {
    int A1[10]; // One dimensional array
    // Better to declare a constant integer variable to hold the size
    // (follow the practice of not hard-coding values that may be changed)
    const int size(15);
    int A2[size];

    // Traverse indices 0-9
    for (int i = 0; i < 10; i++) {
        cin >> A1[i];;
    }

    for (int i = 0; i < size; i++) {
        cin >> A2[i];
    }

    // Prints memory address of array
    cout << A1 << endl;

    for (int i = 0; i < 10; i++) {
        cout << "A1[" << i << "] is at: " << &A1[i];
        cout << " and has a value of: " << A1[i] << endl;
    }

    // Following statements do not throw exception:
    // cout << A1[10] << " " << A1[15] << endl;
    // A1[10] = 500;

    /*
     * C++ Arrays:
     * - Only keep track of where array starts
     * - Saying array[index] advances to the (index+1)th element
     * - You can call to an index out of bounds for an array, and it will
     * come back with whatever is in that memory address despite not
     * being in the dedicated array
     * - Core dump results when accessing out of bounds array element
     * and attempting to write to that memory address *where some data already exists*
     * - Using negative index numbers works the same but goes backward from
     * array start
     * - Bug/security breach: using memory address that is not yours, then another
     * program uses that same memory address and writes over it so that it is
     * changed when your program tries to get it again later
     */

    // Stack refers a memory area that can hold primitive arrays that
    // are fixed size

    return 0;
}