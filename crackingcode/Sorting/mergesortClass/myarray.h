//myarray.h

#ifndef MYARRAY_H
#define MYARRAY_H

class myArray{
private:
	int *array;
	int size;

	void merge(int low, int middle, int high);
public:
	myArray(int a_size);
	~myArray();
	void print();

	void mergesort(int low, int high);
};

#endif