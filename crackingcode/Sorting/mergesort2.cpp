//mergesort2.cpp

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

void merge(int array[], int size, int low, int middle, int high){
	int *temp = new int [size];
	makeitzero(temp, size);
	//copy from low to high
	for (int i = low; i <= high; ++i)	{
		temp[i] = array[i];
	}

	//sort by comparing the two
	int left_cursor = low;
	int right_cursor = middle+1;
	int array_cursor = low;

	while(left_cursor <= middle && right_cursor <= high){
		if(temp[left_cursor] <= temp[right_cursor]){
			array[array_cursor] = temp[left_cursor];
			++left_cursor;
		} else {
			array[array_cursor] = temp[right_cursor];
			++right_cursor;
		}
		++array_cursor;
	}

	//sort the rest from the left
	while(left_cursor <= middle){
		array[array_cursor] = temp[left_cursor];
		++left_cursor;
		++array_cursor;
	}

	//printArray(temp, size);
	//printArray(array, size);
	delete temp;
}

void mergesort(int array[], int size, int low, int high){
	if (low < high) {
		int middle = (high + low) / 2;
		mergesort(array, size, low, middle);
		mergesort(array, size, middle+1, high);
		merge(array, size, low, middle, high);
	}
}


int main(int argc, char const *argv[]) {
	const int size(10);
	int array[size] = {10,9,6,8,4,7,3,1,2,5};
	printArray(array, size);
	mergesort(array,size,0,size-1);
	printArray(array, size);
	return 0;
}