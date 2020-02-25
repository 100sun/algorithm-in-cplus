#include <iostream>
#include <string>
#include <list>
#include <initializer_list>
using namespace std;

// 1
bool any_different(int* p, size_t n) {
	for (int i = 0; i < n - 1; i++) {
		if (*p != *(p + 1)) return false;
		p++;
	}
	return true;
}

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

	// 2
	bool any_different()const {
		snode* p = head_;
		while (p->next_ != nullptr) {
			if (p->data_ != p->next_->data_) return false;
			p = p->next_;
		}
		return true;
	}

	// 3
	bool all_equal_to(int val) const {
		return all_equal_to_helper(head_, val);
	}
	bool all_equal_to_helper(snode* no, int val) const {
		if (no->data_ != val) return false;
		return all_equal_to_helper(no->next_, val);
	}
private:
	snode * head_;
	int size_;
};

// 4	
char* strcpy_(char* s, const char* t) {
	if (s == NULL) return NULL;
	char *p = s;
	while (*t != '\0') {
		*s = *t;
		s++;
		t++;
	}
	*s = '\0';
	return p;
}

int main(int argc, const char * argv[]) {

	int x[] = { 17,17,19,17 }; // true 1
	int y[] = { 17,17,17,17 }; // false 0
	cout << any_different(x, 4) << "\n" << any_different(y, 4) << "\n";

	integer_linkedlist xx = { 17,17,19,17 }; // true 1
	integer_linkedlist yy = { 17,17,17,17 }; // false 0
	cout << xx.any_different() << "\n" << yy.any_different() << "\n";
	cout << xx.all_equal_to(19) << "\n" << yy.all_equal_to(19) << "\n";

	char buf[100] = "hello, world!";
	char empty[100];
	strcpy_(empty, buf);
	cout << "first buf: " << buf << "\n";
	cout << "second buf: " << empty << "\n";


	return 0;
}