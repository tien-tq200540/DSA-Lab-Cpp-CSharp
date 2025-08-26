#include "singly_linked_list.h"
#include <iostream>
using namespace std;

int main() {
	//DEMO
	SinglyLinkedList myList;
	for (int i = 0; i < 15; i++) myList.push_back(i);
	cout << "My 0-indexed linked list: "; myList.print_list(); cout << endl;
	cout << "Size = " << myList.size() << endl;
	//cout << "Value at index 3 is " << myList.get_value_at(3) << endl;
	myList.pop_back();
	cout << "My 0-indexed linked list after pop back: "; myList.print_list(); cout << endl;
	myList.insert_at(2, 10);
	cout << "My 0-indexed linked list after insert value = 10 at index = 2: "; myList.print_list(); cout << endl;
	myList.remove_at(0);
	cout << "My 0-indexed linked list after remove a value at index = 0: "; myList.print_list(); cout << endl;
	myList.reverse();
	cout << "My 0-indexed linked list after reverse: "; myList.print_list(); cout << endl;
	myList.clear();
	cout << "My 0-indexed linked list after clear: "; myList.print_list(); cout << endl;
	return 0;
}
