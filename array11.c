//array11.c

//determines if a string has all unique characters

#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
	char input[50];
	scanf("%s", input);

	int inputsize = strlen(input);
	int array[26];

	int i;
	for (i = 0; i < 26; i++){
		array[i] = 0;
	}
	i = 0;
	while (i<inputsize){
		int var = ((int) input[i])-97;
		array[var] += 1;
		if (array[var]>1){
			printf("NO\n");
			return 0;
		}
		i++;
	}
	printf("YES\n");
	return 0;
}