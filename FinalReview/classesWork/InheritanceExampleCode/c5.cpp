#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Employee {
    std::string first_name, last_name;
};

struct HourlyEmployee : public Employee {
    double hourly_wage;
};

struct SalariedEmployee : public Employee {
    double annual_salary;
};

int main (int argc, char * argv[])
{

    HourlyEmployee he;
    he.first_name = "James"; he.last_name = "Williams"; he.hourly_wage = 18.50;
    cout << he.first_name << ' ' << he.last_name << '\t' << he.hourly_wage << endl;
    SalariedEmployee sh;
    sh.first_name = "Mary"; sh.last_name = "Smith"; sh.annual_salary = 134000;
    cout << sh.first_name << ' ' << sh.last_name << '\t' << sh.annual_salary << endl;

    cout << endl;

    vector<Employee*> ptrs_to_emps;
    HourlyEmployee* he_ptr = &he;
    ptrs_to_emps.push_back(he_ptr);
    ptrs_to_emps.push_back(&sh);
    cout << "vector<Employee*>" << endl;
    for (auto e : ptrs_to_emps)
        cout << '\t' << e->first_name << ' ' << e->last_name << endl;

    cout << endl;

    cout << "Looking at Employee James Williams as on vector<Employee*> as HourlyEmployee:" << endl;
    HourlyEmployee* he_ptr_2 = static_cast<HourlyEmployee*>(ptrs_to_emps.at(0));
    cout << he_ptr_2->first_name << ' ' << he_ptr_2->last_name << '\t' << he_ptr_2->hourly_wage << endl;

    cout << endl;

    vector<Employee> emps;
    emps.push_back(he);
    emps.push_back(sh);
    HourlyEmployee he2;
    he2.first_name = "Jacob"; he2.last_name = "Johnson"; he2.hourly_wage = 21.00;
    emps.push_back(he2);
    cout << "vector<Employee>" << endl;
    for (auto e : emps)
        cout << '\t' << e.first_name << ' ' << e.last_name << endl;

    cout << endl;

    cout << "Looking at Employee James Williams as on vector<Employee> as HourlyEmployee:" << endl;
    cout << (*(static_cast<HourlyEmployee*>(&emps.at(0)))).first_name << ' ' << (*(static_cast<HourlyEmployee*>(&emps.at(0)))).last_name << '\t' << (*(static_cast<HourlyEmployee*>(&emps.at(0)))).hourly_wage << endl;

    return 0;

}