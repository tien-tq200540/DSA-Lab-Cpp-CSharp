#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int val, Node* nxt = nullptr) : data(val), next(nxt) {}

    Node(const Node& other) = delete;
    Node& operator=(const Node& other) = delete;
};

struct SinglyLinkedList {
	private:
		Node* head;
		int length;
	
	public:
		SinglyLinkedList() {
			head = NULL;
		}
		
		~SinglyLinkedList() {
			//delete all nodes in list
			
		}
		
		SinglyLinkedList(const SinglyLinkedList& other) {
			head = NULL;
		}
		
		SinglyLinkedList& operator = (const SinglyLinkedList& other) {
			head = NULL;
		}
		
		void print_list() {
			
		}
		
		void get_value_at(int index) {
			
		}
		
		void push_front(int data) {
			
		}
		
		void push_back(int data) {
			
		}
		
		void insert_at(int pos, int data) {
			
		}
		
		void pop_front() {
			
		}
		
		void pop_back() {
			
		}
		
		void remove_at(int pos) {
			
		}
		
		int size() {
			return 0;
		}
		
		bool is_empty() {
			return false;
		}
		
		//return the index of the first Node in 0-indexed that has data, or -1 if cannot find
		int find_value(int data) {
			return -1;
		}
		
		void reverse() {
			
		}
		
		void clear() {
			
		}
};


int main() {
	SinglyLinkedList myList;
	
	return 0;
}
