//bst1.cpp

#include<iostream>

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int number) {
	Node* temp = new Node;
	temp -> left = NULL;
	temp -> right = NULL;
	temp -> data = number;
	return temp;
}

void insert_node(Node* &root, int number){
	if (root == NULL){
		root = createNode(number);
	} else if (root-> data < number){
		insert_node(root-> right, number);
	} else {
		insert_node(root->  left, number);
	}
}

bool search_node(Node* &root, int number){
	if(root == NULL){
		std::cout << "not there." << std::endl;
		return false;
	} else if (root -> data == number){
		std::cout << "found it." << std::endl;
		return true;
	} else if (root -> data < number){
		search_node(root-> right, number);
	} else {
		search_node(root-> left, number);
	}
}

int heightOfTree(Node* root){
	if(root == NULL) {
		return -1;
	} else {
		int leftHeight  = heightOfTree(root -> left);
		int rightHeight = heightOfTree(root -> right);
		return leftHeight < rightHeight ? rightHeight+1 : leftHeight+1;
	}
}


int main(int argc, char const *argv[]) {
	Node* rootPtr = NULL;
	insert_node(rootPtr, 5);
	insert_node(rootPtr, 2);
	insert_node(rootPtr, 1);
	insert_node(rootPtr, 7);
	insert_node(rootPtr, 8);
	int i;
	for (int i = 1; i <= 10; ++i)	{
		search_node(rootPtr,i);
	}
	//1 1 0 0 1 0 1 1 0 0
	int height = heightOfTree(rootPtr);
	std::cout << std::endl << "Height: " << height << std::endl;
	return 0;
}