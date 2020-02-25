//
// EDIT THIS FILE ONLY FOR YOUR OWN TESTING
// WRITE YOUR CODE IN IntegerLinkedList.h
//

#include <iostream>
#include <string>
#include "IntegerLinkedList.h"

using namespace std;

int main() {
	cout << "Check if all elements are equal" << endl;
	{
		IntegerLinkedList mylist;
		mylist.addFront(23);
		mylist.addFront(23);
		mylist.addFront(23);
		mylist.addFront(23);
		mylist.addFront(23);
		cout << "List: 23 -> 23 -> 23 -> 23 -> 23" << endl;
    if (mylist.checkList())
		  cout << "PASSED: checkList returned true" << endl;
		else
		  cout << "FAIL: checkList returned false; expected true" << endl;
  }
  {
		IntegerLinkedList mylist;
		mylist.addFront(23);
		mylist.addFront(23);
		mylist.addFront(23);
		mylist.addFront(17);
		mylist.addFront(23);
		cout << "List: 23 -> 17 -> 23 -> 23 -> 23" << endl;
    if (!mylist.checkList())
		  cout << "PASSED: checkList returned false" << endl;
		else
		  cout << "FAIL: checkList returned true; expected false" << endl;
  }
  {
		IntegerLinkedList mylist;
		mylist.addFront(17);
		mylist.addFront(23);
		mylist.addFront(23);
		mylist.addFront(23);
		mylist.addFront(23);
		cout << "List: 23 -> 23 -> 23 -> 23 -> 17" << endl;
		if (!mylist.checkList())
		  cout << "PASSED: checkList returned false" << endl;
		else
		  cout << "FAIL: checkList returned true; expected false" << endl;
  }
	// system("pause"); // comment/uncomment if needed
}
