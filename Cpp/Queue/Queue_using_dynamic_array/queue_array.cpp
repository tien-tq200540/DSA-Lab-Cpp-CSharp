#include "queue_array.h"
#include "../IQueue.h"
#include <stdexcept>

QueueArray::QueueArray() {
	length = 0;
	capacity = 1000;
	data = new int[capacity];
	head = tail = 0;
}

QueueArray::QueueArray(int cap) {
	length = 0;
	capacity = cap;
	data = new int[capacity];
	head = tail = 0;
}

QueueArray::~QueueArray() {
	delete[] data;
	data = nullptr;
}

int QueueArray::size() const {
	return length;
}

int QueueArray::get_capacity() const {
	return capacity;
}

void QueueArray::clear() {
	length = head = tail = 0;
}

bool QueueArray::empty() const {
	return length == 0;
}

bool QueueArray::contains(int value) const {
	for (int i = 0; i < length; i++) {
		if (data[(head+i)%capacity] == value) return true;
	}
	return false;
}

void QueueArray::enqueue(int value) {
	if (length >= capacity) {
		capacity *= 2;
		int* newData = new int[capacity];
		for (int i = 0; i < length; i++) {
			newData[i] = data[(head+i)%capacity];
		}
		delete[] data; data = newData;
		head = 0; tail = length;
	}
	data[tail] = value;
	tail = (tail + 1) % capacity;
	length++;
}

int QueueArray::dequeue() {
	if (length == 0) throw std::runtime_error("Nothing to dequeue!");
	int value = data[head];
	head = (head + 1) % capacity;
	length--;
	return value;
}

int QueueArray::top() const {
	if (length == 0) throw std::runtime_error("Nothing to see in top queue!");
	return data[head];
}
