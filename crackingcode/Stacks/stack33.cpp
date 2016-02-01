//stack33.cpp
#include<iostream>

struct Node {
	Node* next = NULL;
	int data;
};

struct BaseNode {
	Node* top  = NULL;
	int count;
};

class SetOfStacks{

	int column;
	const int size;
	const int limit;
	BaseNode* array = NULL;
	Node* top = NULL;

	public:
		SetOfStacks(): column(0), limit(5), size(5) {
			array = new BaseNode[size];
			Node* top = array[0].top;
			int k;
			for (k = 0; k < size; ++k)			{
				array[k].count = 0;
			}
		}
		~SetOfStacks(){
			delete array;
		}
		static int id_generator;
		void push(int number);
		void pop ();
		void popAt(int index);
		void peek();
		void test();
};

int  SetOfStacks::id_generator(0);

void SetOfStacks::push(int number){
	//if it is full
	if(column == size-1 && array[column].count == limit){
		std::cout << "Full Stack" << std::endl;
		return;
	}
	//node generation
	Node* temp = new Node;
	temp -> next = top;
	temp -> data = number;
	//if needs to open new stack
	if (array[column].count == limit && column < size){
		array[++column].top = temp;
		top = array[column].top;
	} else {
		top = temp;
	}
	++array[column].count; //update count
}
void SetOfStacks::pop (){
	//if empty
	if(array[0].count == 0){
		std::cout << "Cannot pop" << std::endl;
		return;
	}
	Node* temp = top;
	top = top -> next;
	delete temp;
	--array[column].count;
	if(array[column].count == 0 && column > 0){
		--column;
	}
}
void SetOfStacks::popAt(int index){
	if (index > column){
		std::cout << "Cannot pop there." << std::endl;
		return;
	} else if(index == column){
		pop();
		std::cout << "Pop at col: " << index << std::endl;
	} else if(index < column && index >= 0){
		Node* temp = array[index+1].top -> next;
		std::cout 	<< "PopAt:: col: " << index << ' '
					<< "ctn: " << array[index].count << ' '
					<< temp -> data << " deleted" << std::endl;
		array[index+1].top -> next = array[index+1].top -> next -> next;
		delete temp;
		--array[index].count;
	} else {
		std::cout << "Impossible to pop" << std::endl;
		return;
	}

}
void SetOfStacks::peek(){
	if (top == NULL){
		std::cout << "Peek: Empty Stack" << std::endl;
	} else {
		std::cout   << "col: "     << column << ' '
					<< "ctn: "     << array[column].count << ' '
					<< top -> data << std::endl;
	}
}

void SetOfStacks::test(){
	int i,count;
	count = 30;
	std::cout << "Test " << id_generator++ << " commencing..." << std::endl << std::endl;
	for (i = 1; i < count; ++i)	{
		push(i); peek();
	}
	for (i = -2; i < 8; ++i){
		popAt(i);popAt(i);
	}
	for (i = 0; i < count; ++i)	{
		pop(); peek();
	}
	std::cout << "Done" << std::endl;
}

int main(int argc, char const *argv[]){
	SetOfStacks myStack;
	myStack.test();
	return 0;
}