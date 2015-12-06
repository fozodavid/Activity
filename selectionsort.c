//selectionsort.c

#include<stdio.h>

int main(int argc, char const *argv[])
{
int size = 15;
int array[15] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
int i = 0;
int temp;
int min;

//		for i = 0 to n - 1

for (i; i < size - 1; i++)
{
//		for j = i + 1 to n

	int j = i+1;
	int min = j;

	for (j; j < size; j++)
	{
//		find index of minimum value

		if (array[min] > array[j]){
			min = j;
		}

	}
//		swap array[min] and array[i]
	if (array[min] < array[i])
	{
	temp = array[i];
	array[i] = array[min];
	array[min] = temp;
	}

/*
//	TEST
	int k = 0;
	printf("\n");
	for (k; k < size; k++)
	{
	printf("array: %d\n",array[k]);
	}
*/

}
	return 0;
}