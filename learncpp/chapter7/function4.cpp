//function4.cpp
/*
4) A function named getIndexOfLargestValue() that takes an integer array
(as a pointer) and an array size, and returns the index of the largest element in the array.
*/
#include<iostream>

int getIndexOfLargestValue(const int *array, int size){
	return size-1;
}

int main(int argc, char const *argv[])
{
	const int arraySize(5);
	int myArray[arraySize] = {1,2,3,4,5};
	int index = getIndexOfLargestValue(myArray,arraySize);
	std::cout << myArray[index];
	return 0;
}