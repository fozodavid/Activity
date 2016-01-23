//function.cpp
/*
1) A function named sumTo() that takes an integer parameter and returns the sum of all
the numbers between 1 and the input number.
*/

#include<iostream>

int sumTo(int value){
	int i;
	int sum(0);
	for (i = 1; i<=value; ++i){
		sum += i;
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int number(5);
	int result = sumTo(number);
	std::cout << result;
	return 0;
}