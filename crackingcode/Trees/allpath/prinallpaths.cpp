//prinallpaths.cpp
#include<iostream>


struct Node{
	Node* left;
	Node* right;
};

Node* createNode(){
	Node* temp = new Node;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
}

void insert_path(Node* root, char sequence[], int index, const int limit) {
	//std::cout << "Doing from index: " << index << std::endl;
	Node* current = root;
	int newlimit = index + limit;
	while(index < newlimit){
		if(sequence[index] == '0'){
	//		std::cout << '0';
			if(current -> left != NULL){
				current = current -> left;
			} else {
				current -> left = createNode();
				current = current -> left;
			}
		} else if (sequence[index] == '1'){
	//		std::cout << '1';
			if(current -> right != NULL){
				current = current -> right;
			} else {
				current -> right = createNode();
				current = current -> right;
			}
		}
		++index;
	}
	//std::cout << std::endl;
}

void traverse(Node* root){
	Node* current = root;
	while (current != NULL){
		if(current-> left != NULL){
			std::cout << '0';
			current = current -> left;
		} else {
			std::cout << '1';
			current = current -> right;
		}
	}
}
void printAllFromRoot(Node* root, int &pathIndex,char path[], int limit){
	Node* current = root;
	if (current -> left == NULL && current -> right == NULL){
		int i;
		for (i=0;i<limit;++i){
			std::cout << path[i];
		}
			std::cout << std::endl;
			--pathIndex;
			return;
	}
	if(current -> left != NULL){
		path[pathIndex] = '0';
		++pathIndex;
		printAllFromRoot(root -> left, pathIndex,path, limit);
	}
	if(current -> right != NULL){
		path[pathIndex] = '1';
		++pathIndex;
		printAllFromRoot(root -> right,pathIndex,path, limit);
	}
	--pathIndex;
}
int countLeaves(Node* node){
  if(node == NULL)
    return 0;
  if(node -> left == NULL && node -> right == NULL ) {
    return 1;
  } else {
    return countLeaves(node -> left) + countLeaves(node -> right);
  }
}

int main(int argc, char const *argv[]) {
	const int sequenceLength(61);
	char sequence[sequenceLength] = "010111000101011110101010110110100101011111010101010111110101";
	const int limit(6);
	char path[limit];
	int pathIndex(0);

	Node* root = createNode();
	Node* current = root;
	int i;
	for (i = 0; i <sequenceLength-limit;++i){
		insert_path(root,sequence,i,limit);
	}

	printAllFromRoot(root,pathIndex,path,limit);
	int leftside  = countLeaves(root-> left);
	int rightside = countLeaves(root-> right);
	std::cout << "0: " << leftside << std::endl;
	std::cout << "1: " << rightside << std::endl;
	return 0;
}
