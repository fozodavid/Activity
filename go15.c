//go15.c

//game of fifteen

#include<stdio.h>
#include<stdlib.h>


int main(int argc, char const *argv[])
{

//INIT
//	input dimensions :
int dim = atoi(argv[1]);
int size = dim*dim;
int won = 0;
//	starts an array for the board
int array[size];
//	selects tile/selects starting position
int activetile = size-1;
void draw(int dim, int array[]);

//SETTING UP BOARD
int i = size-1;
int r = 0;
for(i; i > -1; i--)
{
	array[i] = r;
	r++;
}
if (size%2 == 0){
	array[size-2] = 2;
	array[size-3] = 1;
}


//DRAW
//	draws board
while(won == 0){


draw(dim, array);



char direction;
int temp;
int illegalMove = 1;

// Check if move is valid
while(illegalMove){

printf("What direction do you want to move?(w,a,s,d)\n");
scanf("%c", &direction);
//direction = 'w';
//gets(&direction);

if(direction == 'w'){
	illegalMove = movechecker(0,dim,1,activetile);
}
else if(direction == 's'){
	illegalMove = movechecker(size-dim,size,1,activetile);
}
else if(direction == 'a'){
	illegalMove = movechecker(0,size,dim,activetile);
}
else if(direction == 'd'){
	illegalMove = movechecker(dim-1,size,dim,activetile);
}

}

//MOVING TO DIRECTIONS
if (direction == 'w') {
activetile = move(activetile, array, activetile-dim, temp);
}
else if(direction == 's'){
activetile = move(activetile, array, activetile+dim, temp);
}
else if(direction == 'a'){
activetile = move(activetile, array, activetile-1, temp);
}
else if(direction == 'd'){
activetile = move(activetile, array, activetile+1, temp);
}

won = isWon(array, size);
}
printf("You won!\n");
return 0;
}



void draw(int dim, int array[]){

	int d = 0;
//		for i in size:
	printf("\n");
	for (d; d < dim; d++) {
			int k = 0;
		//			for i in dim:
			for (k; k < dim; k++)
			{
				if (array[d*dim+k] == 0){
					char c = '_';
					printf("  %c",c);
				}
				else{
					printf("%2d ",array[d*dim+k] );
				}

			}
			printf("\n");
		}

}

int move(int activetile, int array[], int swappos, int temp){
//direction == 'a'){
	temp = array[swappos];
	array[swappos] = array[activetile];
	array[activetile] = temp;
	activetile = swappos;
	return activetile;
}

int movechecker(int start, int limit, int step, int activetile){
	int k = start;
	int illegalMove = 0;
	for (k; k<limit;k+=step)
	{
		if(k == activetile){
		illegalMove = 1;
		printf("Illegal move!\n");
		}
	}
	return illegalMove;
}

//won
int isWon(int array[], int size){
//	if all are sorted
	int won = 1;
	int i = 0;
	for (i;i<size-2;i++){
		if (array[i] > array[i+1]){
			won = 0;
		}

	}
	return won;
}