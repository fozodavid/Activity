//position.h

#ifndef POSITION_H
#define POSITION_H

enum Quadrant {
	QUADRANT_TOP_LEFT,
	QUADRANT_TOP_RIGHT,
	QUADRANT_BOTTOM_LEFT,
	QUADRANT_BOTTOM_RIGHT,
	QUADRANT_NOT_THERE
};

class Position{

	private:
		int hstart, hmiddle, hend;
		int vstart, vmiddle, vend;

	public:
		static int id_generator;
		//CONSTRUCTOR
		Position(int hs, int he, int vs, int ve);

		Position GetTopLeft    ();
		Position GetTopRight   ();
		Position GetBottomLeft ();
		Position GetBottomRight();

		Quadrant isInThere(Position X);

		bool tooLittle();

		int getHS();
		int getHE();
		int getVS();
		int getVE();
};

#endif