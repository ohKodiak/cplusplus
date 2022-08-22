#include "functions.h"
using std::cin, std::cout, std::endl, std::ostream, std::string;

#define INFO(X)  cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;
#define INFO_STRUCT(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " count = " << X.count << endl;

/**
 * ----- REQUIRED -----
 * Pushes number to top of stack. If stack is full, then resize stack's array.
 * @param   stack   Target stack.
 * @param   number  Number to push to stack.
 */
void push(Stack& stack, int number) {
  // TODO: implement push function for stack
  INFO_STRUCT(stack);
  INFO(number);
  int capacity = stack.capacity;
  int size = stack.count;
  if (capacity == size)  { 
    int newcap = capacity * 2;
    int* resized_array = new int[newcap];
    for (int i = 0; i <= size; i++ ){
      resized_array[i] = stack.numbers[i];}
      delete[] stack.numbers;
      stack.numbers = resized_array;
      stack.capacity = newcap;
      stack.numbers[stack.count] = number;
      stack.count += 1;}
    else{
      stack.numbers[stack.count] = number;
      stack.count += 1;}
}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Value of popped number.
 */
int pop(Stack& stack) {
  // TODO: implement pop function for stack
  INFO_STRUCT(stack);
  int pop = 0;
  int size = stack.count; // size of array
  if (size == 0)  {
    return INT32_MAX;
  } 
  else{
    pop = stack.numbers[size - 1];
  }
  stack.count--;
  return pop;
}

/**
 * ----- OPTIONAL -----
 * Returns the number at top of stack without popping it. If stack is empty, return INT32_MAX.
 * @param   stack   Target statck.
 * @return          Number at top of stack.
 */
int peek(const Stack& stack) {
  // TODO (optional): implement peek function for stack
  INFO_STRUCT(stack);
  int size = stack.count;
  int peek = 0;
  if (size == 0)  {
    return INT32_MAX;
  }
  else {
    peek = stack.numbers[size -1];
  }
  return peek;
}
