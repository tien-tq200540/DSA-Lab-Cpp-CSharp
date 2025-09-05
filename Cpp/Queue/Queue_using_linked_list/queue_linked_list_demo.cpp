#include "queue_linked_list.h"
#include <iostream>
using namespace std;

int main() {
	QueueLinkedList q;
	for (int i = 0; i < 10; i++) {
		cout << "Enqueue value = " << i << " into queue\n";
		q.enqueue(i);
	}
	cout << "Queue size = " << q.size() << endl;
	cout << "Queue top = " << q.top() << endl;
	cout << "Dequeue it!\n"; q.dequeue();
	cout << "Now queue top = " << q.top() << endl;
	q.clear();
	if (q.empty()) cout << "After clear, queue is empty!";
	else cout << "Error! Queue is not empty!";
	cout << endl;
	
	q.enqueue(125);
	cout << "Enqueue, now queue top = " << q.top();
	return 0;
}
