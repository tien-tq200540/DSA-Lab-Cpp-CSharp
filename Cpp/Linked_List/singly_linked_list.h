#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

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
		SinglyLinkedList();
		~SinglyLinkedList();
		SinglyLinkedList(const SinglyLinkedList& other);
		SinglyLinkedList& operator = (const SinglyLinkedList& other);
		void print_list();
		int get_value_at(int index) const;
		void push_front(int data);
		void push_back(int data);
		void insert_at(int pos, int data);
		void pop_front();
		void pop_back();
		void remove_at(int pos);
		int size() const;
		bool is_empty();
		int find_value(int data);
		void reverse();
		void clear();
};

#endif
