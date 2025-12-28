// Created by HUSol on 10/18/2025.

#include <iostream>
#include "Array.h"

using namespace  std;

int main(int argc, char** argv) {
    int size1, size2, size3;
    double *ptrA;
    double *ptrB;
    double *ptrC;

    cout << "Please enter array size: ";
    cin >> size1;
    cout << endl;

    ptrA = new double[size1];
    init(ptrA, size1);
    print(ptrA, size1);

    cout << "Please enter array size: ";
    cin >> size2;
    cout << endl;

    ptrB = new double[size2];
    init(ptrB, size2);
    print(ptrB, size2);

    cout << "Please enter array size: ";
    cin >> size3;
    cout << endl;

    ptrC = new double[size3];
    init(ptrC, size3);
    print(ptrC, size3);

    cout << "The first and second array are equal: ";
    bool isTrue(equals(ptrA, size1, ptrB, size2));
    if (isTrue) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    cout << "The second and third array are equal: ";
    isTrue = equals(ptrB, size2, ptrC, size3);
    if (isTrue) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    remove(5, ptrA, size1);
    print(ptrA, size1);

    insert(4, 3.4, ptrA, size1);
    print(ptrA, size1);

    remove(4, ptrA, size1);
    print(ptrA, size1);

    cout << "Getting value at index 10: ";
    double value(get(10, ptrA, size1));
    cout << value << endl;

    cout << "Getting value at index 2: ";
    value = get(2, ptrA, size1);
    cout << value << endl;

    cout << "Finding index of 1: ";
    int index = find(1, ptrA, size1);
    cout << index << endl;

    cout << "Finding index of 8.2: ";
    index = find(8.2, ptrA, size1);
    cout << index << endl;
}
