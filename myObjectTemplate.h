#ifndef CSCE_240_MYOBJECTTEMPLATE_H
#define CSCE_240_MYOBJECTTEMPLATE_H

// Class 12/1
#import <iostream>

using namespace std;

template <class T>
class myObjectTemplate {
    template <class U>
    friend ostream & operator<<(ostream &os, const myObjectTemplate<U> &obj);
    template <class U>
    friend istream & operator>>(istream &is, myObjectTemplate<U> &obj);

public:
    myObjectTemplate();
    myObjectTemplate(const myObjectTemplate<T> &obj);

private:

};


#endif //CSCE_240_MYOBJECTTEMPLATE_H