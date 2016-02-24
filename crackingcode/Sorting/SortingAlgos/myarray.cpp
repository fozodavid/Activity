//myarray.cpp

#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>

#include "myarray.h"
#include "myqueue.h"

//MY ARRAY CLASS

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

//RADIX CLASS

Radix::Radix(int a_size, int a_base): myArray(a_size),base(a_base),RQueue(base){}

void Radix::radixsort(){
	int mod = base;
	int divider = 1;
	while(divider <= 1000){
		for (int i = 0; i < size; ++i){
			int key = array[i] % mod;
			key /= divider;
			RQueue.enqueue(key,array[i]);
		}
		int current = 0;
		for (int i = 0; i < base; ++i)	{
			while(RQueue.notEmpty(i)){
				array[current++] = RQueue.dequeue(i);
			}
		}
		mod *= base;
		divider *= base;
	}
}

//MERGE CLASS

Merge::Merge(int a_size): myArray(a_size){}

void Merge::merge(int low, int middle, int high){
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

void Merge::mergesort(int low, int high){
	if(low < high){
		int middle = (low + high) / 2;
		mergesort(low,middle);
		mergesort(middle+1,high);
		merge(low, middle, high);
	}
}