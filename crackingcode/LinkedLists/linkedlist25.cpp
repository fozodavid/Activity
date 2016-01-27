//linkedlist25.cpp

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

void printNodes(Node* &first){
	Node* current = first;
	std::cout << std::endl;
	while (current != NULL){
		std::cout << current -> data << ' ';
		current = current -> next;
	}
	std::cout << std::endl;
}

int convertListToInt(Node* head){
	int multiplier(1);
	int result(0);
	Node* current = head;
	while (current != NULL){
		result += ((current -> data) * multiplier);
		multiplier *= 10;
		current = current -> next;
	}
	return result;
}

void convertIntToList(Node* &head, int value){
	int divider(10);
	head = new Node;
	head -> data = value % (divider);
	Node* last = head;
	int digit;
	while(value/divider){
		digit = (value % (10*divider)) / divider;
		insert_node(last,digit);
		divider *= 10;
	}
}

int main(int argc, char const *argv[]){
	// two numbers are 115 and 983 result: 1098.
	Node* xhead = new Node;
	xhead -> data = 5;
	Node* xtail = xhead;
	insert_node(xtail,1);insert_node(xtail,1);
	printNodes(xhead);

	Node* yhead = new Node;
	yhead -> data = 3;
	Node* ytail = yhead;
	insert_node(ytail,8);insert_node(ytail,9);
	printNodes(yhead);

	int x = convertListToInt(xhead);
	int y = convertListToInt(yhead);
	//std::cout << x << ' ' << y << std::endl;
	Node* result = NULL;
	convertIntToList(result, (x+y));
	printNodes(result);
 	return 0;
}