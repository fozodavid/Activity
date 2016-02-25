//shellsort.cpp
#include<iostream>
#include<iomanip>

void shellsort(int v[], int n) {
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}


void print(int *array, int size) {
	using namespace std;
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
	shellsort(array, size);
	print(array,size);

	return 0;
}