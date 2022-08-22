#include <iostream>
#include <cmath>
using namespace std;


bool isNumericPalindrome(int num)   {

    int numstorage = num;
    int numcheck = 0;
    int counter = 0;
    int i = 0;
    int tensplace = 0;
    int peeled = 0;
    while (numstorage != 0)    {
        peeled = numstorage % 10;
        numstorage /= 10;
        counter += 1;}

    numstorage = num;
    counter -= 1;
    while (num != 0)    {
        peeled = num % 10;
        num /= 10;
        tensplace = pow(10,counter-i);
        peeled *= tensplace;
        numcheck += peeled;
        i += 1;}
    if (numcheck == numstorage)  {return true;}
    return false;
}

int main()  {
cout << isNumericPalindrome(121) << endl;
}