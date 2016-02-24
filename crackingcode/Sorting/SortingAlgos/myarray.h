//myarray.h

#include "myqueue.h"

#ifndef MYARRAY_H
#define MYARRAY_H

class myArray{
	protected:
		int *array;
		int size;

	public:
		myArray(int a_size);
		~myArray();
		void print();
};

class Radix: public myArray {
	private:
		int base;
		myRadixQueue RQueue;
	public:
		Radix(int a_size, int a_base);
		void radixsort();
};

class Merge: public myArray {
	private:
		void merge(int low, int middle, int high);
	public:
		Merge(int a_size);
		void mergesort(int low, int high);
};

#endif