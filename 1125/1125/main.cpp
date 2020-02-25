#include <iostream>
#include "main.h"
using namespace std;

void printIfOdd(int x) {
	if (x % 2 == 1) cout << x << " ";
}

void printOdds(int *p, size_t n) {
	if (n == 1){ printIfOdd(*p); return;}
	printIfOdd(*p);
	printOdds(p + 1, n - 1);
}

void printOddsThenEvens(int *p, size_t n) {
	printOdds(p, n);
	printEvens(p, n);
}

int main(int argc, const char* argv[]) {

	return 0;
}