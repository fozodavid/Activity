//function3.cpp
/*
3) A function named minmax() that takes two integers as input and returns the smaller
and larger number as separate parameters.
*/
#include<iostream>

void minmax(int a, int b, int &minOut, int &maxOut){
	minOut = a-1;
	maxOut = b+1;
}

int main(int argc, char const *argv[]){
	int value1(2);
	int value2(4);
	int emptyvalue(0);
	int emptyvalue2(0);
	minmax(value1,value2,emptyvalue, emptyvalue2);

	std::cout << emptyvalue << ' ' << emptyvalue2;

	return 0;
}