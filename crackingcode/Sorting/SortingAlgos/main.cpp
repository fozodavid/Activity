//main.cpp

#include "myarray.h"
#include <iostream>

int main(int argc, char const *argv[]) {
	const int size(30);
	Merge testArray(size);
	testArray.print();
	testArray.mergesort(0,size-1);
	testArray.print();


	return 0;
}