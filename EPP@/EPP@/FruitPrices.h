//For the list of fruitprices, I use struct which contains each fruit elements. 
//To make a list of them, I use vector data structure to add, sort and so on.
//The specity reason I use vector rather than array is the size of data is variable and it is often to access data randomly.
//I use fstream to read the files.
//In the getAveragePrice function, num means the number of given fruit.

#pragma once
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Fruit {
	Fruit()
		: Fruit("", "", 0.00) {}

	Fruit(const string& name, string variety, double price)
		: name_(name), variety_(variety), price_(price) {}

	friend istream& operator>>(istream& is, Fruit& fr) {
		return is >> fr.name_ >> fr.variety_ >> fr.price_;
	}

	string name_;
	string variety_;
	double price_;
};


class FruitPrices {
public:
	FruitPrices() :items_() {}

	void add(const Fruit& fr) { items_.push_back(fr); }

	int readPriceList(string filename) {
		ifstream ifs(filename);
		if (!ifs.is_open()) { cerr << "Could not open. \n";  exit(1); }

		int nFruits = 0;
		Fruit item;
		while (ifs >> item) {
			add(item);
			nFruits++;
		}

		ifs.close();
		return nFruits;
	}

	double getAveragePrice(string fruit) const {
		double total = 0.0;

		int num = 0;
		for (const Fruit& fr : items_) {
			if (fr.name_ == fruit) {
				total += fr.price_;
				num++;
			}
		}
		if (num == 0) return -1;
		return total / num;
	}

private:
	vector<Fruit> items_;
};