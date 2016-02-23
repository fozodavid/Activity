//main.cpp

#include "myarray.h"

int main(int argc, char const *argv[]) {
	const int size(10);
	myArray testArray(size);
	testArray.print();
	testArray.mergesort(0,size);
	testArray.print();
	return 0;
}