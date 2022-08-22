#include <iostream>
#include <string>
#include <array>
using namespace std;



int* get_even_numbers(int* A, unsigned int n, unsigned int& m) {
    //A is array
    //n is dimensions of array
    //m is size of created array

    m = 0; //could be used as even count 
    int size = 2;
    int* newArray = new int [size];
    unsigned int i = 0;
    int evenCount = 0; //same as m

    for (i = 0; i < n; i++) { //row
        if (evenCount + 1 == size)  { //resizes array
            int newsize = size * 2;
            int* newnewArray = new int [newsize];
            for (int i = 0; i < size; i++)  { //copies everything
                newnewArray[i] = newArray[i];}
            delete[] newArray;
            newArray = newnewArray;
            size = newsize;}


        if (A[i] % 2 == 0)  {
            newArray[evenCount] = A[i];
            m += 1;
            evenCount += 1;}}
        
        return newArray;}
int main()  {

}