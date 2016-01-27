//linkedlist26.cpp

#include<iostream>

struct Node{
	Node* next = NULL;
	int data;
};

void insert_node(Node* &last, int number){
	Node* temp = new Node;
	temp -> data = number;
	last -> next = temp;
	last = last -> next;
}

void printNodes(Node* head){
	Node* current = head;
	std::cout << std::endl;
	while(current != NULL){
		std::cout << current -> data << ' ';
	}
	std::cout << std::endl;
}
int hash(int x){
	return x;
}

Node* findCircularStart(Node* head){
	const int size(32);
	Node* current = head;
	Node* array[size] = { 0 };
	while(current != NULL){
		int hashvalue = hash(current -> data);
		if(array[hashvalue]){
			return current;
		} else {
			++array[hashvalue];
		}
		current = current -> next;
	}
}

int main(int argc, char const *argv[]){
	Node* head = new Node;
	head -> data = 1;
	Node* last = head;
	insert_node(last,2);insert_node(last,3);insert_node(last,4);
	insert_node(last,5);insert_node(last,6);insert_node(last,3);
	Node* result = findCircularStart(head);
	std::cout << result -> data;
	return 0;
}