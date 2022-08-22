#include "HourlyEmployee.h"

std::ostream& operator<<(std::ostream& os, const HourlyEmployee& hourlyEmployee)
{
    hourlyEmployee.log("std::ostream& operator<<(std::ostream&, const HourlyEmployee&)");
    //os << static_cast<Employee>(hourlyEmployee) << '\t' << hourlyEmployee.get_hourly_wage();
    os << hourlyEmployee.get_first_name() << ' ' << hourlyEmployee.get_last_name() << '\t' << hourlyEmployee.get_hourly_wage();
    return os;
}