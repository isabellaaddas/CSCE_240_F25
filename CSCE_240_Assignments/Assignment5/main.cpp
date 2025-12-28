//

#include "myString.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    char dog[] = {'D', 'o', 'g'};
    char cat[] = {'C', 'a', 't'};

    myString s1 = myString(3, dog);
    myString s2 = myString(3, cat);
    myString s3 = myString(s2);

    cout << "My strings: ";
    s1.print();
    cout << ", ";
    s2.print();
    cout << ", ";
    s3.print();
    cout << endl;

    cout << "Are string 1 and 2 equal? ";
    if (s1 == s2) {
        cout << "Yes!" << endl;
    } else {
        cout << "No!" << endl;
    }

    cout << "Are string 2 and 3 unequal? ";
    if (s2 != s3) {
        cout << "Yes!" << endl;
    } else {
        cout << "No!" << endl;
    }

    myString s4;
    s4 = s1 + s2;

    cout << "My strings: ";
    s1.print();
    cout << ", ";
    s2.print();
    cout << ", ";
    s3.print();
    cout << ", ";
    s4.print();
    cout << endl;

    s4.remove(100);
    s4.remove(1);

    cout << "String 4: ";
    s4.print();
    cout << endl;

    cout << "Where is 'dog' in s4?: ";
    cout << s4.find(s1) << endl;

    cout << "Where is 'cat' in s4?: ";
    cout << s4.find(s2) << endl;

    s4.set(100, 'a');
    s4.set(1, 'b');

    cout << "String 4: ";
    s4.print();
    cout << endl;

    cout << "String 4, index 0: " << s4[0] << endl;
    cout << "String 4, index -5: " << s4[-5] << endl;

    cout << "Clearing s4..." << endl;
    s4.clear();
    cout << "Is s4 empty? ";
    if (s4.isEmpty()) {
        cout << "Yes!" << endl;
    } else {
        cout << "No!" << endl;
    }

    return 0;
}

using namespace std;