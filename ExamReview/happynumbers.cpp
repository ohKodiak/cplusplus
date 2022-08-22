#include <iostream>
#include <string>
#include <array>
#include <cmath>
using namespace std;


bool happy(int number)  {
int numstorage = number;
int peel = 0;
int sum = 0;
while (sum != 4)  {
    while ( numstorage != 0) {
        peel = numstorage % 10;
        //cout << peel << endl;
        numstorage /= 10;
        sum += pow(peel,2);
        //cout << sum << endl;
        }
        if (sum == 1)  {numstorage = sum;
            return true;}
        if (sum == 4)  {numstorage = sum;
            return false;}
        numstorage = sum;
        sum = 0;}}


int main()  {
cout << happy(28) << endl;
cout << happy(48) << endl;
cout << happy(16) << endl;
cout << happy(4) << endl;
cout << happy(1) << endl;
}