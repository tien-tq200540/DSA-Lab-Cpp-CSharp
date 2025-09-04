#include "queue_array.h"
#include <iostream>
using namespace std;

int main() {
	QueueArray q;
	for (int i = 0; i < 10; i++) {
		cout << "Enqueue value = " << i << " into queue\n";
		q.enqueue(i);
	}
	
	cout << "Queue length = " << q.size() << endl;
	cout << "Top queue = " << q.top() << endl;
	cout << "Pop it!\n"; q.dequeue();
	cout << "Now, top queue = " << q.top() << endl;
	q.clear();
	if (q.empty()) cout << "Now queue is emtpy!\n";
	else cout << "Error! Queue is not empty!\n";
	q.enqueue(100);
	cout << "Top value after clear and enqueue a demo value = " << q.top();
	return 0;
}
