#include "dynamic_array.h"
#include <iostream>
using namespace std;

int main() {
	//DEMO
	DynamicArray myArray;
	for (int i = 0; i < 10; i++) myArray.push_back(i);
	cout << "My array: "; myArray.print(); cout << endl;
	cout << "Size of array = " << myArray.size() << endl;
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
