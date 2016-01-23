//function5.cpp
/*
5) A function named getElement() that takes an integer array (as a pointer) and an
index and returns the array element at that index (not a copy).
Assume the index is valid.
*/

#include<iostream>

int& getElement(int *array, int index){

	return array[index];;
}

int main(int argc, char const *argv[])
{
	int myArray[5] = {1,2,3,4,5};
	getElement(myArray,4) = 6;
	std::cout << myArray[4];
	return 0;
}