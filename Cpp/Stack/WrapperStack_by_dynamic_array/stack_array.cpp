#include "stack_array.h"
#include "../../Array/dynamic_array.h"

StackArray::StackArray() {
	
}

int StackArray::size() const {
	return data.size();
}

void StackArray::clear() {
	data.clear();
}

bool StackArray::empty() const {
	return data.size() == 0;
}

bool StackArray::contains(int value) const {
	for (int i = 0; i < data.size(); i++) {
		if (data.get_value_at(i) == value) return true;
	}
	return false;
}

void StackArray::push(int value) {
	data.push_back(value);
}

int StackArray::pop() {
	return data.pop_back();
}

int StackArray::top() const {
	return data.get_value_at(data.size() - 1);
}
