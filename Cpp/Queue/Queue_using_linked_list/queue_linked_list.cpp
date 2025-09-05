#include "queue_linked_list.h"
#include <stdexcept>

QueueLinkedList::QueueLinkedList() {
	length = 0;
	capacity = 1000;
	head = nullptr;
	tail = nullptr;
}

QueueLinkedList::QueueLinkedList(int cap) {
	length = 0;
	capacity = cap;
	head = nullptr;
	tail = nullptr;
}

QueueLinkedList::~QueueLinkedList() {
	clear();
}

int QueueLinkedList::size() const {
	return length;
}

int QueueLinkedList::get_capacity() const {
	return capacity;
}

void QueueLinkedList::clear() {
	length = 0;
	Node* cur = head;
	while (cur != nullptr) {
		head = head->next;
		delete cur;
		cur = head;
	}
	head = nullptr; tail = nullptr;
}

bool QueueLinkedList::empty() const {
	return length == 0;
}

bool QueueLinkedList::contains(int value) const {
	Node* cur = head;
	while (cur != nullptr) {
		if (cur->data == value) return true;
		cur = cur->next;
	}
	return false;
}

void QueueLinkedList::enqueue(int value) {
	if (length >= capacity) throw std::runtime_error("Full of queue capacity!");
	Node* newNode = new Node(value);
	if (length == 0) {
		head = newNode;
		tail = newNode;
	} else {
		tail->next = newNode;
		tail = tail->next;
	}
	length++;
}

int QueueLinkedList::dequeue() {
	if (empty()) throw std::runtime_error("Empty queue cannot dequeue!");
	Node* oldHead = head;
	head = head->next;
	int dequeueValue = oldHead->data;
	delete oldHead;
	length--;
	if (head == nullptr) tail = nullptr;
	return dequeueValue;
}

int QueueLinkedList::top() const {
	if (empty()) throw std::runtime_error("Empty queue cannot top!");
	return head->data;
}
