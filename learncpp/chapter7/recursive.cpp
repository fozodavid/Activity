//recursive.cpp
/*
1) A factorial of an integer N (written N!) is defined as the product
(multiplication) of all the numbers between 1 and N (0! = 1).
Write a recursive function called factorial that returns the factorial
of the input. Test it with the first 5 factorials.

Hint: Remember that x * y = y * x, so the product of all the numbers
between 1 and N is the same as the product of all the numbers between N and 1.
*/
#include<iostream>

long long factorial(int n){
	if (n == 0){
		return 1;
	} else {
		return n*factorial(n-1);
	}
}


int main(int argc, char const *argv[]){
	int count(20);
	int i;
	for (int i = 0; i < count; ++i)	{
		std::cout << i << ' ' << factorial(i) << std::endl;
	}
	return 0;
}