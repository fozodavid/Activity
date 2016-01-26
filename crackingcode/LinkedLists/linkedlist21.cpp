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
void delete_node(Node* &prev, Node* &fast){
	Node* temp = prev -> next;
	//if it is not the last
	if (fast -> next) {
		fast = fast -> next;
	//if it is the last
	} else if(!(fast -> next)){
		fast = NULL;
	}
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
		Node* fast = base -> next;
		Node* slow = base;
		while(fast -> next != NULL){
			if (fast -> data == base -> data){
				delete_node(slow, fast);
			} else {
			fast = fast -> next;
			slow = slow -> next;
			}
		}
		base = base -> next;
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
	insert_node(3,last);insert_node(2,last);insert_node(10,last);
	insert_node(8,last);insert_node(8,last);insert_node(8,last);
	print_nodes(head);

	delete_duplicates(head);
	print_nodes(head);

	return 0;
}