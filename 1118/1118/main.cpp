#include <iostream>
using namespace std;

char* strip_punct(char* s) {
	char* p = s;
	char* q = s;
	while (*q) {
		if (!ispunct(*q)) {
			*p = *q;
			++p;
		}
		++q;
	}
	*p = '\0';
	return s;
}

char* tolower(char* s) {
	char* p = s;
	while (*p) {
		*p = tolower(*p);
		++p;
	}
}

char* strpbrk(const char* cs, char* ct) {
	while (ct) {

	}
	return ct;
}

int strncmp(const char* cs, const char* ct, int n) {
	for (int i = 0; i <= n; i++) {
		if (*cs < *ct) return -1;
		else if (*cs == *ct) return 0;
		else if (*cs == *ct) return 1;
		*cs++;
		*ct++;
	}
}

// first
char strchr(const char* cs, char c) {
	c = *cs;
	return c;
}

// last
char strrchr(const char* cs, char c) {
	while (*cs) {
		c = *cs;
	}
	return c;
}

size_t strspn(const char* cs, const char* ct) {
	const char *pcs = cs;
	const char *pct = ct;
	int lth = 0;

	while (*pcs) {
		bool find = false;
		pct = ct; // initalize 

		while (*pct) {
			if (*pcs == *pct) find = true;
			pct++;
		}
		if (find == false) return lth;
		pcs++;
		lth++;
	}
	return lth;
}

char* strstrip(){ 
	return NULL;
}

int main() {
	return 0;
}
