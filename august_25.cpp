/*
 *File: august_25.cpp
 *Author: iaddas
 *
 *Created on August 25, 2025
 */

#include <iostream>
#include <wchar.h>

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

    int x(0);
    float y(0);
    double z(0);
    char j('c');

    // To run command g++ august_25.cpp -o august_25 (compiles it)
    // Then do ./august_25 to print out commands

    cout << "size of int is: " << sizeof(x) << endl;
    cout << "x sits at: " << &x << endl;
    cout << "Hello world!" << endl;
    cout << endl;
    cout << "My name is Ezra" << endl;
    return 0;
}