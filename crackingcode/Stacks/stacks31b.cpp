//stacks31b.cpp

#include<iostream>
#include<climits>

class Stack{
	int *array;
	int top, bottom;
	int min_element = INT_MAX;

	public:
		static int m_test_id;

		Stack(int *extern_array, int ext_top, int ext_bottom){
			top    = ext_top;
			bottom = ext_bottom;
			array  = extern_array;
		}
		void min(){
			std::cout << "Minimum: " << min_element << std::endl;
		}
		void push(int number){
			if(!array[top+1]){
				array[top+1] = number;
				if (number < min_element){
					min_element = number;
				}
				top = top + 1;
			} else {
				std::cout << "Stack full." << std::endl;
			}
		}
		void pop(){
			if(top <= bottom){
				top = bottom;
				std::cout << "Cannot pop." << std::endl;
			} else {
				array[top] = 0;
				top = top-1;
			}
		}
		void peek(){
			if(array[top]){
				std::cout << array[top]     << std::endl;
			} else {
				std::cout << "Empty stack." << std::endl;
			}
		}
		void test(){
			std::cout << "TEST " << m_test_id++ << " Commencing..." << std::endl << std::endl;

			push(1);	peek();
			push(2);	peek();
			push(3);	peek();
			push(4);	peek();
			push(5);	peek();
			min();
			pop  ();	peek();
			pop  ();	peek();
			pop  ();	peek();
			pop  ();	peek();
			pop  ();   std::cout << std::endl;

			std::cout << "Done." << std::endl << std::endl;
		}
};

int Stack::m_test_id = 0;

int main(int argc, char const *argv[]){

	int myArray[19] = { 0 };
	myArray[5]  = 1; //boundary for mystack1
	myArray[11] = 1; //boundary for mystack2
	myArray[18] = 1; //boundary for mystack3

	Stack myStack1(myArray,0,0);
	Stack myStack2(myArray,6,6);
	Stack myStack3(myArray,12,12);

	myStack1.test();
	myStack2.test();
	myStack3.test();

	return 0;
}