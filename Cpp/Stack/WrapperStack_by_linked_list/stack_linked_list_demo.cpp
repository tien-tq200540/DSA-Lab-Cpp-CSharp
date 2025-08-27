#include "stack_linked_list.h"
#include <iostream>
using namespace std;

int main() {
	StackLinkedList s;
	for (int i = 0; i < 10; i++) {
		cout << "Push " << i << " into stack\n";
		s.push(i);
	}
	cout << "Size of stack = " << s.size() << endl;
	
	cout << "Top stack = " << s.top() << endl;
	s.pop();
	cout << "Now top stack = " << s.top() << endl;
	s.clear();
	if (s.empty()) cout << "Stack now is empty!";
	else cout << "Stack is not empty!";
	return 0;
}
