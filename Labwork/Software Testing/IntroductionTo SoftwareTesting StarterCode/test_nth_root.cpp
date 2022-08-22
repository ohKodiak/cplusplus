#include <iostream>
#include <cmath>
#include "nth_root.h"

int main() {
    {   // MINIMUM REQUIREMENT (for this lab)
        // just call the function with various values of n and x
        nth_root(2,1);
        try {
            nth_root(0,1);

        } catch (std::domain_error) {
            std::cout << "A." << std::endl;
        }

        try {
            nth_root(8,-1);

        } catch (std::domain_error) {
            std::cout << "B." << std::endl;
        }

        try {
            nth_root(-1,0);

        } catch (std::domain_error) {
            std::cout << "C" << std::endl;
        }

        //'std::domain_error'
        //nth_root(0,1); //a
        //nth_root(8,-1); //b
        //nth_root(-1,0); //c
        //nth_root(1,1); //d
        nth_root(-1,1); //e f
        nth_root(-6,1); //g
        nth_root(-4,1); // h
        nth_root(6,1); //i
        nth_root(4,1); //j
        nth_root(1,0); // k
        nth_root(3,1); // l
        nth_root(7,-2); // m
        nth_root(1,5); // n
        nth_root(1,(3/4.0)); //o
    }

    {   // TRY HARD
        // report the value
        double actual = nth_root(2, 1);
        std::cout << "nth_root(2, 1) = " << actual << std::endl;
    }

    {   // TRY HARDER
        // compare the actual value to the expected value
        double actual = nth_root(2, 1);
        double expected = 1;
        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=2, x=1)" << std::endl;
            std::cout << "  expected nth_root(2, 1) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }
    }
}
