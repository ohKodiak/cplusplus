#include <iostream>
#include <string>
using namespace std;

//Given positive integers n, k and l, print the first n positive integer 
//numbers that are multiple of k, l or both. Example: n = 6, k = 2 and l = 3, you should print:
//2 3 4 6 8 9
int main()  {
    int n = 0;
    int k = 0;
    int l = 0;
    unsigned long i = 0;
    int counter = 0;
    cin >> n;
    cin >> k;
    cin >> l;

    while (counter <= n)   {
        if ((i % k == 0) || (i % l == 0))   {
            cout << i << " ";
            counter += 1;}
        i += 1;}
}