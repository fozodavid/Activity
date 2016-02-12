//lshape.cpp

#include<iostream>
#include"position.h"
#include"assignfunc.h"

int Position::id_generator(1);

int main(int argc, char const *argv[]){
	int array[SIZE][SIZE] = { 0 };
	int array2[SIZE][SIZE] = { 0 };
	Position y(0,0,3,3);
	Position grand(0,SIZE-1,0,SIZE-1);

	assign(array2,grand,QUADRANT_TOP_RIGHT,y);
	printArray(array2);

	return 0;
}