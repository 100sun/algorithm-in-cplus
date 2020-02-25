#include <iostream>
#include <fstream>
#include "car.h"
using namespace std;

double mean(int* p, int n) {
	if (n == 1) return *p;
	return *p + (n - 1)*mean(p + 1, n - 1);
}

int main(int argc, const char* argv[]) {

	if (argc != 2) {
		cerr << "Usage: prog filename\n";
		exit(1);
	}

	std::string fname = argv[1];

	std::ifstream ifs("cars.txt");
	if (!ifs.is_open()) {
		cerr << "We could not open cars.txt\n";
		exit(2);
	}

	car c;
	collection cars;
	while (ifs >> c) {
		cars.add(c);
	}

	ifs.close();
	return 0;
}