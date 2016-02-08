//bst_traversal.cpp
#include<iostream>
#include<queue>

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
	} else if(root -> data < number){
		insert_node(root -> right, number);
	} else {
		insert_node(root -> left , number);
	}
}

void inOrderTraversal(Node* root){
	if(root == NULL){
		return;
	} else {
		//in order: left, visit, right
		inOrderTraversal(root -> left);
		std::cout << root -> data << ' ';
		inOrderTraversal(root -> right);
	}
}

void levelOrderTraversal(Node* root){
	if(root == NULL){
		return;
	}
	std::queue<Node*> Q;
	Q.push(root);
	while(!Q.empty()){
		Node* current = Q.front();
		std::cout << current -> data << ' ';
		if(current -> left != NULL)  Q.push(current -> left);
		if(current -> right != NULL) Q.push(current -> right);
		Q.pop();
	}
}

int FindHeight(Node* root){
	if(root == NULL){
		return -1;
	} else {
		int leftHeight  = FindHeight(root -> left);
		int rightHeight = FindHeight(root -> right);
		return leftHeight < rightHeight ? rightHeight+1 : leftHeight+1;
	}
}

int main(int argc, char const *argv[]){
	Node* rootPtr = NULL;
	insert_node(rootPtr,5);insert_node(rootPtr,8);insert_node(rootPtr,7);
	insert_node(rootPtr,1);insert_node(rootPtr,3);
	insert_node(rootPtr,4);insert_node(rootPtr,6);insert_node(rootPtr,2);
	inOrderTraversal(rootPtr);
	int height = FindHeight(rootPtr);
	std::cout << std::endl << height << std::endl;
	levelOrderTraversal(rootPtr);
	return 0;
}

/*
      5
   1      8
     3   7
    2 4 6
*/