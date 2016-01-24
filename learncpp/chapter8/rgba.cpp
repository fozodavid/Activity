//rgba.cpp
/*
1) Write a class named RGBA that contains 4 member variables of type
uint8_t named m_red, m_green, m_blue, and m_alpha
(#include cstdint to access type uint8_t). Assign default values
of 0 to m_red, m_green, and m_blue, and 255 to m_alpha. Create a
constructor that uses a member initializer list that allows the
user to initialize values for m_red, m_blue, and m_green (all
three must be provided), and optionally m_alpha. Include a
print() function that outputs the value of the member variables.
*/
#include<iostream>

class RGBA {
	private:
		uint8_t m_red;
		uint8_t m_green;
		uint8_t m_blue;
		uint8_t m_alpha;
	public:
		RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha=255):
			m_red(red), m_green(green), m_blue(blue),m_alpha(alpha)
		{}
		void print(){
			std::cout 	<< "r= " << static_cast<int>(m_red)   << ' '
						<< "g= " << static_cast<int>(m_green) << ' '
						<< "b= " << static_cast<int>(m_blue)  << std::endl;
		}
};

int main(int argc, char const *argv[])
{
	RGBA teal(0,127,127);
	teal.print();
	return 0;
}