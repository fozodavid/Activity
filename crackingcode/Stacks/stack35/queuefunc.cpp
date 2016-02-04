//queuefunc.cpp
#include<iostream>
#include "classes.h"

MyQueue::MyQueue(){}

MyQueue::~MyQueue(){

}

void MyQueue::enqueue(int number){
	if(enq.getTopNode() == NULL){
		enq.push(number);
		deq.push(number);
	} else {
		enq.push(number);
		//put number to the bottom of stack
		Node* current = deq.getTopNode();
		while (current -> next != NULL){
			current = current -> next;
		}
		current -> next = new Node;
		current -> next -> data = number;
	}
}

void MyQueue::dequeue(){
	if(enq.getTopNode() == NULL){
		std::cout << "Empty queue" << std::endl;
		return;
	} else if ((enq.getTopNode() -> next) == NULL){
		deq.peek();
		enq.pop();
		deq.pop();
	} else {
		deq.peek();
		deq.pop();
		//update enq
		Node* temp = enq.getTopNode();
		while (temp -> next -> next != NULL){
			temp = temp -> next;
		}
		delete (temp -> next);
		temp -> next = NULL;
	}
}

void MyQueue::test(){
	enqueue(1);	enqueue(2);	enqueue(3);
	enqueue(4);	enqueue(5);
	dequeue();  dequeue();  dequeue(); dequeue();  dequeue();  dequeue();
	enqueue(1); enqueue(2); enqueue(3);
	dequeue();  dequeue();  dequeue();  dequeue();
}