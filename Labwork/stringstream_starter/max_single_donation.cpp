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
  int numDonations = 0;
  double currentDonation = 0;
  int highestNumDonations = 0;
  double highestDonation = 0;
  int highestDonator;
  double highestSingleDonation = 0;
  double highestDonationTotal = 0;
  int donatorHighestTotal = 0;
  double totalDonation = 0;


  while(getline(ifs,response)){
    istringstream name(response);
    name >> identification;
    if(name.tellg() == -1){
      break;
    }
    else {
      name >> highestDonation;
      totalDonation += highestDonation;
    }
    while(name.tellg() != -1){
      name >> currentDonation;
      if(currentDonation > highestDonation){
        highestDonation = currentDonation;
      }
      totalDonation += currentDonation;
    }
    if(highestSingleDonation < highestDonation){
      highestSingleDonation = highestDonation;
      highestDonator = identification;
    }
    if(totalDonation > highestDonationTotal){
      highestDonationTotal = totalDonation;
      donatorHighestTotal = identification;
    }
    totalDonation = 0;
  }
  maxTotalDonation = highestDonationTotal;
  maxTotalCollector = highestDonator;

  if(highestDonation == 0){
    cout << "No donations." << endl;
  } else {
  cout << "Highest donation total: " << maxTotalDonation << endl;
  cout << "-- collected by id: " << maxTotalCollector << endl;
  cout << "Highest single donation: " << highestSingleDonation << endl;
  cout << "-- collected by id: " << maxTotalCollector << endl;
  }
}