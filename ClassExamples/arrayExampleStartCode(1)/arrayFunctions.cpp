#include <iostream>
#include "arrayFunctions.h"

using std::cin, std::cout, std::endl;

using std::out_of_range;

// always throw an out_of_range exception for any invalid index

void loadRandom(int ary[], int size) {
  if (size > CAPACITY) {
    throw out_of_range("size is greater than capacity");
  }
  for (unsigned int i=0; i<size; ++i) {
    ary[i] = rand()%100 + 1; // values 1 through 100
  }
}

void add(int val, unsigned int index, 
          int ary[], unsigned int size) {
  
}

void removeAtIndex(unsigned int index, 
          int ary[], unsigned int size) {
  
}

void removeFirstOf(int val, 
          int ary[], unsigned int size) {
  
}

int getMax(int ary[], unsigned int size) {
  return 0;
}

int getMin(int ary[], unsigned int size) {
  return 0;
}

unsigned int countVal(int val, int ary[], unsigned int size) {
  return 0;
}

void print(int ary[], unsigned int size) {
  if (size == 0) {
    cout << "Empty array" << endl;
  }
  for (unsigned int i=0; i<size; ++i) {
    cout << ary[i] << endl;
  }  
}