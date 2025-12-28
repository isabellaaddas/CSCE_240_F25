#ifndef CSCE_240_MYSTRING_H
#define CSCE_240_MYSTRING_H


class myString {
public:
    myString();
    myString(int userSize, char userArr[]);
    int getSize();      // Extra helper function to retrieve private variable size
    void insert(int index, char value);
    void remove(int index);
    char get(int index);
    int find(char value);
    bool equals(myString userString);
    void clear();
    void print();
    ~myString();
private:
    char *arr;
    int size;
};


#endif //CSCE_240_MYSTRING_H