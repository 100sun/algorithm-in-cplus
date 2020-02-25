#include <iostream>
#include <stdlib.h>
using namespace std;

struct snode {
	snode() :snode(0) {}
	snode(int data, snode* next = nullptr) :data_(data), next_(next) {}

	friend  ostream& operator<<(ostream& os, const snode& n) {
		return os << n.data_ << "->" << n.next_ << "\n";
	}

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

	void add_back(int data) {
		if (head_ == nullptr) {
			add_front(data);
			return;
		}
		snode* newnode = new snode(data);

		snode* p = head_;
		while (p->next_ != nullptr) {
			p = p->next_;
		}
		
		p->next_ = newnode;
		++size_;
	}

	snode* front() const { return head_; }
	bool empty() const { return size_ == 0; }

	int size() const { return size_; }

	friend ostream& operator<<(ostream& os, const slist& sli) {
		if (sli.size_ == 0) return os << "list is empty\n";
		snode* p = sli.head_;
		while (p != nullptr) {
			os << *p;
			p = p->next_;
		}
		return os;
	}

	int get_smallest() const {
		if (head_ == nullptr) {
			cout << "list is empty\n";
			return -1;
		}

		snode* p = head_;
		int smallest = p->data_, index = 0, smallest_index = 0;

		while (p != nullptr) {
			if (p->data_ < smallest) {
				smallest = p->data_;
				smallest_index = index;
			}
			p = p->next_;
			++index;
			//	printf("current %d (%d) VS smallest %d => smallest_index %d\n", p->data_, index, smallest, smallest_index);
		}
		return smallest_index;
	}

private:
	snode * head_;
	size_t size_;
};
