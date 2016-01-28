//stacks31.cpp

#include<iostream>

int push(int array[], int top, int number){
	if(!array[top+1]){
		array[top+1] = number;
		return top + 1;
	} else {
		std::cout << "Stack full." << std::endl;
		return top;
	}
}
int pop(int array[], int top, int bottom){
	if(top <= bottom){
		top = bottom;
		std::cout << "Cannot pop." << std::endl;
		return top;
	} else {
		array[top] = 0;
		return top-1;
	}
}
void peek(int array[], int top){
	if(array[top]){
		std::cout << array[top] << std::endl;
	} else {
		std::cout << "Empty stack." << std::endl;
	}
}

void test(int id, int array[], int top, int bottom){
	std::cout << "TEST " << id << " Commencing..." << std::endl << std::endl;

	top = push(array,top,1);		peek(array,top);
	top = push(array,top,2);		peek(array,top);
	top = push(array,top,3);		peek(array,top);
	top = push(array,top,4);		peek(array,top);
	top = push(array,top,5);		peek(array,top);
	top = pop (array,top,bottom);	peek(array,top);
	top = pop (array,top,bottom);	peek(array,top);
	top = pop (array,top,bottom);	peek(array,top);
	top = pop (array,top,bottom);	peek(array,top);
	top = pop (array,top,bottom);   std::cout << std::endl;

	std::cout << "Done." << std::endl << std::endl;

}

int main(int argc, char const *argv[]){
	int array[15] = { 0 };
	int top1(0), bottom1(0);
	int top2(5), bottom2(5);
	array[4] = 1;
	int top3(10),bottom3(10);
	array[9] = 1;

	test(1,array,top1,bottom1);
	test(2,array,top2,bottom2);
	test(3,array,top3,bottom3);


	return 0;
}