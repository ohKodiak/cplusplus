#include <iostream>
#include <string>
using namespace std;

class Business {
   public:
      void SetName(string busName) {
         name = busName;
      }

      void SetAddress(string busAddress) {
         address = busAddress;
      }

      string GetDescription() const {
         return name + " -- " + address;
      }

   private:
      string name;
      string address;
};

class Restaurant : public Business {
   public:
      void SetRating(int userRating) {
         rating = userRating;
      }

      int GetRating() const {
         return rating;
      }
//this function cannot access or change the private values of business
//must change to protected for you to be able to access
   private:
      int rating;
};

int main() {
   Business someBusiness;
   Restaurant favoritePlace;

   someBusiness.SetName("ACME");
   someBusiness.SetAddress("4 Main St");

   favoritePlace.SetName("Friends Cafe");
   favoritePlace.SetAddress("500 W 2nd Ave");
   favoritePlace.SetRating(5);

   //cout << someBusiness.GetDescription() << endl;
   //cout << favoritePlace.GetDescription() << endl;
   //cout << "  Rating: " << favoritePlace.GetRating() << endl;

   return 0;
}

/*
class Restaurant : public Business {

   ...

   string GetDescription() const {
      return Business::GetDescription() + "\n  Rating: " + to_string(rating);
      //Business::GetDescription is how you call the original method from business and add to it
      //if you simply wwant to rewrite the function, you dont have to use Business::_______(), simply rewrite it
      --- make sure both methods have the const keyword after the method call 
   };

   ...
}; */