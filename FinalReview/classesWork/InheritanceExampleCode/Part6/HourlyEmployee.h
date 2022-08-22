#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H
#include <iostream>
#include <string>
#include "Employee.h"

class HourlyEmployee : public Employee {
public:
    double get_hourly_wage() const {return hourly_wage;}
private:
    double hourly_wage;
};

std::ostream& operator<<(std::ostream&, const HourlyEmployee&);

#endif