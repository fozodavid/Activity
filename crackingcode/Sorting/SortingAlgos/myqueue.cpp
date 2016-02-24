//myqueue.cpp

#include "myqueue.h"
#include <cstdlib>

myRadixQueue::myRadixQueue(int a_size){
	size = a_size;
	array = new Node*[size];
	for (int i = 0; i < size; ++i) {
		array[i] = NULL;
	}
}

myRadixQueue::~myRadixQueue(){
	delete array;
}

void myRadixQueue::enqueue(int key, int number){
	//find end of queue
	Node* temp = array[key];
	if (notEmpty(key)) {
		while (temp -> next != NULL) {
			temp = temp -> next;
		}
		temp -> next = new Node;
		temp -> next -> data = number;
		temp -> next -> next = NULL;
	} else {
		temp = new Node;
		temp -> next = NULL;
		temp -> data = number;
		array[key] = temp;
	}

}

int myRadixQueue::dequeue(int key){
	Node* temp = array[key];
	if (temp != NULL){
		int result = temp -> data;
		array[key] = temp -> next;
		delete temp;
		return result;
	} else {
		return 0;
	}
}

bool myRadixQueue::notEmpty(int key) {
	if(array[key] == NULL){
		return false;
	} else {
		return true;
	}
}