//pos_func.cpp

#include<iostream>
#include "Position.h"


Position::Position(int hs, int he, int vs, int ve){
	hstart = hs;
	hend   = he;
	vstart = vs;
	vend   = ve;
	hmiddle = (hend-hstart)/2 + hstart;
	vmiddle = (vend-vstart)/2 + vstart;

}
Position Position::GetTopLeft(){
	Position temp(hstart, hmiddle, vstart, vmiddle);
	return temp;
};
Position Position::GetTopRight(){
	Position temp(hmiddle+1, hend, vstart, vmiddle);
	return temp;
};
Position Position::GetBottomLeft(){
	Position temp(hstart, hmiddle, vmiddle+1, vend);
	return temp;
};
Position Position::GetBottomRight(){
	Position temp(hmiddle+1, hend, vmiddle+1, vend);
	return temp;
};
Quadrant Position::isInThere(Position X){

	bool left   = (hstart <= X.hstart) && (X.hstart <= hmiddle);
	bool right  = (hmiddle < X.hstart) && (X.hstart <= hend);
	bool top    = (vstart <= X.vstart) && (X.vstart <= vmiddle);
	bool bottom = (vmiddle < X.vstart) && (X.vstart <= vend);

	if (top && left){
		return QUADRANT_TOP_LEFT;
	} else if (top && right){
		return QUADRANT_TOP_RIGHT;
	} else if (bottom && left){
		return QUADRANT_BOTTOM_LEFT;
	} else if (bottom && right){
		return QUADRANT_BOTTOM_RIGHT;
	} else {
		return QUADRANT_NOT_THERE;
	}
}

bool Position::tooLittle(){
	if(hend == hstart){
		return true;
	} else {
		return false;
	}
}

int Position::getHS(){return hstart;}
int Position::getHE(){return hend;}
int Position::getVS(){return vstart;}
int Position::getVE(){return vend;}
