//array17.cpp

#include<iostream>
#include<iomanip>


void Set0Column_Row(int matrix[][4], int i, int j, int n, int m){
	int x,y;
	for (x = 0; x < n; ++x)	{
		matrix[x][j] = 0;
	}
	for (y = 0; y < m; ++y) {
		matrix[i][y] = 0;
	}
}

void ZeroingRow_Column(int matrix[][4], int n, int m){
	int i,j;
	struct Position {
		int x;
		int y;
	};
	Position array[10] = { 0 };
	//check for 0
	int posIndex = 0;
	for (i = 0; i < n; ++i)	{
		for (j = 0; j < m; ++j) {
			if(!matrix[i][j]){
				array[posIndex].x = i;
				array[posIndex].y = j;
				++posIndex;
			}
		}
	}
	while (posIndex > 0){
		--posIndex;
		Set0Column_Row(matrix,array[posIndex].x,array[posIndex].y,n,m);
	}
}

void printMatrix(int array[][4], int n, int m){
	int i,j;
	std::cout << std::endl;
	for (i = 0; i < n; ++i){
		for (j = 0; j < m; ++j){
			if (!(j % m)){
				std::cout << std::endl;
			}
			std::cout << std::setw(2) << array[i][j] << ' ';
		}
	}
}

int main(int argc, char const *argv[]) {
	const int n = 3;
	const int m = 4;
	int matrix[n][m] = {{1,2,3,4},
						{0,6,0,8},
						{9,10,11,12}};

	printMatrix      (matrix,n,m);
	ZeroingRow_Column(matrix,n,m);
	printMatrix      (matrix,n,m);


	return 0;
}