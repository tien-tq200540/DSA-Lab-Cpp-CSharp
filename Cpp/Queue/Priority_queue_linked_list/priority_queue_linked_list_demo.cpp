#include "priority_queue_linked_list.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	PriorityQueueLinkedList q;
	int randomWeight = -1; srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		randomWeight = (rand()%100) + 1; //random a number between 1 and 100
		cout << "Enqueue a value = " << i << " with weight = " << randomWeight << " into priority queue\n";
		q.enqueue(i, randomWeight);
	}
	cout << "Size of priority queue = " << q.size() << endl;
	cout << "Top of priority queue = " << q.top() << endl;
	cout << "Dequeue it!\n"; q.dequeue();
	cout << "Now, top of priority = " << q.top() << " and size of queue = " << q.size() << endl;
	try {
		q.clear();
	if (q.empty()) cout << "Priority queue is empty!";
	else cout << "Error! Priority queue is not empty!";
	cout << endl;
	q.enqueue(100, 0);
	q.enqueue(50);
	cout << "---Demo for enqueue with no weight input!----\n";
	cout << "Top = " << q.top() << endl; cout << "Dequeue!\n"; q.dequeue();
	cout << "Now top = " << q.top();
	} catch (exception& e) {
		cout << "Caught: " << e.what();
	}
	return 0;
}
