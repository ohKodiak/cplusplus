#include <iostream>
#include <string>
using namespace std;

//A positive integer number n is triproduct if it can be obtained by the product of three 
///consecutive positive integers. For example, 120 is triproduct, since 4 * 5 * 6 = 120. 
///Given n > 0, determine if n is triproduct.
int main()  {

int triproduct = 0;
cin >> triproduct;
int product = 0;
int i = 0;

while (product < triproduct)    {
    product = 0;
    product = i * (i + 1) * (i + 2);
    if (product == triproduct)  {
        cout << triproduct << " is a triproduct" << endl;
        break;
    }
    i += 1;
}}

