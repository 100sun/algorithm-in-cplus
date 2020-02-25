#include "IntegerLinkedList.h"

int main()
{
	IntegerLinkedList list;
	list.insert(0, new Node(10));
	list.insert(0, new Node(20));
	list.insert(1, new Node(30));
	list.insert(list.size(), new Node(40));
	list.insert(2, new Node(50));
	list.display();

	list.reverse();

	IntegerLinkedList list2;
	list2.insert(0, new Node(105));
	list2.insert(0, new Node(104));
	list2.insert(0, new Node(103));
	list2.insert(0, new Node(102));
	list2.insert(0, new Node(101));
	list2.insert(0, new Node(100));
	list.merge(&list2);

	return 0;
}