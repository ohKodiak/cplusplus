#include <string>
#include "Node.h"

using namespace std;

// Default constructor
Node::Node(): data(TemperatureData()), next(nullptr) {} // remember to initialize next to nullptr
//TemperatureData gives default values based on Temperature Data constructor
// Parameterized constructor
Node::Node(string id, int year, int month, double temperature): data(id,year,month,temperature), next(nullptr) {}
// remember to initialize next to nullptr

bool Node::operator<(const Node& b) {
	return this->data < b.data;
}
