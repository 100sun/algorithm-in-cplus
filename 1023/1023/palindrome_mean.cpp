#pragma once
#include <cassert>
#include <string>
#include "integer_linkedlist.h"

// ex. racecar
bool is_salindrome(const char* s) {
	const char* q = s + strlen(s) - 1;
	while (s < q && // until r a c e
		*s == *q) { // c == c
		++s;
		--q;
	}
	return *s == *q;
}

bool is_palindrome_(const char* s) {
	const char* p = s + strlen(p) - 1;
	while (*s && s < q) {
		if (*s != *p) return false;
		++s;
		--p;
	}
	return true;
}

bool is_palindrome(const string s) {
	return is_palindrome(s.c_str());
}

void test_is_palindrome(const string s) {
	cout << s << "is a palindrome\n";
	assert(is_palindrome(s));
}

// Áß°£°ª recursively
double mean(int* p, size_t n) {
	if (n == 1) return *p;
	return (1.0 / n) * // integer -> double 
		(*p +  // like 27
		(n - 1.0) // 
			* mean(p + 1, n - 1));
}
// *p + (n-1.0) * mean(p+1.n-1) / n

// ex. { 2 + (2) * 3.5} / 3	
// ex. { 1 + (3) * 3 } / 4
double mean_(int* p, size_t n) {
	if (n == 1) return *p;
	return (1.0 / n) * (*p + (n - 1.0) * mean(p + 1, n - 1));
}


double mean(snode* p, size_t n) {
	if (p->next_ == nullptr) return p->data_;
	return (1.0 / n) *(p->data_ + (n - 1.0) * mean(p->next_, n - 1));
}

void print(const string& msg, int* p, size_t n) {
	cout << msg << " ";
	while (n-- > 0) {
		cout << *p++ << " ";
	}
}

void test_mean(size_t n) {
	int x[100];

	for (size_t i = 0; i < n; ++i) {
		x[i] = (int)(i + 1);
	}

	double mean_ = mean(x, n);
	double mean_calc = 0.0;
	for (size_t i = 0; i < n; ++i) {
		mean_calc += x[i];
	}
	print("mean of ", x, n);
	cout << "is : " << mean(x, n) << "\n";
	assert(mean_ == mean_calc / n);
}



int main(int argc, const char* argv[]) {
	test_is_palindrome("mom");
	test_is_palindrome("dad");
	test_is_palindrome("boob");
	cout << " Palindrom test passed \n\n";

	integer_linkedlist li = { 5,10,15,20,25 };
	cout << "		li is : " << li << "\n";
	li.rotate_left();

	test_mean(3);
	test_mean(4);
	test_mean(5);
	cout << "recursive mean tests passed ";

	return 0;
}