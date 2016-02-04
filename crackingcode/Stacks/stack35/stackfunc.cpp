//stackfunc.cpp
#include "classes.h"
#include<iostream>


Stack::Stack(){
	top = NULL;
}
Stack::~Stack(){
	while(top!=NULL){
		pop();
	}
}

void Stack::push(int number){
	Node* temp = new Node;
	temp -> data = number;
	temp -> next = top;
	top = temp;
}

void Stack::pop(){
	if(top!=NULL){
		Node* temp = top;
		top = top -> next;
		delete temp;
	} else {
		std::cout<< "cannot pop" << std::endl;
	}
}

void Stack::peek(){
	if(top!=NULL){
		std::cout << top -> data << std::endl;
	} else {
		std::cout << "empty stack" << std::endl;
	}
}

Node* Stack::getTopNode(){
	return top;
}