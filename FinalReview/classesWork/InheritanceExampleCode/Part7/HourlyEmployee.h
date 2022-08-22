#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H
#include <iostream>
#include <string>
#include <sstream>
#include "Employee.h"

class HourlyEmployee : public Employee {
public:
    HourlyEmployee();
    HourlyEmployee(const std::string&, const std::string&, double);
    HourlyEmployee& operator=(const HourlyEmployee&);
    std::string to_str() const;
    double get_hourly_wage() const {return hourly_wage;}
private:
    double hourly_wage;
};

std::ostream& operator<<(std::ostream&, const HourlyEmployee&);

#endif