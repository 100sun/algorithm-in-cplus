#include <iostream>
#include <string>
#include <cmath>   // abs()
#include "C:\Users\sunhy\OneDrive\¹®¼­\Univ\2-2\CLASS\LAB\EPP@\EPP@\FruitPrices.h"

using std::cout;
using std::endl;
using std::string;

bool testAnswer(const string &nameOfTest, double received, double expected);
template <typename T>
bool testAnswer(const string &nameOfTest, const T &received, const T &expected);

int main() {
  {	
	FruitPrices fp;
	testAnswer("file reading 1", fp.readPriceList("pricelist1.txt"), 6);
	testAnswer("getAveragePrice(Apple)", fp.getAveragePrice("Apple"), 2.64);
	testAnswer("getAveragePrice(Cherry)", fp.getAveragePrice("Cherry"), 5.35);
	testAnswer("getAveragePrice(Banana)", fp.getAveragePrice("Banana"), -1);
  }
  {
	FruitPrices fp;
	testAnswer("file reading 2", fp.readPriceList("pricelist2.txt"), 7);
	testAnswer("getAveragePrice(Apple)", fp.getAveragePrice("Apple"), 3.48);
	testAnswer("getAveragePrice(Cherry)", fp.getAveragePrice("Cherry"), 5.033);
	testAnswer("getAveragePrice(Banana)", fp.getAveragePrice("Banana"), 1.04);
  }
}

template <typename T>
bool testAnswer(const string &nameOfTest, const T &received, const T &expected) {
    if (received == expected) {
        cout << "\033[32m" << "PASSED "
				<< "\033[0m" << nameOfTest << ": expected and received " << received << endl;
        return true;
    }
    cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
    return false;
}

bool testAnswer(const string &nameOfTest, double received, double expected) {
  if ( std::abs(expected - received) < 0.005 )  {
    cout << "\033[32m" << "PASSED "
	 << "\033[0m" << nameOfTest << ": expected and received " << received << endl;
    return true;
  }
  cout << "\033[31m" << "FAILED "
       << "\033[0m" << nameOfTest << ": expected " << expected << " but received " << received << endl;
  return false;
}
