/*
 *File: august_27.cpp
 *Author: iaddas
 *
 *Created August 27, 2025
 */

/*
 *0 --> 0000 -> F
 *1 --> 0001 -> T
 *-1 -> 1110 -> T
 *
 *& is a bitwise operator, forces to look at both statements to evaluate
 *&& is the more common operator, simply looks at the value of the first statement,
 *then the second statement
 */

#include <iostream>

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

    int anInt1(0);
    int anInt2(5);

    cout << "Enter two integers: ";
    cin >> anInt1 >> anInt2;

    cout << anInt1 << " " << &anInt1 << endl;
    cout << "You entered: " << anInt1 << " and " << anInt2 << endl;
    if (anInt1 > anInt2) {
        cout << anInt1 << " > " << anInt2 << endl;
    }
    else {
        cout << anInt2 << " > " << anInt1 << endl;
    }

   return 0;
} 
