#include "stack_linked_list.h"
#include "../../Linked_List/singly_linked_list.h"

StackLinkedList::StackLinkedList() {
	
}

int StackLinkedList::size() const {
	return data.size();
}

void StackLinkedList::clear() {
	data.clear();
}

bool StackLinkedList::empty() const {
	return data.size() == 0;
}

bool StackLinkedList::contains(int value) const {
	for (int i = 0; i < data.size(); i++) {
		if (data.get_value_at(i) == value) return true;
	}
	return false;
}

void StackLinkedList::push(int value) {
	data.push_back(value);
}

int StackLinkedList::pop() {
	data.pop_back();
}

int StackLinkedList::top() const {
	return data.get_value_at(data.size() - 1);
}
