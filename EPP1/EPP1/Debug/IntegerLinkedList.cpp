// ADD ANSWER TO THIS FILE

#include "IntegerLinkedList.h"

// bool IntegerLinkedList::checkList() // COMPLETE THIS FOR PROBLEM 2
bool IntegerLinkedList::checkList() {
	SNode* p = head;
	while (p->next != nullptr) {
		if (p->elem != p->next->elem) return false;
		p = p->next;
	}
	return true;
}

bool IntegerLinkedList::checkRecurse(SNode *ptr) {
	//return -1; // COMPLETE THIS FOR PROBLEM 3
	if (ptr->next == nullptr) return ptr->elem == 0;
	return ptr->elem == 0 || checkRecurse(ptr->next);
}

void IntegerLinkedList::addFront(int x) {
	SNode *tmp = head;
	head = new SNode;
	head->next = tmp;
	head->elem = x;
}

// recursion helper function called from main for PROBLEM 3
bool IntegerLinkedList::checkRecurseHelper() {
	return checkRecurse(head);
}
