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
	return 0;
}
