#ifndef CSCE_240_MYSTRING_H
#define CSCE_240_MYSTRING_H


class myString {
public:
    myString();
    myString(int userSize, char userArr[]);
    myString(const myString& other);
    void remove(int index);
    int find(myString value) const;
    void set(int index, char value);
    bool isEmpty() const;
    void clear();
    void print();
    char operator[](int index);
    bool operator==(const myString& other) const;
    bool operator!=(const myString& other) const;
    const myString operator+(const myString& other) const;
    myString& operator=(const myString& other);
    ~myString();
private:
    char *arr;
    int size;
    myString(int newSize, char value);
};


#endif //CSCE_240_MYSTRING_H