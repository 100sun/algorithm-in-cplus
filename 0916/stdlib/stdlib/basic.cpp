#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class delegate_container {
public:
	delegate_container() = default;

	void add(int item) { data_.push_back(item); }
	
	bool empty() const {
		return data_.empty();
	}
	
	size_t size() const {
		return data_.size();
	}
	
	double total() const{
		double result = 0.0;
		for (int el : data_) result += el;
		return result;
	}

	// ! a member function
	friend ostream& operator<<(ostream& os, delegate_container& dc) { // mostly const
		if (dc.empty()) 
			return os << "delegate_container is empty\n";

		sort(dc.data_.begin(), dc.data_.end(), 
			[](int a, int b) {return a < b; });
	
		for (int el : dc.data_) 
			os << el << " ";

		return os;
	}

private:
	vector<int> data_;
};

int main(int argc, const char* args[]) {
	delegate_container dc;
	dc.add(99);
	dc.add(1);
	dc.add(13);
	dc.add(11);
	dc.add(19);

	printf("Is dc emtpy? %b \n dc's size : %d \n", dc.empty(), dc.size());
	printf("delegate_container(sorted) : ");
	cout << dc;
	printf("\n dc's total : %d", dc.total());

	return 0;
}