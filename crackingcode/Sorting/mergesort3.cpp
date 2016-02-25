//mergesort3.cpp

#include<iostream>
#include<iomanip>



void printArray(int array[], int size){
	for (int i = 0; i < size; ++i) {
		if (array[i] == 0){
			std::cout << "__ ";
		} else {
			std::cout << std::setw(2) << array[i] << ' ';
		}
	}
	std::cout << std::endl;
}

void makeitzero(int array[], int size){
	for (int i = 0; i < size; ++i) {
		array[i] = 0;
	}
}




void mergesort(int array[], int size, int low, int high){

}

int main(int argc, char const *argv[]) {
	const int size(10);
	int array[size] = {10,9,6,8,4,7,3,1,2,5};
	printArray(array, size);
	mergesort(array,size,0,size-1);
	printArray(array, size);
	return 0;
}