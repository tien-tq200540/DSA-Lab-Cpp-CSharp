#include <iostream>
#include "stack_array.h"
using namespace std;

int main() {
	StackArray s;
	for (int i = 0; i < 10; i++) {
		cout << "Push " << i << " into stack\n";
		s.push(i);
	}
	
	cout << "Stack size = " << s.size() << endl;
	cout << "Top of stack = " << s.top() << endl;
	cout << "--- Pop ----\n";
	s.pop();
	cout << "After pop, top of stack = " << s.top() << endl;
	
	if (!s.empty()) {
		cout << "Stack is not empty! Clear!\n";
		s.clear();
	}
	if (s.empty()) cout << "Now stack is empty!";
	else cout << "Stack is not empty!";	
	return 0;
}
