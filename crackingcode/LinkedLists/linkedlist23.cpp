//linkedlist23.cpp

#include<iostream>

struct Node{
	char signature;
	Node* next = NULL;
};

void insert_node(Node* &last, char letter){
	Node* temp = new Node;
	temp -> signature = letter;
	last -> next = temp;
	last = last -> next;
}
void print_nodes(Node* &first){
	Node* current = first;
	std::cout << std::endl;
	while(current != NULL){
		std::cout << current -> signature << ' ';
		current = current -> next;
	}
	std::cout << std::endl;
}

void deleteNextNode(Node* &prev){
	Node* temp = prev -> next;
	prev -> next = prev -> next -> next;
	delete temp;
}

void deleteNode(Node* &first, char sign){
	Node* current = first;
	while(current != NULL){
		if(current -> next -> signature == sign){
			deleteNextNode(current);
			return;
		}
		current = current -> next;
	}
}

int main(int argc, char const *argv[]){
	Node* head = new Node;
	head -> signature = 'a';
	Node* last = head;
	insert_node(last,'b');insert_node(last,'c');
	insert_node(last,'d');insert_node(last,'e');
	print_nodes(head);
	deleteNode(head,'b');
	print_nodes(head);
	deleteNode(head,'c');
	print_nodes(head);
	deleteNode(head,'d');
	print_nodes(head);



	return 0;
}
