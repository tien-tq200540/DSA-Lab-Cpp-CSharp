#include "../IStack.h"
#include "../../Linked_List/singly_linked_list.h"

#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

class StackLinkedList : public IStack {
	protected:
		SinglyLinkedList data;
		
	public:
    StackLinkedList();

    int size() const override;
    void clear() override;
    bool empty() const override;
    bool contains(int value) const override;
    void push(int value) override;
    int pop() override;
    int top() const override;
};

#endif
