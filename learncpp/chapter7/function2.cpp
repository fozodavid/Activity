//function2.cpp
/*
2) A function named printEmployeeName() that takes an Employee struct as input.
*/

#include<iostream>

struct Employee {
	char name[25];
};

void printEmployeeName(const Employee &employee){
	std::cout << employee.name;
}

int main(int argc, char const *argv[]){
	Employee bob = {"Bob"};
	printEmployeeName(bob);
	return 0;
}