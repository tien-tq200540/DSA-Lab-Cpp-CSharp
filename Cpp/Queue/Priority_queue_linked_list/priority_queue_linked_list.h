#include "../IQueue.h"

#ifndef PRIORITY_QUEUE_LINKED_LIST
#define PRIORITY_QUEUE_LINKED_LIST

struct Node {
	int data;
	Node* next;
	int weight;
	
	public:
		Node(int data, int weight) : data(data), weight(weight), next(nullptr){}
};

class PriorityQueueLinkedList : public IQueue {
	protected:
		Node* head;
		Node* tail;
	
	public:
		PriorityQueueLinkedList();
		PriorityQueueLinkedList(int cap);
		~PriorityQueueLinkedList();
		int size() const override;
		int get_capacity() const override;
		
		void clear() override;
		bool empty() const override;
		bool contains(int value) const override;
		
		void enqueue(int value) override;
		int dequeue() override;
		int top() const override;
		
		//New enqueue version for Priority queue
		void enqueue(int value, int weight);
};

#endif
