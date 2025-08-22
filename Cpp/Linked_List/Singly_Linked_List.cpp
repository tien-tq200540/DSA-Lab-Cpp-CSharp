#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next = NULL;
};

void print(Node* head) {
	Node* cur = head;
	while (cur != NULL) {
		cout << cur->data << "-->";
		cur = cur->next;
	}
	cout << endl;
}

Node* insertNode(Node* head, int data, int pos) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	
	if (head == NULL) head = newNode;
	else if (pos == 1) {
		newNode->next = head;
		head = newNode;
	} else {
		Node* cur = head;
		while (pos > 2 && cur->next != NULL) {
			cur = cur->next;
			pos--;
		}
		
		newNode->next = cur->next;
		cur->next = newNode;
	}
	
	return head;	
}

int main() {
	Node* head = NULL;
	Node* cur;
	for (int i = 0; i < 10; i++) {
		Node* newNode = new Node();
		newNode->data = i;
		newNode->next = NULL;
		
		if (head == NULL) {
			head = newNode;
			cur = head;
		} else {
			cur->next = newNode;
			cur = cur->next;
		}
	}
	
	print(head);
	head = insertNode(head, 11, 1);
	print(head);
	return 0;
}
