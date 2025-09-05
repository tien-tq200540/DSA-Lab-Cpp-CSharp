#include "../IQueue.h"

#ifndef QUEUE_LINKED_LIST
#define QUEUE_LINKED_LIST

struct Node {
	int data;
	Node* next;
	
	public:
		Node() : data(0), next(nullptr){}
		Node(int val) : data(val), next(nullptr){}
};

class QueueLinkedList : public IQueue {
	protected:
		Node* head;
		Node* tail;
		
	public:
		QueueLinkedList();
		QueueLinkedList(int cap);
		~QueueLinkedList();
		
		int size() const override;
		int get_capacity() const override;
		
		void clear() override;
		bool empty() const override;
		bool contains(int value) const override;
		
		void enqueue(int value) override;
		int dequeue() override;
		int top() const override;
};

#endif
