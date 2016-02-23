//myarray.cpp

#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

#include "myarray.h"

//PRIVATE FUNCTIONS

void myArray::merge(int low, int middle, int high){
	int *temp = new int [size];
	//copy from array to temp
	for (int i = low; i <= high; ++i)	{
		temp[i] = array[i];
	}
	//sort
	int left_cursor  = low;
	int right_cursor = middle+1;
	int array_cursor = low;

	while(left_cursor <= middle && right_cursor <= high){
		if(temp[left_cursor] <= temp[right_cursor]){
			array[array_cursor++] = temp[left_cursor++];
		} else {
			array[array_cursor++] = temp[right_cursor++];
		}
	}
	//sort rest
	while(left_cursor <= middle){
		array[array_cursor++] = temp[left_cursor++];
	}
	delete temp;
}

//PUBLIC FUNCTIONS

myArray::myArray(int a_size){
	size = a_size;
	array = new int[size];

	//random number generator for contents
    srand((unsigned)time(0));
    int random_integer;
    for(int i = 0; i < size; ++i){
        random_integer = (rand()%size)+1;
        array[i] = random_integer;
    }

}

myArray::~myArray(){
	delete array;
	array = NULL;
}

void myArray::print(){
	for (int i = 0; i < size; ++i) {
		if (array[i] == 0){
			std::cout << "__ ";
		} else {
			std::cout << std::setw(2) << array[i] << ' ';
		}
	}
	std::cout << std::endl;
}

void myArray::mergesort(int low, int high){
	if(low < high){
		int middle = (low + high) / 2;
		mergesort(low,middle);
		mergesort(middle+1,high);
		merge(low, middle, high);
	}
}
