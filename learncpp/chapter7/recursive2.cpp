//recursive2.cpp
/*
2) Write a recursive function that takes an integer as input and
returns the sum of all the numbers in the integer (e.g. 357 = 15).
Print the answer for input 93427 (which is 25).
*/
#include<iostream>

int sumTo(int a){
	if (a == 0){
		return 0;
	} else {
		int divider = 10000000;
		while((a/divider) == 0){
			divider/=10;
		}
		return (a/divider) + sumTo(a%divider);
	}
}

int main(int argc, char const *argv[]){
	std::cout << sumTo(93427);
	return 0;
}