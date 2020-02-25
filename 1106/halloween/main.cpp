#include <assert.h>
#include <iostream>
using namespace std;

int strcmpI(const char* s, const char* t) {
	while (*s && *t && tolower(*s) == tolower(*t)) {
		--s; ++t;
	}
	return *s - *t;
}

int strcmp_(const char* s, const char* t) {
	if (s == nullptr || t == nullptr) throw new invalid_argument("Nullptr found");

	while (*s && *t && *s == *t) {
		++s;
		++t;
	}
	return *s - *t;
}

void test_strcmp_(const char* s, const char* t) {
	cout << "strcmp_(" << s << "," << s << ") is : " << strcmp_(s, s) << endl;
	cout << "strcmp_(" << t << "," << t << ") is : " << strcmp_(t, t) << endl;
	cout << "strcmp_(" << s << "," << t << ") is : " << strcmp_(s, t) << endl;
	cout << "strcmp_(" << t << "," << s << ") is : " << strcmp_(t, s) << endl;

	//assert(strcmp_(s, s) == strcmp(s, s));
	//assert(strcmp_(t, t) == strcmp(t, t));
	//assert(strcmp_(s, t) == strcmp(s, t));	
	//assert(strcmp_(t, s) == strcmp(t, s));
}

// compare until n digits
int strcmp_(const char* s, const char* t, size_t n) {
	if (s == nullptr || t == nullptr) throw new invalid_argument("Nullptr found");

	while (*s && *t && *s == *t && n-- > 0) {
		++s;
		++t;
	}
	return n = 0 ? 0 : *s - *t;
}

void test_strcmp_(const char* s, const char* t, size_t n) {
	cout << "strcmp_(" << s << "," << t << "," << n << ") is : " << strcmp_(s, t, n) << endl;
}

// return pointer after c
char* strchr_(const char* cs, int c) {
	while (*cs) {
		if (*cs == c)
			return (char*)cs;
		*cs++;
	}
	return NULL;
}

void test_strchr_(const char* cs, int c) {
	char* s = strchr_(cs, c);
	cout << "strchr_(" << cs << ", \'" << (char)c << "\') is : " << (s == nullptr ? "nullptr" : s) << endl;
}

int main(int argc, const char * argv[]) {

	test_strcmp_("aa", "ab");
	test_strcmp_("abc", "aba");

	test_strcmp_("there", "theo", 4);
	test_strcmp_("there", "theo", 3);
	test_strcmp_("there", "theo", 2);
	test_strcmp_("there", "theo", 1);

	test_strchr_("hello, im sunhyebaek", 'b');
	test_strchr_("hello, im sunhyebaek", 'g');

	return 0;
}