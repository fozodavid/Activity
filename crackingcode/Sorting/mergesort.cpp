//mergesort.cpp

#include<iostream>

using namespace std;

void merge(int array[], int size, int low, int middle, int high){
	int temp[size];
	for (int i = low; i <= high; ++i) {
		temp[i] = array[i];
	}
	int i = low;
	int j = middle+1;
	int k = low;

	while (i <= middle && j <= high){
		if (temp[i] <= temp[j])	{
			array[k] = temp[i];
			++i;
		} else {
			array[k] = temp[j];
			++j;
		}
		++k;
	}
	while(i <= middle){
		array[k] = temp[i];
		++k;
		++i;
	}
}


void mergeSort (int array[], int size, int low, int high){
	if (low < high) {
		int middle = (low + high) / 2;
		mergeSort(array, size, low, middle);
		mergeSort(array, size, middle+1, high);
		merge(array, size, low, middle, high);
	}
}

int main(int argc, char const *argv[]) {
	const int size(10);
	int numbers[] = {5,10,1,6,2,9,3,8,7,3};
	mergeSort(numbers, size, 0, 9);
	for (int i = 0; i < size; ++i)	{
		cout << numbers[i] << ' ';
	}
	return 0;
}