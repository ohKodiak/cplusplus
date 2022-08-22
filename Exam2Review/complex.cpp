#include <iostream>
#include <string>
#include <array>
using namespace std;

class Gaussian  {
    public:
    void setA(int a);
    void setA()    {
        this->a = 0;};
    void setB(int b);
    void setB() {
        this-> b = 0;}
    int getA();
    int getB();
    void print();
    Gaussian operator+(int a)   {

    }
    private:
    int a;
    int b;
};

void Gaussian::setA(int a)    {
    this->a = a;}

void Gaussian::setB(int b)  {
    this-> b = b;}

int Gaussian::getA()    {
    return a;}

int Gaussian::getB()    {
    return b;}

void Gaussian::print()  {
    cout << a << " + " << b << "i" << endl;}




