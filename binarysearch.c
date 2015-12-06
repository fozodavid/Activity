//binarysearch.c

//	binary search
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char const *argv[])
{

	int list[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	int target = 1;
	int start = 0;
	int end = 14;
	int size = 15;

//	can only search sorted lists

	if (isSorted(list, end) == 1)
		{
			printf("The array is not sorted!\n" );
			return 1;
		}

/*
//	TEST

	int i = 0;
	while (i < end+1){
    binarySearch(i,list,start,end,size);
	i++;
	}
*/

	binarySearch(target,list,start,end,size);

	return 0;
}

//  functions

int isSorted(int array[], int end)
{
	int i = 0;
	while(i < end+1)

	{
		if (array[i] > array[i+1]) {
			return 1;
		}
		i++;
	}
	return 0;
}

int binarySearch(int target, int array[], int start, int end, int size)
{
	if (size == 0) {
		printf("%d is NOT in the array!\n", target);
		return 1;
	}
//	while length of list > 0
	while(size > 0) {

//	look at middle of list
	int examined = (end-start)/2 + start;
	if (target == array[examined])
	{
	 	printf("%d is in the array!\n",target);
//	if number found, return true
	 	return 0;
	}
//	else if number higher, search left
	else if (target > array[examined])
	{
		binarySearch(target, array, end-(size/2)+1, end, size/2);
	}
//	else if number lower, search right
	else {
		binarySearch(target, array, start, start+(size/2)-1, size/2);
	}

	size = 0;

	}

}