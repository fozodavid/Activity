//classes.h

#include<cstddef>

#ifndef MY_QUEUE_H
#define MY_QUEUE_H

struct Node {
	Node* next;
	int data;
	Node(){
		next=NULL;
	}
};

class Stack {
	private:
		Node* top;
	public:
		Stack();
		~Stack();
		void push(int number);
		void pop();
		void peek();
		Node* getTopNode();
};

class MyQueue {
	private:
		Stack enq;
		Stack deq;
	public:
		MyQueue();
		~MyQueue();
		void enqueue(int number);
		void dequeue();
		void test();
};

#endif