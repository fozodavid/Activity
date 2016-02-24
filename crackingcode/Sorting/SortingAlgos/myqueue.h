//myqueue.h

#ifndef MYQUEUE_H
#define MYQUEUE_H

struct Node {
	int data;
	Node* next;
};

class myRadixQueue {
private:
	int size;
	Node **array;
public:
	myRadixQueue(int a_size);
	~myRadixQueue();
	void enqueue(int key, int number);
	int dequeue(int key);
	bool notEmpty(int key);
};

#endif