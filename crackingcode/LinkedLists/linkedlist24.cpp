//linkedlist24.cpp

#include<iostream>

struct Node{
	Node* next = NULL;
	int data;
};

void insert_node(Node* &endnode, int number){
	Node* temp = new Node;
	temp -> data = number;
	endnode -> next = temp;
	endnode = endnode -> next;
}

void printNodes(Node* first){
	Node* current = first;
	std::cout << std::endl;
	while (current != NULL){
		std::cout << current -> data << ' ';
		current = current -> next;
	}
	std::cout << std::endl;
}
void partitionX(Node* &head, int value){
	Node* firstHead  = NULL;
	Node* firstLast  = NULL;
	Node* secondHead = NULL;
	Node* secondLast = NULL;

	while (head != NULL){
		//if data is smaller than value it moves to firstHead linked list
		if(head -> data < value){
			if(!firstHead){
				firstHead = head;
			}
			firstLast  = head;
		//else it moves to secondHead linked list
		} else {
			if(!secondHead){
				secondHead = head;
			}
			secondLast = head;
		}
		//get next element
		if(head -> next){
			head = head -> next;
		//if it is the last
		} else {
			head = NULL;
			secondLast -> next = NULL;
		}
	}
	//merge the two list together
	if(firstLast){
		firstLast -> next = secondHead;
		head = firstHead;
	} else {
		head = secondHead;
	}
}


int main(int argc, char const *argv[])
{
	Node* head = new Node;
	head -> data = 8;
	Node* last = head;
	int i;
	for (i = 7; i > 0; --i){
		insert_node(last,i);
	}
	int x = 4;
	printNodes(head);
	partitionX(head, x);
	printNodes(head);
	return 0;
}