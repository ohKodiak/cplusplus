#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
#include "HourlyEmployee.h"
using namespace std;

int main (int argc, char * argv[])
{
    HourlyEmployee h1("Jill", "Williamson", 20.0);
    HourlyEmployee h2;
    h2 = h1;
    cout << h1 << endl;
    cout << h2 << endl;
    cout << h2.to_str() << endl;

    return 0;
}