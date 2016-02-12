//assignfunc.cpp
#include<iostream>
#include<iomanip>
#include"position.h"
#include"assignfunc.h"


void printArray(int array[SIZE][SIZE]){
	int i, j;
	for (i = 0; i < SIZE; ++i){
		std::cout << std::endl;
		for (j = 0; j < SIZE; ++j){
			std::cout << std::setw(4) << array[i][j] << ' ';
		}
	}
	std::cout << std::endl;
}

void fill(int array[][SIZE], Position Square, Quadrant quad){
	Position temp(0,0,0,0);
	switch(quad){
		case QUADRANT_TOP_LEFT:     temp = Square.GetTopLeft();     break;
		case QUADRANT_TOP_RIGHT:    temp = Square.GetTopRight();	break;
		case QUADRANT_BOTTOM_LEFT:  temp = Square.GetBottomLeft();  break;
		case QUADRANT_BOTTOM_RIGHT: temp = Square.GetBottomRight(); break;
	}
	int mini = temp.getHS();
	int maxi = temp.getHE();
	int minj = temp.getVS();
	int maxj = temp.getVE();

	int i      = Square.getHS();
	int j      = Square.getVS();
	int ilimit = Square.getHE();
	int jlimit = Square.getVE();

	while (i <= ilimit) {
		j = Square.getVS();
		while (j <= jlimit) {
			if(((mini <= i) && (i <= maxi)) && ((minj <= j) && (j <= maxj))){
				//std::cout << "FILL: do nothing: i: " << i << " j: " << j << std::endl;
			} else {
				//std::cout << "FILL: i: " << i << " j: " << j << std::endl;
				array[i][j] = Position::id_generator;
			}
		++j;
		}
	++i;
	}
	++Position::id_generator;
	printArray(array);
}


void assign(int array[][SIZE], Position Square, Quadrant quad, Position X){

	if (Square.tooLittle()){
		return;
	}

	// UPDATE QUADRANT IF NEEDED
	Quadrant check = Square.isInThere(X);
	if (check != QUADRANT_NOT_THERE){
		quad = check;
	}

	// WHEN SMALL FILL IT
	fill(array, Square,quad);

	// RECURSIVE CALL
	Position tl = Square.GetTopLeft();
	Position tr = Square.GetTopRight();
	Position bl = Square.GetBottomLeft();
	Position br = Square.GetBottomRight();

	switch(quad){
		case QUADRANT_TOP_LEFT:
			assign(array, tl, QUADRANT_TOP_LEFT,X);
			assign(array, tr, QUADRANT_BOTTOM_LEFT,X);
			assign(array, bl, QUADRANT_TOP_RIGHT,X);
			assign(array, br, QUADRANT_TOP_LEFT,X);
			break;
		case QUADRANT_TOP_RIGHT:
			assign(array, tl, QUADRANT_BOTTOM_RIGHT,X);
			assign(array, tr, QUADRANT_TOP_RIGHT,X);
			assign(array, bl, QUADRANT_TOP_RIGHT,X);
			assign(array, br, QUADRANT_TOP_LEFT,X);
			break;
		case QUADRANT_BOTTOM_LEFT:
			assign(array, tl, QUADRANT_BOTTOM_RIGHT,X);
			assign(array, tr, QUADRANT_BOTTOM_LEFT,X);
			assign(array, bl, QUADRANT_BOTTOM_LEFT,X);
			assign(array, br, QUADRANT_TOP_LEFT,X);
			break;
		case QUADRANT_BOTTOM_RIGHT:
			assign(array, tl, QUADRANT_BOTTOM_RIGHT,X);
			assign(array, tr, QUADRANT_BOTTOM_LEFT,X);
			assign(array, bl, QUADRANT_TOP_RIGHT,X);
			assign(array, br, QUADRANT_BOTTOM_RIGHT,X);
			break;
	}
}
