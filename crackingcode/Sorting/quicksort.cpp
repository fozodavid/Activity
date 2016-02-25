//quicksort.cpp
#include<iostream>

void print(int *array, int size){
	for (int i = 0; i < size; ++i){
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;
}

void swap(int *array, int a, int b) {
	int temp = array[b];
	array[b] = array[a];
	array[a] = temp;
}

int partition(int *array, int start, int end){
	int pivot = array[end];
	int pindex = start;
	for (int i = start; i < end; ++i) {
		if(array[i] <= pivot) {
			swap(array,i,pindex);
			++pindex;
		}
	}
	swap(array,pindex,end);
	return pindex;
}

void quicksort(int *array, int start, int end){
	if(start < end){
		int pindex = partition(array,start,end);
		quicksort(array,start,pindex-1);
		quicksort(array,pindex+1,end);
	}
}

int main(int argc, char const *argv[]) {
	const int size(10);
	int array[size]	= {10,9,8,7,1,6,2,3,4,5};
	print(array,size);
	quicksort(array, 0, size-1);
	print(array,size);
	return 0;
}