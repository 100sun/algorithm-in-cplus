#pragma once
#include <initializer_list>
#include <list>
#include <iostream>
using namespace std;

struct snode {
	snode() : snode(0) {}
	snode(int data, snode* next = nullptr) :data_(data), next_(next) {}
	int data_;
	snode* next_;
};

class int_list {
public:
	int_list() : head_(nullptr), size_(0) {};
	int_list(const initializer_list<int>& li) : int_list() {
		for (int el : li)
			push_front(el);
	}

	void push_front(int data) {
		snode* newnode = new snode(data, head_);
		head_ = newnode;
		++size_;
	}

	bool islesser(int cmp) {
		return isLesserHelper(head_, cmp);
	}

	//for (int el : list_)
	//	if (el > cmp) return false;

	bool isLesserHelper(snode* no, int n) {
		if (no->next_ == nullptr) return n < no->data_;
		return n < no->data_ && n < isLesserHelper(no->next_, n);
	}


	bool isLesserHelper(list<int>::const_iterator it, int n) {
		auto it2 = it;
		if (++it2 == tail_) return n < *it;
		return n < *it && isLesserHelper(++it, n);
	}

	/*friend ostream& operator<<(ostream& os, const int_list& li) {
		if (li.size_==0) return os << "list is empty\n";

		snode* p = li.head_;
		while (p != nullptr) {
			os << *p;
			p = p->next_;
		}
		return os;
	}*/

	/*void print(tree* root) {
	if (root == nullptr) return;
	print(root->left());
	print(*root);
	print(root->right());
	}*/

private:
	snode* head_;
	snode* tail_;
	int size_;
};

int main(int argc, const char argv[]) {
	int_list li = { 10,17,23,17,92 };
	cout << li.islesser(15);
	system("pause");
}