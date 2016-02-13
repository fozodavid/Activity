//bit52.cpp

#include<iostream>
#include<bitset>

int main(int argc, char const *argv[]) {
	const int size(10);
	double d[size] = {0.00001, 0.0001, 0.001, 0.01, 1.0, 10.0, 100.0, 1000.0, 10000.0, 100000.0};

	int i = 0b111111;
	for (i = 0; i < size; ++i)	{
		std::cout << (d[i]) << std::endl;
	}
	return 0;
}