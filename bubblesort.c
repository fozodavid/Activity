//bubblesort.c

#include<stdio.h>

int main(int argc, char const *argv[])
{
	int size = 8;
	int a[8] = {8,7,6,5,4,3,2,1};
	int i = 0;
	int swapped;
	int temp;
//	Iterate over list
	for (i; i < size; i++)
	{
	swapped = 0;
	int j = size;
		for (j; i < j; j--)
//	Compare adjacent elements
		{
			if (a[j] < a[j-1])
				{
//	Swap elements that are in the wrong order
					temp = a[j];
					a[j] = a[j-1];
					a[j-1] = temp;
					swapped = 1;
				}
//	Largest element will 'bubble' to the end
		}
//	The list is sorted once no elements have been swapped
		if (swapped == 0)
		{
			break;
		}
//  TEST
		int k = 0;
		printf("\n\n");
		while(k < size){
			printf("%d",a[k] );
			k++;
		}

	}
	return 0;
}