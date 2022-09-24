// TODO: Implement this source file

#include "MyString.h"
#include <iostream>
#include <fstream>
#include <tuple>
#include <limits>
#include <stdexcept>
//c strings are null termintaed, meaning that the last value is '\0'
MyString::MyString(): sizeAttribute(0), capacityAttribute(1), string(new char[capacityAttribute])   {}
//could be this
//initialization list
MyString::MyString(const MyString& str):sizeAttribute(str.sizeAttribute), capacityAttribute(str.capacityAttribute), string(new char [str.sizeAttribute]) {
    //could be this
   // this->string = new char[this->capacityAttribute];
    for (size_t i = 0; i < str.size(); i++)  { //edit to bounds made at 12:48
        this->string[i] = str.at(i);}}
//could be this
MyString::MyString(const char* s): sizeAttribute(0), capacityAttribute(1), string(new char[capacityAttribute])  {
    unsigned int i = 0;
    unsigned int counter = 0;
    while (s[i] != '\0')    {
        counter += 1;
        i += 1;}
    i = 0;
    this->capacityAttribute = counter + 1;
    //unsigned int cap = this->capacityAttribute;
    this->sizeAttribute = counter;
    delete[] this->string;
    this->string = new char[this->capacityAttribute];
    while (i < counter)    { //changed from s[i] != '\0'
        this->string[i] = s[i];
        i += 1;}
}

MyString::~MyString()   {
    if (this->string != nullptr)  {
        delete[] this->string;
        this->string = nullptr;}
}

void MyString::resize(size_t n) {

if (n+1 > this->capacityAttribute)    {
   char* newString = new char [n+1]; 
    unsigned int i = 0;
    for (i = 0; i < sizeAttribute; i++) { //fix this
        newString[i] = this->string[i];
        } //copy over
    delete[] this->string;
    this->string = newString;
    this->capacityAttribute = n+1;

    } //increased capacity if needed to

if (n < this->sizeAttribute)  {   //updates size
    this->sizeAttribute = n;}

unsigned int i = 0;
for (i = this->sizeAttribute; i < capacityAttribute; i++) {
    string[i] = '\0';}

}

size_t MyString::capacity() const{
    return this->capacityAttribute;
}

size_t MyString::size() const{
    return this->sizeAttribute;
}

size_t MyString::length() const{
    return this->sizeAttribute;
}

const char* MyString::data() const noexcept{
/*Returns a pointer to an array that contains a null-terminated sequence of characters (i.e., a C-string) 
representing the current value of the string object.*/
//returns pointer to array, string is already a pointer
return this->string; //string is already a pointer?
}

bool MyString::empty()  const noexcept{
    if (this->sizeAttribute == 0) {
        return true;}
    return false;}

const char& MyString::front() const{
    if (this->sizeAttribute != 0)   {
            return this->string[0];} //need .at()?
    //throw something??
    throw std::out_of_range("yee");
}

const char& MyString::at(size_t pos) const{
    //takes in index as parameter 
    //check bounds first
    if (pos >= this->sizeAttribute)   {
        throw std::out_of_range("oh yeah1");}   
    return this->string[pos];  
}

void MyString::clear() noexcept { //could be this
    delete[] this->string;
    this->sizeAttribute = 0;
    this->capacityAttribute = 1; //should still be bigger than size
    this->string = new char[0];} //array[] = {}

size_t MyString::find(const MyString& str, size_t pos) const noexcept{
    unsigned int i = 0;
    bool check = true;
    for (i = pos; i < this->sizeAttribute; i++ )  {
        if (this->string[i] == str.at(0))    {
            for (unsigned int j = 0; j < str.length(); j++)  {
                if (this->string[i+j] != str.at(j))   {
                    check = false;
                    break;}}
            //should get out of of this loop if all are the same
        if (check)  {return i;}}
    }
    return -1;
}

MyString& MyString::operator=(const MyString& str){
    /*A string object, whose value is either copied (1) or moved (5) if different from *this 
    (if moved, str is left in an unspecified but valid state). */
    //*this is where you need to assign the array to
    //str is an array of characters
    //could i just do *this = str;
    delete[] this->string;
    char* newArray = new char[str.capacity()];
    for (unsigned int i = 0; i < str.size(); i++)  {
        newArray[i] = str.data()[i];} 
    string = newArray;
    this->capacityAttribute = str.capacity(); //changed from capacityAttribute
    this->sizeAttribute = str.size();
    return *this;
}

MyString& MyString::operator+=(const MyString& str)  { //could be this
//1. what is size? 2. check for '\0' 3. 
    //im assuming this adds one string to another, so you can use similar loop to last function
    unsigned int hold = this->sizeAttribute; //an offset 
    size_t holdsize = hold + str.size();
    this->resize(holdsize); //gives out output, avoid using if neccesary
    //this->capacityAttribute += str.capacity(); //changed from sizeattribute to capacity attribute at 11:28
    for (unsigned int i = 0; i < str.size(); i++)  {
        this->string[hold + i] = str.at(i);}
    this->sizeAttribute = holdsize;
    return *this; //does this function work???

}

ostream& operator<<(ostream& os, const MyString& str)  {
    for (unsigned int i = 0; i < str.size(); i++) {
        os << str.at(i); //load it
    }
    return os;}

//should i be using size instead of .sizeattribute???????
//index starts at 0, size starts at 1 thus you use <
//error means you're accessing out of range somewhere