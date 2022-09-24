// TODO: Implement this header file

#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <iostream>
#include <fstream>
#include <tuple>
#include <limits>
#include <stdexcept>
using namespace std;

class MyString  {
    private:
    size_t sizeAttribute;
    size_t capacityAttribute; //cant have same name as a function
    char* string; 

    public:
    MyString(); //default constructor, written not tested
    MyString(const MyString& str); //parameterized constructor, not done
    MyString(const char* s); //parameterized constructor, not done
    ~MyString(); //deletes memory assigns for an object, deletes memory for char array
    void resize(size_t n); //written, not tested
    size_t capacity() const; //done, could be moved here because less than a line
    size_t size() const; //done
    size_t length() const; //done
    const char* data() const noexcept; //written not tested
    bool empty() const noexcept; //done
    const char& front() const; //written, not tested
    const char& at(size_t pos) const; //written, not tested
    void clear() noexcept; //written, not tested
    MyString& operator= (const MyString& str); //not started
    MyString& operator+= (const MyString& str); //not started
    size_t find(const MyString& str, size_t pos = 0) const noexcept; //return -1 if not found, pos = 0 a default parameter already?
    //in progress
    //when is somepthing const and when it something not, const at end means its a constant member function, object cant be modified
    //how to do constructors and destructors 
    //why is << throwing error
};

ostream& operator<< (ostream& os, const MyString& str); //not started, gives errors

#endif