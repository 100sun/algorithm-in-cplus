#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

size_t index_of_second_largest_value(int *p, size_t n) {
	int max = *p;
	int second = 0;

	for (size_t i = 0; i < n; i++) {
		if (*p > max) {
			second = max;
			max = *p;
		}
		p++;
	}

	return second;
}

struct snode {
	snode() :snode(0) {}
	snode(int data, snode* next = nullptr) :data_(data), next_(next) {}

	int data_;
	snode* next_;
};

class slist {
public:
	slist() :head_(nullptr), size_(0) {}

	void add_front(int data) {
		snode* newnode = new snode(data, head_);
		head_ = newnode;
		++size_;
	}

	int get_largest() const {
		if (head_ == nullptr) {
			cout << "list is empty\n";
			return -1;
		}

		snode* p = head_;
		int largest = p->data_;

		while (p != nullptr) {
			if (p->data_ > largest)
				largest = p->data_;
			p = p->next_;
		}
		return largest;
	}

	bool is_greater(int n) {
		return is_greater_helper(head_, n);
	}

	bool is_greater_helper(snode* p, int n) {
		if (p->next_ == nullptr) return n > p->data_;
		return n > p->data_ && n > is_greater_helper(p->next_, n);
	}


private:
	snode * head_;
	size_t size_;
};

struct grocery_item {
	grocery_item() :grocery_item("", 0, 0, 0.00, 0.00) {}
	grocery_item(const std::string& name, size_t stock_id, int the_quantity_purchased, double current_price, double non_salses_price)
		:name_(name), stock_id_(stock_id), the_quantity_purchased_(the_quantity_purchased), current_price_(current_price), non_sales_price_(non_salses_price) {}

	friend std::istream& operator >> (std::istream& is, grocery_item& gi) {
		return is >> gi.name_ >> gi.stock_id_ >> gi.the_quantity_purchased_ >> gi.current_price_ >> gi.non_sales_price_;
	}

	friend std::ostream& operator << (std::ostream& cs, const grocery_item& gi) {
		return cs << gi.name_ << " " << gi.stock_id_ << " " << gi.the_quantity_purchased_ << " " << gi.current_price_ << " " << gi.non_sales_price_<< "\n";
	}

	string name_;
	size_t stock_id_;
	int the_quantity_purchased_;
	double current_price_;
	double non_sales_price_;
};

class grocery_list {
public:
	grocery_list() :items_() {}

	void add_back(grocery_item item) {
		items_.push_back(item);
	}

	double subtotal() const {
		double subtotal = 0.0;
		for (const grocery_item& gi : items_)
			subtotal += gi.current_price_;
		return subtotal;
	}

	double sales_tax() const {
		double sales_tax = subtotal()*0.0925;
		return sales_tax;
	}

	double saved_money() const {
		double saved_money = 0.0;
		for (const grocery_item& gi : items_)
			saved_money += (gi.non_sales_price_-gi.current_price_);
		return saved_money;
	}

	double total() const {
		double total = 0.0;
		total = subtotal() + sales_tax();
		return total;
	}

	// display
	friend ostream& operator<<(ostream& os, const grocery_list& gb) {
		if (gb.items_.empty()) return os << "No items in your grocery bill\n";
		for (const grocery_item& gi : gb.items_)
			os << gi;
		printf("\n subtotal : %lf + sales tax : %lf = total : %lf\n saved money : %lf", gb.subtotal(), gb.sales_tax(), gb.total(), gb.saved_money());
		return os;
	}

private:
	vector<grocery_item> items_;
};

int main(int argc, const char * argv[]) {

	// Q1
	int x[] = { -22,10,20,-5,8,-90,7 };
	int x_size = sizeof(x) / sizeof(int);
	std::cout << "\nSecond largest array : " << index_of_second_largest_value(x, x_size) << "\nLargest value";

	// Q2 Q3
	slist sli;
	sli.add_front(5);
	sli.add_front(13);
	sli.add_front(3);
	sli.add_front(-2);
	sli.add_front(-1);

	cout << sli.get_largest() << "\nis greater than 16: " << sli.is_greater(16) << "\n";
	
	// Q4 Q5
	if (argc != 2) {
		cerr << "Usage: prog filename\n";
		exit(1);
	}

	std::string fname = argv[1];
	std::cout << "Filename is " << fname << ".\n";

	std::ifstream ifs(fname);
	if (!ifs.is_open()) {
		cerr << "We could not open " << fname << ".\n";
		exit(2);
	}

	grocery_item gi;
	grocery_list bill;
	while (ifs >> gi) {
		bill.add_back(gi);
	}
	cout << "\n" << bill;

	ifs.close();

	return 0;
}