//
//  main.cpp
//  simple_vector
//
//  Created by sophia100 on 9/9/19.
//  Copyright © 2019 sophia100. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>

using namespace std;

// class VS struct : private VS public
struct grocery_item {
	grocery_item()
		:grocery_item("", 0, 0.00) {}
	grocery_item(const std::string& name, size_t code, double price)
		:name_(name), code_(code), price_(price) {}

	friend std::istream& operator >> (std::istream& is, grocery_item& gi) {
		return is >> gi.name_ >> gi.code_ >> gi.price_;
	}
	friend std::ostream& operator << (std::ostream& cs, const grocery_item& gi) {
		return cs << gi.name_ << " " << gi.code_ << " " << gi.price_ << "\n";
	}

	//std::string name()const {
	//	return name_;
	//}
	//size_t code()const {
	//	return code_;
	//}
	//double price()const {
	//	return price_;
	//}

	std::string name_;
	size_t code_;
	double price_;
};

class grocery_bill {
public:
	grocery_bill() :items_() {}

	size_t size() const { return items_.size(); }

	double total() const {
		double total = 0.0;
		for (const grocery_item& gi : items_)
			total += gi.price_;
		return total;
	}

	// sort 
	friend bool operator<(const grocery_item& lhs, const grocery_item& rhs) {
		return((lhs.price_ > rhs.price_) ||
			(lhs.price_ == rhs.price_ && lhs.name_ < rhs.name_)) ||
			(lhs.name_ == rhs.name_&& lhs.code_ > rhs.code_);
	}

	// display
	friend ostream& operator<<(ostream& os, const grocery_bill& gb) {
		if (gb.items_.size()) return os << "No items in your grocery bill\n";
		for (const grocery_item& gi : gb.items_)
			os << gi;
		return os;
	}

private:
	vector<grocery_item> items_;
};

int main(int argc, const char * argv[]) {

	// terminal : ls -> cd -> ./simple_vector : err => ./simple_vector Baek : Hello, Baek -> ls -al
	// nano items.txt -> cat items.txt
	// argv[0] : ~.cpp / argv[1] : items.txt
	if (argc != 2) { // 2 for only fname 3 for f l name
		cerr << "Usage: prog filename\n"; // instance(object) of ostream <- same operator
		exit(1); // everything is not cool
	}

	//    std::string fname = argv[1];
	//    std::string lname = argv[2];
	//    std::cout << "Hello, " << fname << " " << lname << "\n";

	std::string fname = argv[1];
	std::cout << "Filename is " << fname << ".\n"; // instance of ostream

	// open
	// nano items.txt -> ls -> rebuild -> ./stdlib items.txt 
	std::ifstream ifs(fname); // iostream
	if (!ifs.is_open()) {
		cerr << "We could not open " << fname << ".\n";
		exit(2);
	}

	//// read
	//char c = '\n';
	//while (ifs.good()) {
	//	cout << c;
	//	c = ifs.get();
	//}

	grocery_item gi;

	//while (ifs >> gi) 
	//	cout << gi;

	vector<grocery_item> bill;
	while (ifs >> gi) {
		bill.push_back(gi);
	}

	/*double total = 0.0;
	for (const grocery_item& el : bill) {
		total += el.price_;
		cout << el;
	}

	printf("Total of bill is : %lf\n\n", total);*/

	ifs.close();

	return 0; // everything is cool
}