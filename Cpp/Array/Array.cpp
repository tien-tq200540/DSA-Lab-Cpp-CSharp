#include <iostream>
#include <stdexcept>
using namespace std;

struct DynamicArray {
	private:
		int* data;
		int length;
		int capacity;
	
	public:
		DynamicArray() {
			length = 0;
			capacity = 1000;
			data = new int[capacity];
		}
		
		~DynamicArray() {
			delete[] data;
			data = nullptr;
		}
		
		DynamicArray(const DynamicArray& other) {
			length = other.length;
			capacity = other.capacity;
			data = new int[capacity];
			for (int i = 0; i < length; i++) data[i] = other.data[i];
		}
		
		DynamicArray& operator = (DynamicArray& other) {
			if (this != &other) {
				delete[] data;
				length = other.length;
				capacity = other.capacity;
				data = new int[capacity];
				for (int i = 0; i < length; i++) data[i] = other.data[i];
			}
			return *this;
		}
		
		void push_back(int value) {
			if (length >= capacity) {
				capacity *= 2;
				int* newData = new int[capacity];
				for (int i = 0; i < length; i++) newData[i] = data[i];
				delete[] data;
				data = newData;
			}
			
			data[length++] = value;
		}
		
		int pop_back() {
			if (length == 0) throw runtime_error("Array is empty");
			return data[--length];
		}
		
		int get_value_at(int index) {
			if (index < 0 || index >= length) throw out_of_range("get_value_at(int): index is out of range");
			return data[index];
		}
		
		void print() {
			for (int i = 0; i < length; i++) cout << data[i] << " ";
		}
		
		void clear() {
			delete[] data;
			data = new int[capacity];
			length = 0;
		}
		
		int get_min() {
			if (length == 0) throw runtime_error("Array is empty");
			int min = data[0];
			for (int i = 1; i < length; i++) {
				if (data[i] < min) min = data[i];
			}
			return min;
		}
		
		int get_max() {
			if (length == 0) throw runtime_error("Array is empty");
			int max = data[0];
			for (int i = 1; i < length; i++) {
				if (data[i] > max) max = data[i];
			}
			return max;
		}
		
		void reverse() {
			for (int i = 0; i < length/2; i++) {
				int tmp = data[i];
				data[i] = data[length-1 - i];
				data[length-1 - i] = tmp;
			}
		}
		
		// TODO: optimize rotate later
		void rotate(int step) {
			if (step < 0) throw invalid_argument("rotate(int): invalid step");
			step %= length;
			if (step == 0) return;
			while (step > 0) {
				int tmp = data[length-1];
				for (int i = length-1; i > 0; i--) data[i] = data[i-1];
				data[0] = tmp;
				step--;
			}
		}
		
		// TODO: implement insert_at and remove_at after linked list, stack, queue and dequeue
};

int main() {
	//DEMO
	DynamicArray myArray;
	for (int i = 0; i < 10; i++) myArray.push_back(i);
	cout << "My array: "; myArray.print(); cout << endl;
	cout << "Min = " << myArray.get_min() << " and max = " << myArray.get_max() << endl;
	
	cout << "--- Reverse ---\n"; 
	myArray.reverse();
	cout << "After reverse, my array: "; myArray.print(); cout << endl;
	myArray.reverse();
	cout << "Reverse again to get old array: "; myArray.print(); cout << endl;
	
	try {
		cout << "--- Rotate ---\n";
		myArray.rotate(5);
		cout << "After rotate, my array: "; myArray.print(); cout << endl;
	} catch (exception& e) {
		cout << "Caught: " << e.what() << endl;
	}
	return 0;
}
