#include "../IStack.h"
#include "../../Array/dynamic_array.h"

#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

class StackArray : public IStack {
	protected:
		DynamicArray data;
		
	public:
    StackArray();

    int size() const override;
    void clear() override;
    bool empty() const override;
    bool contains(int value) const override;
    void push(int value) override;
    int pop() override;
    int top() const override;
};

#endif
