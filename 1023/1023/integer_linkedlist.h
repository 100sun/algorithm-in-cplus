#include <iostream>
#include <list>
#include <initializer_list>
using namespace std;

struct snode {
	snode() : snode(0) {}
	snode(int data, snode* next = nullptr) :data_(data), next_(next) {}
	int data_;
	snode* next_;
};

class integer_linkedlist {
public:
	integer_linkedlist() : head_(nullptr), size_(0) {};
	integer_linkedlist(const initializer_list<int>& li) : integer_linkedlist() {
		for (int el : li)
			push_front(el);
	}

	void push_front(int data) {
		snode* newnode = new snode(data, head_);
		head_ = newnode;
		++size_;
	}

	void push_back(snode* p) {
		p->next_ = nullptr;
		if (head_ == nullptr) {
			head_ = p;
			++size_;
			return;
		}
		snode* q = head_;
		while (q->next_ != nullptr) {
			q = q->next_;
		}
		q->next_ = p;
		++size_;
	}

	friend ostream& operator<<(ostream& os, const integer_linkedlist& li) {
		if (li.size_ == 0) return os << "list is empty\n";
		snode* p = li.head_;
		while (p != nullptr) {
			os << *p;
			p = p->next_;
		}
		return os;
	}

	snode* clip_front() {
		if (head_ == nullptr) return head_;

		snode* p = head_;
		head_ = head_->next_;
		--size_;
		p->next_ = nullptr;
		
		return p;
	}

	void rotate_left() {
		snode* front_ = clip_front();
		push_back(front_);
	}

	int largest_index() {
		if (head_ == nullptr) { 
			cout << "list is empty\n";
			return -1;
		}
		snode* p = head_;
		int largest = p->data_;
		int index = 0, largest_index = 0;
		while (p != nullptr) {
			//
		}
		return largest_index;
	}
private:
	snode * head_;
	int size_;
};
