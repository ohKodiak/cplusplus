#include <stdexcept> 
using namespace std;


int Largest(int a, int b, int c) {
  int d;
 // if (a > d) {
  d = a;
  if (b > d) {
    d = b;
  } if (c > d) {
    d = c;
  }
  return d;
}

bool SumIsEven(int a, int b) {
  if ( (a+b) % 2 == 0 ) {
    return true;}
  else{
    return false;
  }
}

int BoxesNeeded(int apples) {
  int num;
  if (apples <= 0)   {
    return 0;
  } else  {
    double remainder = apples % 20;
    if (remainder == 0) {
      num = apples/20;
    } else  {
        num = 1 + (apples/20);
    }

  }
  return num;

}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
  if (A_total == 0){  
    throw std::invalid_argument("Invalid Argument"); }
  if (B_total == 0){  
    throw std::invalid_argument("Invalid Argument"); }
  if (A_total < A_correct){  
    throw std::invalid_argument("Invalid Argument"); }
  if (B_total < B_correct){  
    throw std::invalid_argument("Invalid Argument"); }
  if (A_total < 0 || A_correct < 0 || B_correct < 0 || B_total < 0 ){  
    throw std::invalid_argument("Invalid Argument"); }
  double A_correct1 = A_correct;
  double B_correct1 = B_correct;
  double A_total1 = A_total;
  double B_total1 = B_total;
  double Acorrect; double Bcorrect;
  Acorrect = A_correct1 / A_total1;
  Bcorrect = B_correct1 / B_total1;
  if (Acorrect > Bcorrect)  {
    return true;
  }
  else  {
    return false;
  }
}


bool GoodDinner(int pizzas, bool is_weekend) {
  if (is_weekend) {
      if (pizzas >= 10)  {
        return true;
      } else{
        return false;
      }
  } else{
      if (pizzas >= 10 && pizzas <= 20)  {
        return true;
      } else{
        return false;      
  }}}



/*
  if (high <= low){  
    throw std::invalid_argument("Invalid Argument"); }
  int value = 0;
  int counter = low;
  while (counter <= high) {
    if (counter < 0)  {
      if (abs(counter) <= high)  {
        counter += 1;
        continue;
        }
      }
    if (counter > 0)  {
      if ((0-counter) >= low)  {
        counter += 1;
        continue;
        }
      }    
    if ((counter > 0) && (value > INT32_MAX - counter)) {
      throw std::overflow_error("Overflow error");}
    if ((counter < 0) && (value < INT32_MIN - counter)) {
      throw std::overflow_error("Overflow error");} 

    value += counter;
    counter += 1;
    }*/
 /* 
  for (int n = low; n <= high; n++) {
    if ((n < 0) && (abs(n) <= high))  {

        continue;
      }
    else if ((n > 0) && ((0-n) >= low))  {
        continue;
      }  
    if ((n > 0) && (value > INT32_MAX - n)) {
      throw std::overflow_error("Overflow error");}
    if ((n < 0) && (value < INT32_MIN - n)) {
      throw std::overflow_error("Overflow error");} 

    value += n;
    }
    */
int SumBetween(int low, int high) {
  if (high <= low){  
    throw std::invalid_argument("Invalid Argument"); }
  if (high + low == 0)  {
    return 0;
  }
  int value = 0;
  int counter = low;
  while (counter <= high) {
    if (counter == INT32_MIN) {
      if (high == 2147483647) {
        value = INT32_MIN;
        break;
      } else{
      value += counter;
      counter += 1;
      continue;}
    }
    if (counter < 0)  {    
      if (abs(counter) <= high)  {
        //cout << "check3" << endl;
        counter +=1;
        continue;
        }
      }
    if (counter > 0)  {
      if ((0-counter) >= low)  {
        counter += 1;
        continue;
        }
      }    
    if ((counter > 0) && (value > INT32_MAX - counter)) {
      throw std::overflow_error("Overflow error");}
    if ((counter < 0) && (value < INT32_MIN - counter)) {
      throw std::overflow_error("Overflow error");} 

    value += counter;
    counter += 1;
    }

  
  return value;}


int Product(int a, int b) {

  if ((a == -1) && (b == INT32_MIN))  { // becomes overflow
      throw std::overflow_error("Overflow error");} 


  if ((b == -1) && (a == INT32_MIN))  { //becomes overflow
      throw std::overflow_error("Overflow error");}


  if (b < 0 && a > 0)  {
    if ((b != 0) && (a > INT32_MIN / b))  { //underflow when a is negative
      throw std::overflow_error("Overflow error");}}


  if (a < 0 && b > 0)  {
    if ((a != 0) && (b > INT32_MIN / a))  { //underflow when a is negative
      throw std::overflow_error("Overflow error");}}


  if ((a < 0) && (b < 0)) {
    if ((b != 0) && (a < INT32_MAX / b)) { // overflow when both negative
      throw std::overflow_error("Overflow error");}}


  if ((a > 0) && (b > 0)) {
    if ((b != 0) && (a > INT32_MAX / b))  { //overflow when both positive
      throw std::overflow_error("Overflow error");}}


/*
  if ((a == -1) && (b == INT32_MIN))  {
     throw std::overflow_error("Overflow error");  // becomes overflow
  }
  if ((b == -1) && (a == INT32_MIN))  { //becomes overflow
     throw std::overflow_error("Overflow error");
  }
  if ((b != 0) && (abs(a) > INT32_MAX / abs(b))) { // overflow 
      throw std::overflow_error("Overflow error");
  }
  if ((b != 0) && (abs(a) < INT32_MIN / abs(b)) ) { //underflow
      throw std::overflow_error("Overflow error");
  }
*/
  int product = a * b;
  return product;
}