#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct car {
	string model;
	string mfr;
	int milege;
	int cost;
	int engine;
	
	car() :car("", "", 0, 0, 0) {}
	car(const string& model_, const string& mfr_, int milege_, int cost_, int engine_)
		:model(model_), mfr(mfr_), milege(milege_), cost(cost_), engine(engine_) {}'
	

	friend istream& operator>>(istream& is, car& c) {
		return is >> c.model >> c.mfr >> c.mileage >> c.cost >> c.engine;
	}
	friend ostream& operator<<(ostream& os, car& c) {
		return os << c.model << "," << c.mfr << "," << c.mileage << "," << c.cost << "," << c.engine << "kw";
	}

};

struct student {
	string lname;
	string fname;
	int gpa;
	int id;
};

class collection {
public:
	collection() = default;
	
	void add(const car& c){
		cars_.push_back(c);
	}

	void printbycost() {
		sort(cars_.begin(), cars_.end(), [](const car&a, const car& b) {
			return a.cost > b.cost;
		}
		print();
	}
	void printbyengine();
	void printbymilege();
	int numbercars() {
		return cars_.size();
	}
	void print() {
		for (car& c : cars_) {
			cout << c << "\n";
		}
	}
private:
	vector<car> cars_;
};