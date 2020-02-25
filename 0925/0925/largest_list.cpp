#include <iostream>
#include <stdlib.h>
using namespace std;

struct snode {
	int data_;
	snode* next_;

	snode() :snode(0) {}
	snode(int data, snode* next=nullptr) :data_(data), next_(next) {}
};

class slist {
private:
	snode * head_;
public:
	slist() : head_(nullptr) {}
	
	snode* front() const { return head_; }

	void add_front(int data) {
		snode* newnode = new snode(data, head_);
		head_ = newnode;
	}
};

template <typename T1>
T1 max(const T1& a, const T1& b) { return a > b ? a : b; }

int largest_list(snode* p) {
	if (p->next_ == nullptr) return p->data_;
	return max(p->data_, largest_list(p->next_));
}

int main(int argc, const char* argv[]) {
	slist li;
	li.add_front(-1);
	li.add_front(0);
	li.add_front(-3);
	li.add_front(-2);

	cout << largest_list(li.front());
	return 0;
}