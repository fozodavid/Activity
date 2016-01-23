//funcptr.cpp
#include<iostream>

int foo(){
	return 5;
}

int main(int argc, char const *argv[])
{
	std::cout << foo;
	return 0;
}