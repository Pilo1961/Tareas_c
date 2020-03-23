
#include<stdio.h>
#include<stdlib.h>
#include"definiciones.h"
#define A_matriz "A.txt" //de tamaño NxN

//funciones BLAS
extern void dgemv_(char *transpose_a, int *m, int *n, double *alpha, double *a, int *lda, double *x, int *incx, double *beta, double *y, int *incy);
extern void dcopy_(int *j,double *a_hat,int *incx,double *z,int *incy);
extern void dscal_(int *N,double *scal,double *v,int *incx);
extern void dtrsv_(char *uplo, char *trans, char *diag, int *N, double *L, int *j, double *x, int *i);

//funciones definidas 
void copia_columna(arreglo_2d_T A, arreglo_1d_T v,int N, int j);
void copia_vector_matriz(arreglo_2d_T A, arreglo_1d_T v,int desde, int hasta, int col, int desfase);
void corta_matriz(arreglo_2d_T A, arreglo_2d_T A_mas,int N, int j);
void corta_vector(arreglo_1d_T original, arreglo_1d_T vector_corto, int N, int j);


int main(int argc, char *argv[]){	
    arreglo_2d_T A, L, U, L2;
	arreglo_1d_T v, a_hat, z;
    int N=atoi(argv[1]);    
    int incx=1,rows_l2,i,j,jj;
    double ALPHA=-1,BETA=1,scal;
    char uplo='L', trans='N', diag='U';
    
    //inicio A
	A=malloc(sizeof(*A));
    renglones(A)=N;
	columnas(A)=N;
    entradas(A)=malloc(renglones(A)*columnas(A)*sizeof(double));
    inicializa_matriz(A,A_matriz);
    
    //inicio L
    L=malloc(sizeof(*L));
    renglones(L)=N;
	columnas(L)=N;
    entradas(L)=malloc(renglones(L)*columnas(L)*sizeof(double));
    
    //inicio U
    U=malloc(sizeof(*U));
    renglones(U)=N;
	columnas(U)=N;
    entradas(U)=malloc(renglones(U)*columnas(U)*sizeof(double));
    
    //llena matrices L y U
    for(i=0;i<N;i++)
        for(j=0;j<N;j++){
            if(i==j)
                entrada(L,i,j)=1;
            else
                entrada(L,i,j)=0;
            entrada(U,i,j)=0;
        }
    
    //inicio vectores
	v=malloc(sizeof(*v));   
    renglones_vector(v)=N;
    entradas_vector(v)=calloc(N,sizeof(double));
    
    a_hat=malloc(sizeof(*a_hat));
	renglones_vector(a_hat) = N;
    entradas_vector(a_hat)=calloc(N,sizeof(double));

    z=malloc(sizeof(*z));
    renglones_vector(z) = N;
    entradas_vector(z)=malloc(N*sizeof(double));

	for(j=0;j<N;j++){
        if(j==0)
            //En j=0 no usamos a_hat
            copia_columna(A,v,N,0);
        else{
            copia_columna(A,a_hat,N,j);
            //copio el vector a_hat en z para usarlo en la funcion fortran
            jj=j+1; //al llamar funciones fortran uso indices j+1
            dcopy_(&jj,entradas_vector(a_hat),&incx,entradas_vector(z),&incx);
            
            //resuleve el sistema L*z1=z. z1 sobreescribe z y se llama z
            jj=j+1;
            dtrsv_(&uplo,&trans,&diag,&jj,entradas(L),&jj,entradas_vector(z),&incx);
            
            //copia el vector solucion z en U, en la columna j
            copia_vector_matriz(U,z,0,j,j,0);
            
            /*
            Inicia y llena matriz L2. Se hace aqui para que borre la del ciclo anterior. 
            La matriz L2 es la matriz L(j:n,:)
            */
            
            L2=malloc(sizeof(*L2));
            renglones(L2)=N-j;
            columnas(L2)=N;
            entradas(L2)=realloc(entradas(L2),renglones(L2)*columnas(L2)*sizeof(double));
            corta_matriz(L,L2,N,j);
            
            //corta el vector v. nos deja con v(j:n)
            corta_vector(a_hat,v,N,j);
            
            /*
            resuelve el sistema v=-L(j:n,1:j-1)*z+a_hat
            Limitamos el número de columnas en la matriz L por medio del parametro jj
            En este caso no usamos el indice j+1 por como esta construida la matriz L2
            */
            rows_l2=N-j;
            jj=j;
            dgemv_(&trans, &rows_l2, &jj, &ALPHA, entradas(L2), &rows_l2, entradas_vector(z), &incx,&BETA,entradas_vector(v),&incx);
            }
        
        //calcula la entrada de la diagonal de U
        entrada(U,j,j)=entrada_vector(v,0);
        
        //checa que no sea cero y se haga la division
        if(entrada_vector(v,0)!=0){
            scal=1/entrada_vector(v,0);
            dscal_(&N,&scal,entradas_vector(v),&incx);
        }
        
        //actualiza la matriz L
        copia_vector_matriz(L,v,1,N-j,j,j);
    
    }
    
	printf("matriz 1:\n");
	imprime_matriz(A);
	printf("------------\n");
    
    
	printf("matriz L\n");
	imprime_matriz(L);
	printf("------------\n");
    
	printf("matriz U:\n");
	imprime_matriz(U);
	printf("------------\n");
    
	free(entradas(A));
	free(A);
	free(entradas(L));
	free(L);
    free(entradas(U));
	free(U);
    free(entradas(L2));
    free(L2);
	free(entradas_vector(v));
	free(v);
	free(entradas_vector(a_hat));
	free(a_hat);
	free(entradas_vector(z));
	free(z);

    return 0;
}

void copia_columna(arreglo_2d_T A, arreglo_1d_T v,int N, int j){
    int i=0;
    for(i=0;i<N;i++)
        entrada_vector(v,i)=entrada(A,i,j);
}

void copia_vector_matriz(arreglo_2d_T A, arreglo_1d_T v,int desde, int hasta, int col, int desfase){
    int i;
    for(i=desde;i<=hasta;i++){
        entrada(A,i+desfase,col)=entrada_vector(v,i);
    }
}

void corta_matriz(arreglo_2d_T A, arreglo_2d_T A_mas,int N, int j){
    int i,k;
    for(i=j;i<N;i++)
        for(k=0;k<N;k++)
            entrada(A_mas,i-j,k)=entrada(A,i,k);   
}


void corta_vector(arreglo_1d_T original, arreglo_1d_T vector_corto, int N, int j){
    int i;
    for(i=0;i<N-j;i++)
            entrada_vector(vector_corto,i)=entrada_vector(original,i+j); 
    for(i=N-j;i>N;i++);
        entrada_vector(vector_corto,i)=0;
}
