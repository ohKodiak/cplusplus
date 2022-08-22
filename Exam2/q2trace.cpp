#include <iostream>
using std::cout;
using std::endl;
using std::string;

int beta(int &r, int s) {
   r /= 3;
   s *= 2;
   int temp = r + s + 9;
   return temp;
}

int alpha(int p, int& q) {
   q = 4;
   int temp = beta(p, q);
   temp += p;
   return temp;
}

struct item {
   string iName;
   int iQuant;
   item() : iName(""), iQuant(0) {}
};

int main() {
   int a = 11;
   int b = 3;
   
   int c = alpha(a, b);
   
   int d = beta(c, a);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
   item* aLot = new item();
   item* evenMore = new item();

   aLot->iName = "gum";
   aLot->iQuant = c;
   evenMore->iName = "candy";
   evenMore->iQuant = d;

   cout << "Products from the " << a << "&" << b << " store" << endl;
   cout << (*aLot).iName << "'s quantity: " <<
      (*aLot).iQuant << endl;
   cout << (*evenMore).iName << "'s quantity: " <<
      (*evenMore).iQuant << endl;

  delete evenMore;
  aLot = nullptr;
}