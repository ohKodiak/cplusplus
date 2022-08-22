#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Employee {
    std::string first_name, last_name;
};

struct HourlyEmployee {
    Employee emp;
    double hourly_wage;
};

struct SalariedEmployee {
    Employee emp;
    double annual_salary;
};

int main (int argc, char * argv[])
{

    HourlyEmployee he {{"James", "Williams"}, 18.50};
    cout << "HourlyEmployee" << endl;
    cout << '\t' << he.emp.first_name << ' ' << he.emp.last_name << '\t' << he.hourly_wage << endl;

    SalariedEmployee sh {{"Mary", "Smith"}, 134000};
    cout << "SalariedEmployee" << endl;
    cout << '\t' << sh.emp.first_name << ' ' << sh.emp.last_name << '\t' << sh.annual_salary << endl;

    return 0;

}