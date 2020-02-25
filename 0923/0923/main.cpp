#include "slist.h"

// recursion

int fibo(int n) {
	if (n <= 1) { return 1; }
	return fibo(n - 1) + fibo(n - 2);
}

int fact(int n) {
	if (n == 1) return 1;
	else return (n * fact(n - 1));
}

// sum

int sum(int n) {
	if (n < 1) return 1;
	else return n + sum(n - 1);
}

int sum_array(int* p, size_t n) {
	if (n == 1) return *p;
	return *p + sum_array(p + 1, n - 1);
}

int sum_list(snode* p) {
	if (p->next_ == nullptr) return p->data_;
	return p->data_ + sum_list(p->next_);
}

// prod

int prod_array(int* p, size_t n) {
	if (n == 1) return *p;
	return *p * prod_array(p + 1, n - 1);
}

int prod_list(snode* p) {
	if (p->next_ == nullptr) return p->data_;
	return p->data_ * prod_list(p->next_);
}

// min 
template <typename T>
T min(const T& a, const T& b) { return a < b ? a : b; }

int min_arr(int* p, size_t n) {
	if (n == 1) return *p;
	return min(*p, min_arr(p + 1, n - 1));
}

int min_list(snode* p) {
	if (p->next_ == nullptr) return p->data_;
	return min(p->data_ , min_list(p->next_));
}

// max
template <typename T1>
T1 max(const T1& a, const T1& b) { return a > b ? a : b; }

int largest_arr(int *p, size_t n) {
	if (n == 1) return *p;
	return max(*p, largest_arr(p + 1, --n));
}

int largest_list(snode* p) {
	if (p->next_ == nullptr) return p->data_;
	return max(p->data_, largest_list(p->next_));
}

int main(int argc, const char* argv[]) {

	// largest
	int x[] = { 3,33,7,-1,5,2 };
	int x_size = sizeof(x) / sizeof(int);
	cout << "array : ";
	for (int i = 0; i < x_size ; i++) cout << x[i] << " ";
	cout << " \nlargest array : " << largest_arr(x, x_size) <<"\n";
	cout << "min array : " << min_arr(x, x_size) << "\n\n";

	slist sli3;
	sli3.add_front(5);
	sli3.add_front(10);
	sli3.add_front(3);
	sli3.add_front(-2);
	sli3.add_front(-1);

	cout << sli3 << "largest list : " << largest_list(sli3.front()) << "\n";
	cout << "min list : " << min_list(sli3.front()) << "\n\n";

	// recursion
	int n = 5;
	cout << "fibonacci of " << n << " is " << fibo(5) << "\n";
	cout << "factorial of " << n << " is " << fact(5) << "\n";
	cout << "sum of " << n << " is " << sum(5) << "\n\n";

	slist sli2;
	sli2.add_back(5);
	sli2.add_back(10);
	sli2.add_back(3);
	sli2.add_back(-2);
	sli2.add_back(-1);

	cout << sli2 << "sum of list is " << sum_list(sli2.front()) << "\n";
	cout << "prod of list is " << prod_list(sli2.front()) << "\n\n\n";

	// linked_list
	slist sli;
	sli.add_front(5);
	sli.add_front(10);
	sli.add_front(3);
	sli.add_front(-2);
	sli.add_front(-1);

	cout << sli << "\n";
	printf("size : %d \nsmallest index : %d\n\n", sli.size(), sli.get_smallest());

	return 0;
}