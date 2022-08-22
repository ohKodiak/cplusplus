#include <iostream>
#include <string>
#include <array>
using namespace std;

int* get_array_ordered_by_frequency (int *a, unsigned int size_a, unsigned int& new_array_size)    {
    //a is array of integers
    //size a is the number of elements in a
    //new size is number of elements in new array being created
    int i = 0;
    int j = 0;
    new_array_size = 1;
    int added = 0;
    int same = 0;
    int index = 0;
    int holdcount;
    int holdnum;
    bool duplicate = false;
  
    //need array for same sizes and out array
    //array
    int* outArray = new int [new_array_size];
    int* holdcount = new int [size_a];
    for (i = 0; i < size_a; i++)    { //iterate through A
       
        if (added + 1 == new_array_size) { //checks need for resize, works good
            int newsize = new_array_size + 1;
            int* newnewArray = new int [newsize];
            for (int i = 0; i < new_array_size; i++)  { //copies everything
                newnewArray[i] = outArray[i];}
            delete[] outArray;
            outArray = newnewArray;
            new_array_size = newsize;}
 
        //out array 
        //have new size, wrong bound
        for (int k = 0; k < new_array_size; k++)    {
            if (a[i] == outArray[k]) {duplicate = true;}
        if (duplicate)   {continue;}
        }
        for (j = 0; j < size_a; j++)    { //iterate through outArray, a array index against outArray elements
            if (a[i] == a[j])   {
                same += 1; }   
            }
        //remove that number from a[i]
        
        if (same == 0)  {
            added += 1;}
        

}}

int main()  {
    int array[5] = {2,3,3,-3,5};
    int size = 5;
    unsigned int new_array_size = 0;
    int* balls = get_array_ordered_by_frequency(array, size,new_array_size);
    for (int i = 0; i < new_array_size; i++)  {
        cout << balls[i] << endl;}
}