//
// Created by HUSol on 11/3/2025.
//

#include "myObject.h"
#include <iostream>

using namespace std;

// cout is part of output stream, cin is part of input stream, both in iostream
// so stream.operator<<(arr1) when cout << arr1

int main(int argc, char** argv) {
    myObject arr1 = myObject();
    myObject arr2 = myObject(5, 1);
    myObject arr3 = myObject(5, 10);

    /* When doing arr1 = arr2, it performs a shallow copy of all
     * data members from arr2 to arr1 data members and thus destruction
     * upon program exit will cause an error of double de-allocation of
     * the same space.
     */

    cout << "Array 1: ";
    arr1.printArray();
    cout << "Array 2: ";
    arr2.printArray();
    cout << "Array 3: ";
    arr3.printArray();

    arr1 = arr2 + arr3;

    cout << "Array 1: ";
    arr1.printArray();
    cout << "Array 2: ";
    arr2.printArray();
    cout << "Array 3: ";
    arr3.printArray();

    cout << arr1[0] << endl;
    arr1[0] = 2;
    cout << arr1[0] << endl;

    return 0;
}