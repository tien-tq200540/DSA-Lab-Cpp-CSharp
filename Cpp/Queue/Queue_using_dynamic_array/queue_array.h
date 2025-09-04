#include "../IQueue.h"

#ifndef QUEUE_ARRAY
#define QUEUE_ARRAY

class QueueArray : public IQueue {
	protected:
		int* data;
		int head; int tail;
		
	public:
		QueueArray();
		QueueArray(int cap);
		~QueueArray();
		
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
