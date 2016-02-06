//anagrammic10.c

//anagrammic7.c

//#define _CRTDBG_MAP_ALLOC
//#include<crtdbg.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>


#define height 6
#define width 997

int anagrammic(char text[100]);

int main(int argc, char const *argv[])
{
	int t;

	char n[1000];
	int i = 0;
	int s = 0;
	scanf("%d", &t);

	for (i; i<t; i++) {
		scanf("%s", n);
		anagrammic(n);
		//for (s; i<100;s++) {
			//n[s] = 0;
		//}
	}
	return 0;
}

int anagrammic(char text[100]) {


	char* s;
	int slen = strlen(text);
	s = (char*)malloc(slen * sizeof(char));
	strcpy(s,text);

	int count;
	long square[255];
	int cummulative[100];

	int i = 97;
	for (i; i <= 122; i++) {
		square[i] = i*i*i;
	}

	int sum = 0;
	int k = 0;

	for (k; k<100; k++) {
		sum += k;
		cummulative[k] = sum;
	}



	int idxf = slen;
	int hossz = 0;
	count = 0;
	int utkozes = 0;

	long a1[height][width];
	int b1[height][width];

	for (i = 0; i<idxf - 1; i++) {
		hossz++;
		int n;
		for (k = 0; k<height; k++) {
			for (n = 0; n<width; n++) {
				a1[k][n] = 0;
				b1[k][n] = 0;
			}
		}
		int j = 1;
		while (j <= slen - hossz + 1) {
			long Dx = 0;
			for (k = 0; k < hossz; k++) {
				Dx = Dx + square[(long)(char)s[k + j - 1]];
			}

			int Xx = Dx%width;
			int p = 0;
			int bool = 0;
			do
			{
				if (a1[p][Xx] > 0) {
					if (a1[p][Xx] == Dx) {
						b1[p][Xx] = b1[p][Xx] + 1;
						bool = 1;
					}
					else {
						p++;

					}
				}
				else {
					a1[p][Xx] = Dx;

					bool = 1;
				}


			} while ((p < height) && (bool == 0));

			if (p >= height) {
				utkozes++;
				//printf("Out of Bounds!!!");
			}
			j++;
		} //nagy while

		int f = 0;
        int fg = 0;
		for (f = 0; f<width; f++) {
            for (fg= 0;fg<height;fg++){

			count = count + cummulative[b1[fg][f]];
            }
		}

	} // for
	fprintf(stdout, "%d\n", count);

	return 0;

}