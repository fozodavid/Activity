//stack6.cpp

#include<iostream>

struct Node {
	Node* next = NULL;
	int data;
};

class Stack {
	Node* top  = NULL;

	public:
		static int m_test_id;
		void push(int number);
		void pop ();
		void peek();
		void test(int count);
};

void Stack::push(int number){
	Node*   temp = new Node;
	temp -> data = number;
	temp -> next = top;
	top  = temp;
}

void Stack::pop (){
	if (top != NULL){
		Node* temp = top;
		top = top -> next;
		delete temp;
	} else {
		std::cout << "Cannot pop." << std::endl;
	}
}

void Stack::peek(){
	if (top != NULL){
		std::cout << top -> data << ' ';	 //<< std::endl;
	} else {
		std::cout << "Empty stack." << std::endl;
	}
}

void Stack::test(int count){
	std::cout 	<< std::endl << "TEST " << m_test_id++
				<< " Commencing..." << std::endl << std::endl;
	int i;
	for (i = 0; i < count; ++i){
		push(i); peek();
	}
	for (i = 0; i < count; ++i){
		pop();   peek();
	}
	std::cout << std::endl << "Done." << std::endl << std::endl;
}

int Stack::m_test_id(0);

int main(int argc, char const *argv[]){

	Stack myStack;
	myStack.test(21);
	myStack.test(11);
	myStack.test( 6);

	return 0;
}