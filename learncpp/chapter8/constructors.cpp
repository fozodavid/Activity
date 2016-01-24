//constructors.cpp
/*
1) Write a class named Ball. Ball should have two private member
variables with default values: m_color (“Black”) and m_radius (10.0).
Ball should provide one or more constructors to set only m_color,
set only m_radius, or set both values. Write a function to print
out the color and radius of the ball.
*/
#include<iostream>

class Ball{
	char *m_color;
	double m_radius;

	public:
		Ball(char *color , double radius = 10.0){
			m_color = color;
			m_radius = radius;
		}
		void print(){
			std::cout 	<< "The color  of the ball is: " << m_color << std::endl
						<< "The radius of the ball is: " << m_radius << std::endl;
		}
};

int main(int argc, char const *argv[])
{
	//Ball myBall_1;
	char color1[] = "White";
	char color2[] = "Red";
	Ball myBall_2(color1);
	Ball myBall_3(color2,5.0);

	//myBall_1.print();
	myBall_2.print();
	myBall_3.print();

	return 0;
}
