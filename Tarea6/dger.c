#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define y_vector "y.txt" //de tamaño Nx1
#define x_vector "x.txt" //de tamaño Mx1

extern void dger_(int *m, int *n, double *alpha, double *x, int *incx, double *y, int *incy, double *a, int *lda);
int main(int argc, char *argv[]){
	arreglo_2d_T A;
	arreglo_1d_T x, y;
	int M=atoi(argv[1]);
	int N=atoi(argv[2]);
	int incx=1;
	double ALPHA;
    ALPHA = 1.0;
    
	A=malloc(sizeof(*A));
	x=malloc(sizeof(*x));
	y=malloc(sizeof(*y));

	renglones(A)=M;
	columnas(A)=N;
	renglones_vector(x)=M;
	renglones_vector(y) = N;
	entradas_vector(y)=malloc(N*sizeof(double));
	inicializa_vector(y,y_vector);

	entradas_vector(x)=malloc(M*sizeof(double));
	inicializa_vector(x,x_vector);

	
    entradas(A)=calloc(M*N,sizeof(double));
    printf("vector x:\n");
	imprime_vector(x);
	printf("------------\n");
	printf("vector y:\n");
	imprime_vector(y);
	printf("------------\n");
	printf("vector resultado:\n");

	dger_(&M, &N, &ALPHA, entradas_vector(x), &incx, entradas_vector(y),&incx, entradas(A), &M);
	imprime_matriz(A);
	
    free(entradas(A));
	free(A);
	free(entradas_vector(x));
	free(x);
	free(entradas_vector(y));
	free(y);
	return 0;
}
