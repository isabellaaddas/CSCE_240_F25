/*
 * File: sept_3.cpp
 * Author: iaddas
 *
 * Created on September 3, 2025
 */

#include <iostream>

using namespace std;

/* never use global variables, int x(5); unless a constant */

// Function prototype: return type, name, arguments
int myPow(int base, int exp); // Creates a "heads up" that a function exists

// Overloading: can have the same names and types, but different #/types of arguments
// If you instantiate a parameter with a value, a call can be made with a missing
// argument using this "default argument" to fill it in
// However, you cannot use return type for overloading (same name and arguments,
// diff return type)

// Avoid auto-casting an int to a float

int main(int argc, char** argv) {
    int b(1), e(0);
    int product(1);

    cout << "Enter b ^ e:";
    cin >> b >> e;
    cout << b << " " << e << endl;

    int i;
    // & refers to memory address
    cout << &b << " " << &e << " " << &product << endl;
    // Call-by-value: value is copied to memory location of parameters
    product = myPow(b, e);  // Function call (invoke)

    cout << b << "^" << e << "=" << product << endl;

    return 0;
}

// Function description here
int myPow(int base, int exp) {
    // All memory used here expires once function ends, returning
    // only product
    int product(1);
    cout << &base << " " << &exp << " " << &product << endl;
    for (int i=0; i < exp; i++) {
        product *= base;
    }

    return product;
}