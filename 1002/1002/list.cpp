//  recurisve_list

#include <iostream>
#include <list>

struct snode {
	int data_;
	snode* next_;
};

class slist {
private:
	snode * head_, *tail_;
public:
	slist() { head_ = NULL; tail_ = NULL; }

	void push_front(int value) {
		snode *temp = new snode;
		temp->data_ = value;
		temp->next_ = head_;
		head_ = temp;
	}


	void print_forwards() {
		print_forwards_helper(head_);
	}

	void print_forwards_helper(snode* p) {
		if (p == nullptr) return;
		std::cout << p->data_ << " ";
		print_forwards_helper(p->next_);
	}


	void print_backwards() {
		print_backwards_helper(head_);
	}

	void print_backwards_helper(snode* p) {
		if (p == nullptr) return;
		print_backwards_helper(p->next_);
		std::cout << p->data_ << " ";
	}

};



class list_int {
private:
	std::list<int> list_;
public:
	list_int() = default;
	void add_front(int x) { list_.push_front(x); }
	void add_back(int x) { list_.push_back(x); }
	int front() const { return list_.front(); }
	int back() const { return list_.back(); }
	bool empty() const { return list_.empty(); }
	size_t size() const { return list_.size(); }
	
	void print_backwards() {
		print_backwards_helper(list_.begin());
	}
	void print_backwards_helper(std::list <int>::iterator it) const {
		if (it == list_.end()) return;
		int val = *it;
		print_backwards_helper(++it);
		std::cout << val << " ";
	}

	void print_forwards() {
		print_forwards_helper(list_.begin());
	}
	void print_forwards_helper(std::list <int>::iterator it) const {
		if (it == list_.end()) return;
		std::cout << *it << " ";
		print_forwards_helper(++it);
	}

	void clear() { list_.clear(); }
	
	friend std::ostream& operator<<(std::ostream& os, const list_int& li) {
		if (li.empty()) return os << "list is empty\n";
		for (int el : li.list_) os << el << " ";
		return os;
	}

};

// in recursion you should write only 3 lines and except from printing only 2!!

void print_forwards(int* array, size_t n) {
	if (n == 0) return;
	std::cout << *array << " "; //forwards
	print_forwards(array + 1, n - 1);
}

void print_backwards(int* array, size_t n) {
	if (n == 0) return;
	print_backwards(array + 1, n - 1);
	std::cout << *array << " ";
}

int main(int argc, const char * argv[]) {
	// insert code here...
	int arr[] = { 1,2,3,4,5 };
	print_forwards(arr, sizeof(arr) / sizeof(int));
	std::cout << std::endl;
	print_backwards(arr, sizeof(arr) / sizeof(int));
	std::cout << std::endl;

	list_int li;
	li.add_back(10);
	li.add_back(20);
	li.add_back(30);
	li.add_back(40);
	li.add_back(50);
	li.print_forwards();
	std::cout << std::endl;
	li.print_backwards();
	std::cout << std::endl;

	slist sli;
	sli.push_front(100);
	sli.push_front(200);
	sli.push_front(300);
	sli.push_front(400);
	sli.push_front(500);
	sli.print_forwards();
	std::cout << std::endl;
	sli.print_backwards();
	std::cout << std::endl;
	return 0;
}