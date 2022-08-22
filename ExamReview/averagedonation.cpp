#include <iostream>
#include <string>
#include <array>
using namespace std;

void bestDonor(int kellyDonations[], int numKellyDonations, int sarahDonations[], int numSarahDonations)    {
    double kellyave = 0.0;
    double kellytotal = 0.0;
    double sarahave = 0.0;
    double sarahtotal = 0.0;
    int i = 0;
    int j = 0;
    for (i = 0; i < numKellyDonations; i++)   {
        if (kellyDonations[i] < -1) {break;}
        kellytotal += kellyDonations[i];
    }
    for (j = 0; j < numSarahDonations; j++)   {
        if (sarahDonations[j] < -1) {break;}
        sarahtotal += sarahDonations[j];
    }

    kellyave = kellytotal / numKellyDonations;
    sarahave = sarahtotal / numSarahDonations;
    if (kellytotal < 300 ) {kellyave = 0;}
    if (sarahtotal < 300 ) {sarahave = 0;}
    if (numKellyDonations < 5)  {kellyave = 0;}
    if (numSarahDonations < 5)  {sarahave = 0;}
    if (kellyave > sarahave)    {
        cout << "kelly: " << kellyave << endl;}
    if (kellyave < sarahave)    {
        cout << "sarah: " << sarahave << endl;}
    if (kellyave == sarahave)    {
        cout << "no" << endl;
    }

}
int main()  {
    int kellyDonations[] = {100,100,100,300,300,-2};
    int numKellyDonations = 5;
    int sarahDonations[] = {100,100,101,300,300,-3};
    int numSarahDonations = 5;

    bestDonor(kellyDonations, numKellyDonations, sarahDonations, numSarahDonations);
}