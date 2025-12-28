//
// Created by HUSol on 10/27/2025.
//

#include "myString.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    char dog[] = {'D', 'o', 'g'};
    char cat[] = {'C', 'a', 't'};

    myString dogStr = myString(3, dog);
    myString catStr = myString(3, dog);

    dogStr.print();
    cout << " and ";
    catStr.print();
    cout << endl;

    if (dogStr.equals(catStr)) {
        cout << "Strings are the same." << endl;
    } else {
        cout << "Strings are different." << endl;
    }

    dogStr.print();
    cout << " has length " << dogStr.getSize() << endl;
    catStr.print();
    cout << " has length " << catStr.getSize() << endl;

    dogStr.insert(3, 's');
    catStr.insert(3, 's');

    dogStr.print();
    cout << " has length " << dogStr.getSize() << endl;
    catStr.print();
    cout << " has length " << catStr.getSize() << endl;

    dogStr.print();
    cout << " and ";
    catStr.print();
    cout << endl;

    dogStr.remove(3);
    catStr.remove(3);

    dogStr.print();
    cout << " has length " << dogStr.getSize() << endl;
    catStr.print();
    cout << " has length " << catStr.getSize() << endl;

    dogStr.print();
    cout << " and ";
    catStr.print();
    cout << endl;

    char value(' ');
    value = dogStr.get(0);
    cout << "Index 0 in Dog returns: " << value << endl;
    value = dogStr.get(100);
    cout << "Index 100 in Dog returns: " << value << endl;

    int index(0);
    index = dogStr.find('o');
    cout << "Finding 'o' in Dog returns: " << index << endl;
    index = dogStr.find('q');
    cout << "Finding 'q' in Dog returns: " << index << endl;

    catStr.clear();

    dogStr.print();
    cout << " and ";
    catStr.print();
    cout << endl;

    return 0;
}
