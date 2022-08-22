#include <iostream>
#include <string>
#include <array>
using namespace std;
#include <iostream>
#include <string>


int main()  {
    int balls = 334;
    try
    {
        if (balls < 500)    {throw invalid_argument("in my face");}
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
//catch (const invalid_argument & ia) {cerr << "Invalid File: " << ia.what() << endl;}

}