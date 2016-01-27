//linkedlist27.cpp

#include<iostream>

struct Node{
	Node* next = NULL;
	char sign;
};

void insert_node(Node* &tail, char letter){
	Node* temp = new Node;
	temp -> sign = letter;
	tail -> next = temp;
	tail = tail -> next;
}

void printNodes(Node* head){
	Node* current = head;
	std::cout << std::endl;
	while(current != NULL) {
		std::cout << current -> sign << ' ';
		current = current -> next;
	}
	std::cout << std::endl;
}

char kthToLast(Node* head, int k, int length){
	Node* current = head;
	int count(0);
	int limit = length - k -1;
	while(count < limit){
		current = current -> next;
		++count;
	}
	return current -> sign;
}

bool isPalindrome(Node* head,int length){
	Node* current = head;
	int count(0);
	int limit = length/2;
	while(count <= limit){
		char k = kthToLast(head,count,length);
		if(k != current -> sign){
			return false;
		}
		current = current -> next;
		++count;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	Node* head = new Node;
	head -> sign = 'a';
	Node* last = head;
	insert_node(last,'b');
	insert_node(last,'c');
	insert_node(last,'b');
	insert_node(last,'a');
	printNodes(head);
	const int length(5);
	bool result = isPalindrome(head,length);
	std::cout << result;
	return 0;
}