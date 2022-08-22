#include <iostream>
#include <sstream>
#include <fstream>
using std::cin, std::cout, std::endl, std::string, std::getline,
      std::ifstream, std::istringstream;

int main() {
  string filename;
  cout << "Enter donation filename: ";
  cin >> filename;
  ifstream ifs(filename);
  if (!ifs.is_open()) {
    cout << "Failed to open file " << filename << "." << endl;
    return 1;
  }
  
  double maxTotalDonation = 0;
  int maxTotalCollector = 0;
  
  // read data
  string response;
  int identification;
  string donation;
  string oldDonation;
  int counter = 0;
  bool idCheck = true;
  int numDonations = 0;
  double currentDonation = 0;
  int highestNumDonations = 0;
  double highestDonation = 0;
  int highestDonator;

  while(getline(ifs,response)){
    istringstream name(response);
    name >> identification;
    if(name.tellg() == -1){
      break;
    }
    else {
      name >> highestDonation;
      numDonations += 1;
    }
    while(name.tellg() != -1){
      cout << "Works" << endl;
      name >> currentDonation;
      if(currentDonation > highestDonation){
        highestDonation = currentDonation;
      }
      numDonations += 1;
    }
    if(numDonations > highestNumDonations){
      highestNumDonations = numDonations;
      highestDonator = identification;
    }
    numDonations = 0;
  }
  maxTotalDonation = highestNumDonations;
  maxTotalCollector = highestDonator;

  if(highestDonation == 0){
    cout << "No donations." << endl;
  } else {
  cout << "Highest donation total: " << maxTotalDonation << endl;
  cout << "-- collected by id: " << maxTotalCollector << endl;
  }
}