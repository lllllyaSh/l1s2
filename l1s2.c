#include<stdio.h>
#include<stdlib.h>

typedef struct Line{
	int n;
	int *a;
}Line;

typedef struct Matrix {
	int lines;
	Line *matr;
}Matrix;

int getInt(int *);
void erase(Matrix *a);
int input(Matrix *a);
void output(Matrix a);
Matrix newmatr(int i, Matrix *a);

Matrix newmatr(int i, Matrix *a){



}

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
	int m, i, j, q; // q-òóþ ñòðîêó èçìåíèòü
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
		for(j = 0; j < m; ++j, ++val){
			if(getInt(val) == 0){
				matr->lines = i + 1;
				erase(matr);
				return 0;
			}
		}
	}
	printf("Enter number of line which needed to change:\n");
	if(getInt(&q) == 0){
		return 0;
	return 1;
}

void erase(Matrix *a){
	int i;
	for(i = 0; i < a->lines; i++){
		free(a->matr[i].a);
		free(a->matr);
		a->lines = 0;
		a->matr = NULL;
	}
}


int main(){
	Matrix matr = {0, NULL};
	if(input(&matr) == 0){
		printf("End of file occured\n");
		return 1;
	}
	//res = newmatr(i, matr);
	printf("Source matrix:\n");
	output(matr);
	printf("\n");
	printf("New matrix:\n");
	//output(res);
	return 0;
}
