//stringbuffer2.c

#include<string.h>
#include<stdio.h>
#include<malloc.h>
#include<limits.h>


char * GetString2(void){
	//var
	char *buffer  = NULL; //growable buffer for chars
	unsigned int capacity = 0; // capacity of buffer
	unsigned int n = 0; // number of chars actually in the buffer
	char c;
	//get it from stdio iteratively
	while(c != '\n' && c != EOF){
		scanf("%c", &c);
	//String buffer
		//grow buffer if necessary
		if(n+1 > capacity){
			if (capacity == 0){
				capacity = 4;
			} else if (capacity <= (UINT_MAX/2)){
				capacity *=2 ;
			}
			else {
				free(buffer);
				return NULL;
			}
			char* temp = realloc(buffer, capacity * sizeof(char));
            /*if (temp == NULL)
            {
                free(buffer);
                return NULL;
            }*/
            buffer = temp;

		//doubling buffer
			//malloc string buffer

		}
		//append character to the buffer
		buffer[n] = c;
		n++;
	}
	//return NULL if user didn't provide input
	if (n == 0 && c == EOF){
		return NULL;
	}


	//minimize buffer
	char* minimal = malloc(sizeof(char)*(n+1));
	strcpy(minimal, buffer);
	free(buffer);
	minimal[n] = '\0';

	//return string
	return minimal;
}

int main(int argc, char const *argv[])
{
	char *n = GetString2();
	int c= 0;

	while (n[c] != '\0'){
		printf("%c", n[c]);
		c++;
	}
	return 0;
}