#include <string>
#pragma once
#include "Node.h"

class IntegerLinkedList {
	Node org;
public:
	IntegerLinkedList() :org(0) {}
	~IntegerLinkedList() {
		while (!isEmpty()) delete remove(0);
	}
	bool isEmpty() {
		return getHead() == NULL;
	}
	Node* getHead() {
		return org.getLink();
	}
	void insert(int pos, Node* p) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) prev->insertNext(p);
	}
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) return prev->removeNext();
		else {
			printf("is Empty");
			return NULL;
		}
	}
	void replace(int pos, Node* p) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete prev->removeNext();
			prev->insertNext(p);
		}
	}
	Node* getEntry(int pos) {
		Node* p = &org;
		for (int i = -1; i < pos; i++) {
			p = p->getLink();
			if (p == NULL) break;
		}
		return p;
	}
	Node* find(int val) {
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			if (p->hasData(val)) return p;
		return NULL;
	}
	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			count++;
		return count;
	}
	void display() {
		printf("< Linked-List (simply) > \n\t[size] = %d\n\t[content] : ", size());
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			p->display();
		printf("\n");
	}

	int getIndexSmallest() {
		int count = 0, minIndex = 0;
		int min = getHead()->getData;
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			count++;
			if (p->getData() < min) minIndex = count;
		}
		return minIndex;
	}
	
	bool isLesser(int compare) {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			if (p->getData() < compare) return false;
		return true;
	}

	// (1) 리스트의 모든 데이터 값을 더한 합을 출력하는 함수 sum()을 작성하세요.
	int sum() {
		int sum = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			sum += p->getData();
		return sum;
	}
	// (2) 리스트에서 특정한 값을 갖는 노드의 개수를 계산하는 함수 count(int number)를 작성하세요.
	int count(int val) {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			if (p->hasData(val)) count++;
		return count;
	}
	// (3) 리스트의 모든 노드의 순서를 반대로 바꾸는 연산을 수행하는 함수 reverse()를 작성하세요.
	void reverse() {
		int pos = 0;
		for (int i = 0; i < size(); i++) {
			//			Node *p = remove(size() - 1); // 삭제한 마지막 노드를 pos번째에 push 
			insert(pos++, remove(size() - 1)); // positon 증가
		}
		printf("\nResult of Reverse\n");
		display();
		printf("\t[sum] = %d\n", sum());
		printf("\t[count of %d] = %d\n", 100, count(100));
	}
	// (4) 다른 리스트 객채 that의 노드 정보를 현재 리스트에 병합하는 다음 연산을 함수로 작성하세요.
	void merge(IntegerLinkedList *that) {
		while (!that->isEmpty())
			insert(size(), (that->remove(0)));
		printf("\nResult of Merge\n");
		display();
		printf("\t[sum] = %d\n", sum());
		printf("\t[count of %d] = %d\n", 100, count(100));
	}
};

void increment(int& n) {
	n++;
}