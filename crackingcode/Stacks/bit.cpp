//bit.cpp

#include<iostream>
#include<cmath>
#include<iomanip>

void printBinary(int digit){
	int i;
	int subtractor;
	std::cout << std::setw(3) << digit << ' ';
	for (i = 7; i >= 0; i--){
		subtractor = static_cast<int>(pow(2.0,i));
		if (digit >= subtractor){
			std::cout << '1';
			digit -= subtractor;
		} else {
			std::cout << '0';
		}
	}
	std::cout << ' ' ;
}


int main(int argc, char const *argv[]) {
	int i;
	for(i = 0; i < 256; ++i){
		if(i % 8 == 0) {
			std::cout << std::endl;
		}
		printBinary(i);
	}
	std::cout << std::endl;
	return 0;
}