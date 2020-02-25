//
// EDIT THIS FILE ONLY FOR YOUR OWN TESTING
// WRITE YOUR CODE IN IntegerLinkedList.h
//

#include <iostream>
#include <string>
#include "IntegerLinkedList.h"

using std::string;
using std::cout;
using std::endl;

int main() {
	cout << "Check if any element is zero" << endl;
	{
		IntegerLinkedList mylist;
		mylist.addFront(23);
		mylist.addFront(23);
		mylist.addFront(0);
		mylist.addFront(23);
		mylist.addFront(23);
		cout << "List: 23 -> 23 -> 0 -> 23 -> 23" << endl;
    if (mylist.checkRecurseHelper())
		  cout << "PASSED: checkRecurseHelper returned true" << endl;
		else
		  cout << "FAIL: checkRecurseHelper returned false; expected true" << endl;
  }
  {
		IntegerLinkedList mylist;
		mylist.addFront(23);
		mylist.addFront(23);
		mylist.addFront(23);
		mylist.addFront(17);
		mylist.addFront(23);
		cout << "List: 23 -> 17 -> 23 -> 23 -> 23" << endl;
    if (!mylist.checkRecurseHelper()) // check if any element is zero
		  cout << "PASSED: checkRecurseHelper returned false" << endl;
		else
		  cout << "FAIL: checkRecurseHelper returned true; expected false" << endl;
  }
  {
		IntegerLinkedList mylist;
		mylist.addFront(0);
		mylist.addFront(23);
		mylist.addFront(17);
		mylist.addFront(23);
		mylist.addFront(23);
		cout << "List: 23 -> 23 -> 17 -> 23 -> 0" << endl;
		if (mylist.checkRecurseHelper()) // check if any element is zero
		  cout << "PASSED: checkRecurseHelper returned true" << endl;
		else
		  cout << "FAIL: checkRecurseHelper returned false; expected true" << endl;
  }
	// system("pause"); // comment/uncomment if needed

}
