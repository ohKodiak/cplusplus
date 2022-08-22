#include <iostream>
#include <string>
#include <array>
using namespace std;


void sum(const int size, int sequence[], int k)   {
    int i = 0;
    int j = 0;
    //cout << k << endl;
    for ( i = 0; i < size; i++) {
        for (j = 0; j < size; j++)  {
        if (sequence[i] + sequence[j] == k && (sequence[i] != sequence[j]) && (sequence[i] > sequence[j])) {
            cout << sequence[i] << "  " << sequence[j] << endl;}}}}
int main()  {
    int array1[8] = {1,2,3,4,5,6,7,8};
    sum(8,array1,8);
    cout << endl;
}

//how to make sure that they are distinct????