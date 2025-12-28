/*
 * Created by iaddas, 10/20
 */

#include "myObject.h"
#include <iostream>

using namespace std;

// This :: says the function belongs to this class (scope resolution
// operator
myObject::myObject() {
    size = 0;
    arr = nullptr;  // Best practice for setting pointer to nothing
}

myObject::myObject(int size, int initVal) {
    this->size = size;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = initVal;
    }
}

myObject::myObject(const myObject& other) {
    arr = new int[other.size];
    size = other.size;
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

ostream& operator<<(ostream& os, const myObject& obj) {
    for (int i = 0; i < obj.size; i++) {
        os << obj.arr[i] << " ";
    }
    os << endl;

    return os;
}

istream& operator>>(istream& is, myObject& obj) {
    for (int i = 0; i < obj.size; i++) {
        is >> obj.arr[i];
    }

    return is;
}

void myObject::copyArray(myObject& other) {
    delete[] arr;
    arr = new int[other.size];
    size = other.size;
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

int myObject::getSize() {
    return size;
}

void myObject::printArray() const {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void myObject::setElement(int index, int value) {
    if ((index < 0) || (index >= size)) {
        cout << "index out of bounds" << endl;
    } else {
        arr[index] = value;
    }
}

void myObject::operator=(const myObject& other) {
    if (this != &other) {
        delete[] this->arr;
        this->size = other.size;
        this->arr = new int[other.size];
        for (int i = 0; i < this->size; i++) {
            this->arr[i] = other.arr[i];
        }
    }
}

bool myObject::operator==(const myObject& other) const {
    bool isEqual = true;

    if (this->size != other.size) {
        isEqual = false;
    } else {
        for (int i = 0; i < size; i++) {
            if (arr[i] != other.arr[i]) {
                isEqual = false;
                break;
            }
        }
    }

    return isEqual;
}

const myObject myObject::operator+(const myObject &other) {
    if (size != other.size) {
        cout << "Arrays must be same size" << endl;
        return myObject();
    } else {
        myObject result(size, 0);

        for (int i = 0; i < size; i++) {
            result.arr[i] = arr[i] + other.arr[i];
        }

        return result;
    }
}

void myObject::append(const myObject &other) {
    if (this != &other) {
        //
    }
}

int myObject::operator[](int index) const {
    if ((index < 0) || (index >= size)) {
        return -1;
    }

    return arr[index];
}

int &myObject::operator[](int index) {
    if ((index >= 0) && (index < size)) {
        return arr[index];
    }

    throw out_of_range("index out of bounds");
}

const myObject myObject::operator++() {
    // Modify arr immediately and return the changed
    // object (this)
    for (int i = 0; i < size; i++) {
        arr[i]++;
    }

    return *this;
}

const myObject myObject::operator++(int dummy) {
    // Create temp copied object, modify arr, return
    // the copy that represents original state
    myObject temp(*this);
    for (int i = 0; i < size; i++) {
        arr[i]++;
    }

    return temp;
}

void myObject::setSize(int newSize) {
    if (size >= 0) {
        size = newSize;
    }
}


myObject::~myObject() {
    delete[] arr;
}

