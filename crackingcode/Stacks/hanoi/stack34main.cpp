//stack34main.cpp
#include "stack34.h"
#include "stack34functions.cpp"
#include "stack34algo.cpp"

/*Command 'g++ Test.cpp' does both compilation and linking. If you have many
source files, you should link Test.cpp with them too like 'g++ Test.cpp other1.cpp other2.cpp'
or just compile all files and link them all together later like
'g++ Test.o other1.o other2.o'.*/

int main(){
	Hanoi myHanoi5(4);
	myHanoi5.check();
	myHanoi5.solve();
	//myHanoi5.check();

	return 0;
}