#ifndef ISTACK_H
#define ISTACK_H

class IStack {
	public:
		IStack() = default;
		virtual ~IStack() = default;
		IStack(const IStack& other) = delete;
		IStack& operator = (const IStack& other) = delete;
		IStack(IStack&& other) = delete;
		IStack& operator=(IStack&& other) = delete;

		virtual int size() const = 0;
		virtual void clear() = 0;
		virtual bool empty() const = 0;
		virtual bool contains(int value) const = 0;
		
		virtual void push(int value) = 0;
		virtual int pop() = 0;
		virtual int top() const = 0;
};

#endif
