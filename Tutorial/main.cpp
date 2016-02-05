//main.cpp

#include<iostream>
#include "Sally.h"
#include "Sally.cpp"
using namespace std;

int main() {
	Sally a(34);
	Sally b(21);
	Sally c;

	c=a+b;
	cout << c.num << endl;
	return 0;
}