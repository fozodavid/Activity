//linkedlist21.cpp
#include<iostream>

struct Node{
	Node* next = NULL;
	int data;
};

void insert_node(int digit, Node* &last){
	Node* temp = new Node;
	temp -> data = digit;
	last -> next = temp;
	last = last  -> next;
}
void delete_node(Node* &prev){
	Node* temp = prev -> next;
	//if not the last
	if (prev -> next -> next){
		prev -> next = prev -> next -> next;
	//if it is the last
	} else {
		prev -> next = NULL;
	}
	delete temp;
}

void delete_duplicates(Node* first){
	Node* base = first;
	while (base -> next != NULL){
		Node* current = base;
		while(current -> next != NULL){
			if (current -> next -> data == base -> data){
				delete_node(current);
				//current = current -> next;
			} else {
			current = current -> next;
			}
		}
		if (base -> next){
			base = base -> next;
		}
	}
}

void print_nodes(Node* first){
	Node* current = first;
	while (current != NULL){
	std::cout << current -> data << ' ';
	current = current -> next;
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	Node* head = new Node;
	head -> data = 10;
	Node* last = head;
	insert_node(1,last);insert_node(1,last);insert_node(1,last);
	insert_node(3,last);insert_node(2,last);insert_node(1,last);
	insert_node(8,last);insert_node(8,last);insert_node(10,last);

	print_nodes(head);
	delete_duplicates(head);
	print_nodes(head);

	return 0;
}