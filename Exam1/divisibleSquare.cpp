#include <iostream>
#include <stdexcept>

using std::cout, std::endl;

int squaredDivisibleDigits(int number, unsigned int divisor) {

    //catch exceptions first
    if ((number != 0) && (number > INT32_MAX / number)) { // checks for overflow 
      throw std::invalid_argument("Overflow error");}
    if (divisor == 0) { 
      throw std::invalid_argument("Division by zero");} // if divisor is zero

    //initialize variables
    int product = 0;
    int digit = 0;
    //int storeproduct = 0;
    int counter = 0;

    product = number * number;//get product
    if (product == 0)   {return 1;} //must account for this here because 0 wont go into my while loop
    //storeproduct = product;//store product before i peel in case i need it later

    while (product != 0)    { //peel product to check each digit 
        digit = product % 10; //peels
        product /= 10; //moves to product to next digit
        if (digit % divisor == 0)   {  //find if divisible by divisor and add to counted list
            counter += 1;} 
    }

    return counter; // modify to return correct value
}

int main() {
    //cout << squaredDivisibleDigits(123456789, 1) << endl;
    cout << squaredDivisibleDigits(10, 4) << endl;

}