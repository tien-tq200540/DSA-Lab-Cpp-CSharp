#include "singly_linked_list.h"
#include <iostream>
#include <stdexcept>
using namespace std;

SinglyLinkedList::SinglyLinkedList() {
	head = nullptr;
	length = 0;
}
		
SinglyLinkedList::~SinglyLinkedList() {
	//delete all nodes in list
	clear();
}
		
SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& other) {
	Node* otherIte = other.head;
	while (otherIte != nullptr) {
		//clone a node from other list, then push_back
		push_back(otherIte->data);
		otherIte = otherIte->next;
	}
}
		
SinglyLinkedList& SinglyLinkedList::operator = (const SinglyLinkedList& other) {
	if (this != &other) {
		//same with copy constructor
		clear();
		Node* otherIte = other.head;
		while (otherIte != nullptr) {
			push_back(otherIte->data);
			otherIte = otherIte->next;
		}
	}
	return *this;
}
		
void SinglyLinkedList::print_list() {
	if (length == 0 && head == nullptr) {
		cout << "Empty linked list!";
		return;
	}
			
	Node* cur = head;
	while (cur != nullptr) {
		cout << cur->data << "-->";
		cur = cur->next;
	}
}
		
int SinglyLinkedList::get_value_at(int index) {
	if (length == 0 && head == nullptr) throw runtime_error("get_value_at(int): linked list is empty");
	if (index < 0 || index >= length) throw out_of_range("get_value_at(int): range out of bounds");
	Node* cur = head;
	while (index-- > 0) cur = cur->next;
	return cur->data;
}
		
void SinglyLinkedList::push_front(int data) {
	Node* newNode = new Node(data);
	if (length == 0 && head == nullptr) head = newNode;
	else {
		newNode->next = head;
		head = newNode;
	}
	length++;
}
		
void SinglyLinkedList::push_back(int data) {
	Node* newNode = new Node(data);
	if (length == 0 && head == nullptr) head = newNode;
	else {
		Node* cur = head;
		while (cur->next != nullptr) cur = cur->next;
		cur->next = newNode;
		cur = nullptr;
	}
	length++;
}
		
void SinglyLinkedList::insert_at(int pos, int data) {
	if (pos < 0 || pos > length) throw out_of_range("insert_at(int, int): range out of bounds");
	if (pos == 0) push_front(data);
	else if (pos == length) push_back(data);
	else {
		Node* front = head;
		for (int i = 1; i < pos; i++) front = front->next;
		Node* newNode = new Node(data);
		newNode->next = front->next;
		front->next = newNode;
		length++;
		front = nullptr;
	}
}
		
void SinglyLinkedList::pop_front() {
	if (length == 0 && head == nullptr) throw runtime_error("pop_front(): linked list is empty");
	Node* cur = head;
	head = head->next;
	delete cur;
	cur = nullptr;
	length--;
}
		
void SinglyLinkedList::pop_back() {
	if (length == 0 && head == nullptr) throw runtime_error("pop_back(): linked list is empty");
	if (length == 1) {
		delete head;
		head = nullptr;
	} else {
		Node* prev = head;
		while (prev->next->next != nullptr) prev = prev->next;
		delete prev->next;
		prev->next = nullptr;
		prev = nullptr;
	}
	length--;
}
		
void SinglyLinkedList::remove_at(int pos) {
	if (length == 0 && head == nullptr) throw runtime_error("remove_at(int): linked list is empty");
	if (pos < 0 || pos >= length) throw out_of_range("remove_at(int): range out of bounds");
	if (pos == 0) pop_front();
	else if (pos == length-1) pop_back();
	else {
		Node* front = head;
		for (int i = 1; i < pos; i++) front = front->next;
		Node* popNode = front->next;
		front->next = popNode->next;
		delete popNode;
		length--;
		popNode = nullptr;
		front = nullptr;
	}
}
		
int SinglyLinkedList::size() const {
	return length;
}
		
bool SinglyLinkedList::is_empty() {
	return length == 0;
}
		
//return the index of the first Node in 0-indexed that has data, or -1 if cannot find
int SinglyLinkedList::find_value(int data) {
	if (length > 0) {
		Node* cur = head;
		int index = 0;
		while (cur != nullptr) {
			if (cur->data == data) return index;
			cur = cur->next;
			index++;
		}
		cur = nullptr;
	}
	return -1;
}
		
void SinglyLinkedList::reverse() {
	if (length <= 1) return;
	Node* front = nullptr; Node* cur = head; Node* nxt = head->next;
	while (cur != nullptr) {
		cur->next = front;
		front = cur;
		cur = nxt;
		if (nxt != nullptr) nxt = nxt->next;
	}
	head = front;
	front = nullptr;
	cur = nullptr;
	nxt = nullptr;
}
		
void SinglyLinkedList::clear() {
	Node* front = head;
	while (head != nullptr) {
		head = head->next;
		delete front;
		front = head;
	}
	head = nullptr;
	length = 0;
}
