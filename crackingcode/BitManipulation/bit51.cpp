//bit51.cpp
#include<iostream>
#include<bitset>

int setBit(int num,int i){
	return ((1 << i) | num);
}

int setFromjtoi(int m, int n, int i, int j){
	int mask = setBit(((~0) << j), i) -1;
	n = n << i;
	m = m & mask;
	return (n | m);
}

int main(int argc, char const *argv[]) {
	int m = 0b111100111100;
	int n = 0b10011;
	int i = 2;
	int j = 7;

	std::cout << std::bitset<16>(m) << std::endl;
	m = setFromjtoi(m,n,i,j);
	std::cout << std::bitset<16>(m) << std::endl;
	return 0;
}