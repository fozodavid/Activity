//queue4.cpp

#include<iostream>

struct Node {
	Node* next = NULL;
	int data;
};

class Queue {
	Node* first = NULL;
	Node* last  = NULL;

	public:
		static int id_generator;
		void enqueue(int number);
		void dequeue();
		void test(int count);
};

void Queue::enqueue(int number){
	if (first == NULL){
		first = new Node;
		first -> data = number;
		last = first;
	} else {
		last -> next = new Node;
		last -> next -> data = number;
		last = last -> next;
	}
}
void Queue::dequeue(){
	if (first != NULL){
		Node* temp = first;
		first = first -> next;
		if((temp -> data)%20 == 0) std::cout << std::endl;
		std::cout << temp -> data << ' ';
		delete temp;
	} else {
		first = last;
	}
}
void Queue::test(int count){
	int i;
	std::cout << std::endl << "Test " << id_generator++ << " commencing..." << std::endl;
	for (i = 0; i < count; ++i)	{
		enqueue(i);
	}
	for (i = 0; i < count; ++i)	{
		dequeue();
	}
	std::cout << std::endl << "Done" << std::endl;
}

int Queue::id_generator(0);

int main(int argc, char const *argv[]) {
	Queue myQueue;
	myQueue.test(800);

	return 0;
}