#pragma once
#include <stdio.h>

class Node {
	int data;
	Node* link;

public:
	Node(int val = 0) : data(val), link(NULL) {}
	int getData() {
		return data;
	}
	Node* getLink() {
		return link;
	}
	void setLink(Node* p) {
		link = p;
	}
	void display() {
		printf("<%2d>", data);
	}

	bool hasData(int val) {
		return data == val;
	}
	void insertNext(Node* p) {
		p->link = link;
		link = p;
	}
	Node* removeNext() {
		Node* p = link;
		if (p != NULL) link = p->link;
		return p;
	}
};