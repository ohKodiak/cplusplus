#include <iostream>
#include <string>
#include <array>
using namespace std;



int seg(int sequence[], int size)   {
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (sequence[i] != sequence[i+1])   {
            counter += 1;}
    }
    return counter;
}
int main()  {
const int sized = 11;
int segment[11] = {5,2,2,3,4,4,4,4,1,1,1};

cout << seg(segment,sized) << endl;


}


