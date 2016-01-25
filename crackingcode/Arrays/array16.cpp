//array16.cpp

#include<iostream>

struct Pixel {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;
};

void rotate(Pixel picture[][3],Pixel   outputPic[][3] , int dim){
	int input_i;
	int input_j;
	int output_i = dim-1;
	int output_j = 0;
	for (input_i = 0; input_i < dim; ++input_i)	{
		int output_i_current = output_i;
		int output_j_current = output_j;
		for (input_j = 0; input_j < dim; ++input_j)	{
		//	std::cout << output_i_current << ' ' << output_j_current << std::endl;
			outputPic[input_i + output_i_current--][input_j + output_j_current--] =
			picture[input_i][input_j];
		}
		--output_i;
		++output_j;
	}
}

void printArray(int array[][3], int size){
	int i,j;
	for (i = 0; i < size; ++i){
		for (j = 0; j < size; ++j){
			if (!(j % 3)){
				std::cout << std::endl;
			}
			std::cout << array[i][j] << ' ';
		}
	}
}

void rotate(int matrix[][3], int dim){
	int layer;
	for (int layer = 0; layer < (dim/2); ++layer)	{
		int first = layer;
		int last = dim-1 - layer;
		int i;
		for (i = 0; i < last; ++i){
			int offset = i - first;
			//save top
			int top = matrix[first][i];

			//left -> top
			matrix[first][i] = matrix[last-offset][first];

			//bottom -> left
			matrix[last-offset][first] = matrix[last][last - offset];

			//right -> bottom
			matrix[last][last-offset] = matrix[i][last];

			//top -> right
			matrix[i][last] = top;

		}
	}
}


int main(int argc, char const *argv[])
{
	const int size = 3;
	/*Pixel array[size][size] = 	{   {{0,0,0,0},{1,1,1,1},{2,2,2,2}},
									{{3,3,3,3},{4,4,4,4},{5,5,5,5}},
									{{6,6,6,6},{7,7,7,7},{8,8,8,8}} 	};*/
	int array[size][size] = {{1,2,3},{4,5,6},{7,8,9}};
	Pixel outputArray[size][size] = { 0 };

	printArray(array,size);

	rotate(array, size);
	std::cout << std::endl;

	printArray(array,size);

	return 0;
}