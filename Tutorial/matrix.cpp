#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//az én részem

class Matrix 
{
    public:
        vector<int> a;
        Matrix operator+(Matrix);
};


Matrix::Matrix() {

}

Matrix Matrix::operator+(Matrix other) {
    Matrix brandNew;

    unsigned int i;
    unsigned int j;
	unsigned int asize = other.a.size();
	unsigned int aasize = other.a[0].size();

    for (i = 0; i < asize; i++){
        for (j = 0; j<aasize;j++){
            brandNew.a[i][j] = a[i][j] + other.a[i][j];
        }
    }

}
//endof én részem


int main () {

   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }
   return 0;
}
