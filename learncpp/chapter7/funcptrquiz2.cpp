#include <iostream>

int getInteger(){
    std::cout << "Enter an integer: ";
    int x;
    std::cin >> x;
    return x;
}

char getOperation(){
    char op;
    do
    {
        std::cout << "Enter an operation ('+', '-', '*', '/'): ";
        std::cin >> op;
    }
    while (op!='+' && op!='-' && op!='*' && op!='/');

    return op;
}

int add(int x, int y){
	return x + y;
}
int subtrack(int x, int y){
	return x - y;
}
int multiply(int x, int y){
	return x * y;
}
int divide(int x, int y){
	return x/y;
}

typedef int (*arithmeticFcn)(int, int);

arithmeticFcn getArithmeticFcn(char op){
	switch(op){
		default:
		case('+'): return add;
		case('-'): return subtrack;
		case('*'): return multiply;
		case('/'): return divide;
	}
}

/*2c) Modify getArithmeticFcn to loop
through the array and return the appropriate function pointer.*/

struct arithmeticStruct {
	char op;
	arithmeticFcn fcn;
};

static arithmeticStruct myArray[4] = 	{{'+',add},{'-',subtrack},
										 {'*',multiply},{'/',divide}};


int main(){
    int x = getInteger();
    char op = getOperation();
    int y = getInteger();

    arithmeticFcn fcn = getArithmeticFcn(op);
    std::cout << x << ' ' << op << ' ' << y << " = " << fcn(x, y) << '\n';

    return 0;
}