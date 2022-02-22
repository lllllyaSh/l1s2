#include<stdio.h>
#include<stdlib.h>

struct Line {
	int n;
	int *a;
};

struct Matrix {
	int lines;
	Line *matr;
};

int getInt(int *);
void erase(Matrix *a);
int input(Matrix *a);
void output(Matrix a);

int getInt(int *a){
	int n;
	do{
		n = scanf_s("%d", a, sizeof(int));
		if(n < 0)
			return 0;
		if(n == 0){
			printf("%s\n", "Error! Please, repeat input");
			scanf_s("%*c", 0);
		}
	} while(n == 0);
	return 1;
}

int input(Matrix *matr){
	int m, i, j;
	int *val;
	do{
		printf("Enter number of lines: \n");
		if(getInt(&m) == 0)
			return 0;
	} while(m < 1);
	matr->lines = m;
	matr -> matr = (Line *)malloc(m * sizeof(Line));
	for(i = 0; i < matr->lines; ++i){
		do{
			printf("Enter number of items in %d line:\n", i + 1);
			if(getInt(&m) == 0){
				matr->lines = i;
				erase(matr);
				return 0;
			}
		}while(m < 1);
		matr->matr[i].n = m;
		val = (int *)malloc(sizeof(int) * m);
		matr->matr[i].a = val;
		printf("Enter values in %d line:\n", i + 1);
		for(j = 0; j < m; ++j, ++p){
			if(getInt(val) == 0){
				matr->lines = i + 1;
				erase(matr);
				return 0;
			}
		}
	}
	return 1;
}


int main(){
	Matrix matr = {0, NULL};
	if(input(&matr) == 0){
		printf
	}
}