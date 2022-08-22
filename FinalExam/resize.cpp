#include <iostream>

using std::cout, std::endl;

// TODO: Write this function
void removeDuplicates(int*& ary, unsigned int& size)    {
    int* newArray = new int[size+1]; //new array
    //Leave the duplicate with the lowest index in the array, and remove any subsequent duplicates.
    unsigned int holdIndex = INT32_MAX; //keep index of lowest duplicate
    int insertIndex = 0;
    bool same = false;
    int count = 0;
    for (unsigned int i = 0; i < size; i++) {
        count = 0;
        same = false;
        for (unsigned int j = 0; j < size; j++) {
            if (ary[i] == ary[j])   {
            count += 1;
            
            if (i < holdIndex)  {holdIndex = i;}}} //save smallest index
        if (count > 1)  {same = true;}
        if (same == false)  { //not a duplicate
        newArray[insertIndex] = ary[i]; //insert, keep track of new array index
        insertIndex += 1;}
    }
    newArray[insertIndex + 1] = ary[holdIndex];
    //you have a temporary array, now create the one you're going to return
    for (int i = 0; i < insertIndex; i++)   {
        ary[i] = newArray[i];
        }
    
    delete[] newArray;
    size = insertIndex + 1; //passed by reference
}

void printAry(const int* ary, unsigned int size) {
    cout << size << " elements:" << endl;
    for (unsigned int i=0; i<size; ++i) {
        cout << ary[i] << endl;
    }
}

int main() {
    unsigned int size = 8;
    int* ary = new int[size] {3, 5, 2, 3, 5, 7, 9, 3};
    printAry(ary, size);
    removeDuplicates(ary, size);
    printAry(ary, size);
    delete [] ary;
}