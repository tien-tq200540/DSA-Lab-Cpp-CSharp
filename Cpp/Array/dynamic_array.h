#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

struct DynamicArray {
	private:
		int* data;
		int length;
		int capacity;
	
	public:
		DynamicArray();
		~DynamicArray();
		DynamicArray(const DynamicArray& other);
		DynamicArray& operator = (DynamicArray& other);
		int size() const;
		int get_capacity() const;
		void push_back(int value);
		int pop_back();
		int get_value_at(int index) const;
		void set_value_at(int index, int value);
		void print();
		void clear();
		int get_min();
		int get_max();
		void reverse();
		void rotate(int step);
		
		// TODO: implement insert_at and remove_at after linked list, stack, queue and dequeue
};

#endif
