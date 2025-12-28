// Pre-processing code defining a variable of this object - good practice
// Reduces memory
#ifndef CSCE_240_MYOBJECT_H
#define CSCE_240_MYOBJECT_H

#include <iostream>
using namespace std;

/* Overloaded operator rules
 * 1. Can only overload existing operators
 * 2. Cannot overload certain operators (., .*, ::, sizeof, typeid, ?:,(name)_cast, decltype)
 * 3. Precedence cannot be changed
 * 4. Number of parameters cannot be changed
 */
// Public is for everyone, private is only for variables of type object

/* Friend qualifiers - allow qualified objects to have access to private members
 *
 * - myObject& called by reference b/c faster and const so it doesn't change
 * (can only be call-by-value if obj has copy constructor)
 * - ostream& called by reference b/c
 * - return type ostream& so it can be cascade-enabled
 *
 * - input stream works the same way, however myObject& is not const b/c
 * the array is being modified
 */
class myObject {
    // << and >> require 2 objects
    friend ostream& operator<<(ostream& os, const myObject& obj);
    friend istream& operator>>(istream& is, myObject& obj);
public:
    // Member functions and data
    myObject();     // Constructor (default); can be overloaded (alternates)
    ~myObject();    // Destructor (default)
    myObject(int size, int initVal);
    void copyArray(myObject& other);    // Must do this so that the other object
                                        // is passed by reference and does not
                                        // create another object ("other") that is
                                        // limited to function scope and destructs
                                        // when function escapes

    myObject(const myObject& other);    // Copy constructor that works to safely copy an
                                        // existing myObject object to a new one
                                        // (**BY DEEP COPY WITHIN FUNCTION DEFINITION**)
    int getSize();
    void printArray() const;
    void setElement(int index, int value);
    void operator=(const myObject& other);
    bool operator==(const myObject& other) const;   // "const" makes sure nothing on the left
                                                    // side of the operation is changed
                                                    // (the calling object)
    // Cascade: chaining functions so results are used in the next operation
    const myObject operator+(const myObject& other);
    void append(const myObject& other);
    int operator[](int index) const;
    int &operator[](int index);
    const myObject operator++();            // Pre-increment operator ++arr1
    const myObject operator++(int dummy);   // Post-increment operator arr1++
private:
    int size;
    int* arr;
    void setSize(int newSize);
};


#endif //CSCE_240_MYOBJECT_H