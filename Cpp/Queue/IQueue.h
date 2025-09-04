#ifndef IQUEUE_H
#define IQUEUE_H

class IQueue {
	protected:
		int length;
		int capacity;
	public:
		IQueue() = default;
		virtual ~IQueue() = default;
		IQueue(const IQueue& other) = delete;
		IQueue& operator = (const IQueue& other) = delete;
		IQueue(IQueue&& other) = delete;
		IQueue& operator=(IQueue&& other) = delete;
		
		virtual int size() const = 0;
		virtual int get_capacity() const = 0;
		
		virtual void clear() = 0;
		virtual bool empty() const = 0;
		virtual bool contains(int value) const = 0;
		
		virtual void enqueue(int value) = 0;
		virtual int dequeue() = 0;
		virtual int top() const = 0;
};

#endif
