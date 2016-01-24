//stack.cpp
#include<iostream>

/*
The class should be named Stack, and should contain:
* A private fixed array of integers of length 10.
* A private integer to keep track of the length of the stack.
* A public member function named reset() that sets the length
  to 0 and all of the element values to 0.
* A public member function named push() that pushes a value on
  the stack. push() should return false if the array is already
  full, and true otherwise.
* A public member function named pop() that pops a value off the
  stack. If there are no values on the stack, it should return -1.
* A public member function named print() that prints all the
  values in the stack.
*/
class Stack {
	int array[10];
	int stackLength;
	int currentSize;

	public:
		void reset(){
			currentSize = 0;
			stackLength = 0;
		}
		bool push(int value){
			array[currentSize] = value;
			++currentSize;
			++stackLength;
		}
		int pop(){
			array[currentSize] = 0;
			--currentSize;
			--stackLength;
		}
		void print(){
			int i;
			std::cout << "( ";
			for (i = 0; i < currentSize; ++i){
				std::cout << array[i] << ' ';
			}
			std::cout << " )" << std::endl;
		}
};


int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}