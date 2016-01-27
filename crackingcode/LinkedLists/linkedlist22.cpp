//linkedlist22.cpp

#include<iostream>

struct Node {
	int data;
	Node* next = NULL;
};

void insert_node(Node* &last, int number){
	Node* temp = new Node;
	temp -> data = number;
	last -> next = temp;
	last = last -> next;
}

void print_nodes(Node* &first){
	Node* current = first;
	std::cout << std::endl;
	while (current != NULL){
		std::cout << current -> data << ' ';
		current = current -> next;
	}
	std::cout << std::endl;
}

Node* kthToLast(Node* first, int index){
	int lastIndex(0);
	Node* scan = first;
	while(scan != NULL){
		scan = scan -> next;
		++lastIndex;
	}
	scan = first;
	int counter(0);
	while(counter < (lastIndex-index-1)){
		scan = scan -> next;
		++counter;
	}
	return scan;
}

int main(int argc, char const *argv[]){
	Node* head = new Node;
	head -> data = 0;
	Node* last = head;
	int i;
	int limit = 7;
	for (i = 1; i < limit; ++i)	{
		insert_node(last,i);
	}

	print_nodes(head);
	for (i = 0; i < limit; ++i)	{
		std::cout << "kth index: " << i << std::endl;
		Node* kth = kthToLast(head,i);
		std::cout << "result: " << kth -> data << std::endl;
	}

	return 0;
}