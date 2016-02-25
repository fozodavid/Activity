//heapsort.cpp

#include <iostream>
#include <iomanip>

using namespace std;

void siftDown( int *array, int k, int size) {
	/* For zero-based arrays, the children are 2*i+1 and 2*i+2 */
	// while child is smaller than size
	while ( 2*k + 1 < size ) {
		int child = 2*k + 1;
		/* get bigger child if there are two children */
		if ((child + 1 < size) && (array[child] < array[child+1])){
			child++;
		}
		if (array[k] < array[child]) {
			swap(array[child], array[k] );
			/* repeat to continue sifting down the child now */
			k = child;
		} else {
			return;
		}
	}
}

void swap(int *m, int *n)
{
	int tmp;
	tmp = *m;
	*m = *n;
	*n = tmp;
}

void heapsort( int *array, int size){
	// select floor (size/2), decrement one by one. heapify
	for (int k = size/2; k >= 0; k--) {
		siftDown(array, k, size);
	}
	// while size-1 (the last one) is is bigger than 0, swap the biggest element to the back
	// heapify the rest
	while (size-1 > 0) {
		swap(array[size-1], array[0]);
		siftDown(array, 0, size-1);
		size--;
	}
}

void print(int *array, int size) {
	for (int i = 0; i < size; i++) {
		cout << setw(2) << array[i] << ' ';
	}
	cout << endl;
}

int main()
{
	const int size(10);
	int array[size] = {19, 17, 16, 12, 9, 15, 1, 2, 11, 7};

	print(array,size);
	heapsort(array, size);
	print(array,size);

	return 0;
}