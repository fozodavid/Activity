//trees41.cpp

#include<iostream>

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int number){
	Node* temp = new Node;
	temp -> data = number;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

void insert_node(Node* &root, int number){
	if(root == NULL){
		root = createNode(number);
	} else if (number < root -> data){
		insert_node(root -> left, number);
	} else {
		insert_node(root -> right, number);
	}
}
int abs( int number){
	if (number < 0){
		return -number;
	} else {
		return number;
	}
}

int FindHeight(Node* root){
	if (root == NULL){
		return -1;
	} else {
		int leftheight = FindHeight(root -> left);
		int rightheight = FindHeight(root -> right);
		if(abs(leftheight - rightheight) > 1){
			return -10;
		} else if(leftheight == -10 || rightheight == -10){
			return -10;
		} else {
			return leftheight < rightheight ? rightheight+1 : leftheight+1;
		}
	}
}


bool Ifbalanced(Node* root){
	int result = FindHeight(root);
	if (result == -10) return false;
	else return true;
}
void InOrderTraversal(Node* root) {
	if (root == NULL){
		return;
	}
	InOrderTraversal(root-> left);
	std::cout << root -> data << ' ';
	InOrderTraversal(root-> right);
}

int main(int argc, char const *argv[]) {
	Node* rootPtr = NULL;
	insert_node(rootPtr,1);
	bool balanced = Ifbalanced(rootPtr);
	std::cout << balanced << std::endl;
	insert_node(rootPtr,2);
	balanced = Ifbalanced(rootPtr);
	std::cout << balanced << std::endl;
	insert_node(rootPtr,3);
	balanced = Ifbalanced(rootPtr);
	std::cout << balanced << std::endl;
	insert_node(rootPtr,4);
	balanced = Ifbalanced(rootPtr);
	std::cout << balanced << std::endl;
	insert_node(rootPtr,5);
	balanced = Ifbalanced(rootPtr);
	std::cout << balanced << std::endl;
	int height = FindHeight(rootPtr);
	std::cout << height << std::endl;
	InOrderTraversal(rootPtr);
	return 0;
}
