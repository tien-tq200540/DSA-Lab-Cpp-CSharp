#include "priority_queue_linked_list.h"
#include <stdexcept>

PriorityQueueLinkedList::PriorityQueueLinkedList() {
	head = nullptr;
	tail = nullptr;
	length = 0;
	capacity = 1000;
}

PriorityQueueLinkedList::PriorityQueueLinkedList(int cap) {
	head = nullptr;
	tail = nullptr;
	length = 0;
	capacity = cap;
}

PriorityQueueLinkedList::~PriorityQueueLinkedList() {
	clear();
}

int PriorityQueueLinkedList::size() const {
	return length;
}

int PriorityQueueLinkedList::get_capacity() const {
	return capacity;
}

void PriorityQueueLinkedList::clear() {
	Node* cur = head;
	while (cur != nullptr) {
		head = head->next;
		delete cur;
		cur = head;
	}
	head = nullptr; tail = nullptr;
	length = 0;
}

bool PriorityQueueLinkedList::empty() const {
	return length == 0;
}

bool PriorityQueueLinkedList::contains(int value) const {
	Node* cur = head;
	while (cur != nullptr) {
		if (cur->data == value) return true;
		cur = cur->next;
	}
	return false;
}

void PriorityQueueLinkedList::enqueue(int value) {
	if (length == capacity) throw std::runtime_error("Full of capacity! Cannot enqueue!");
	Node* newNode;
	if (length == 0) {
		newNode = new Node(value, 0);
		head = newNode; tail = newNode;
	} else {
		newNode = new Node(value, tail->weight+1);
		tail->next = newNode;
		tail = tail->next;
	}
	length++;
}

void PriorityQueueLinkedList::enqueue(int value, int weight) {
	if (length == capacity) throw std::runtime_error("Full of capacity! Cannot enqueue!");
	Node* newNode = new Node(value, weight);
	if (length == 0) {
		head = newNode;
		tail = newNode;
	} else if (newNode->weight < head->weight) {
		newNode->next = head;
		head = newNode;
	} else {
		Node* cur = head;
		while (cur->next != nullptr && cur->weight <= weight && cur->next->weight <= weight) cur = cur->next;
		newNode->next = cur->next;
		cur->next = newNode;
	}
	if (tail->next != nullptr) tail = tail->next;
	length++;
}

int PriorityQueueLinkedList::dequeue() {
	if (length == 0) throw std::runtime_error("Cannot dequeue of an empty priority queue!");
	Node* dequeueTop = head;
	head = head->next;
	int dequeueValue = dequeueTop->data;
	delete dequeueTop;
	length--;
	if (length == 0) {
		head = nullptr;
		tail = nullptr;
	}
	return dequeueValue;
}

int PriorityQueueLinkedList::top() const {
	if (length == 0) throw std::runtime_error("Cannot get top value of an empty priority queue!");
	return head->data;
}
