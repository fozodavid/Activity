//funcptrquiz.cpp
/*
1a) Create a short program asking the user
for two integer inputs and a mathematical
operation (‘+’, ‘-‘, ‘*’, ‘/’). Ensure the
user enters a valid operation.
*/
#include<iostream>

int main(int argc, char const *argv[])
{
	std::cout << "Give me two integers! ";
	int a,b;
	std::cin >> a >> b;

	std::cout << "Specify operation (\'+\', \'-\', \'*\', \'/\'): ";
	char operation;
	std::cin >> operation;



	return 0;
}