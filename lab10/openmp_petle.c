#include<stdlib.h>
#include<stdio.h>
#include<omp.h>
#include<math.h>

#define N 1000000

int main(){
    omp_set_num_threads(4);
    int num;
    int i;
    double *A = (double*)malloc(sizeof(double)*(N+2));
    double *B = (double*)malloc(sizeof(double)*(N+2));
    double suma;

    for(i=0;i<N+2;i++) A[i] = (double)i/N;
    for(i=0;i<N+2;i++) B[i] = 1.0 - (double)i/N;

    double t1 = omp_get_wtime();
    for(i=0; i<N; i++){
        A[i] += A[i+2] + sin(B[i]);
    }
    t1 = omp_get_wtime() - t1;

    suma = 0.0;
    for(i=0;i<N+2;i++) suma+=A[i];
    printf("suma %lf, czas obliczen %lf\n", suma, t1);



    for(i=0;i<N+2;i++) A[i] = (double)i/N;
    for(i=0;i<N+2;i++) B[i] = 1.0 - (double)i/N;

    t1 = omp_get_wtime();
    double *A1 = (double*)malloc(sizeof(double)*(N));;
    for(int i = 0;i<N;i++){
        A1[i]= A[i+2];
    }

#pragma omp parallel for schedule(static)
    for(i=0; i<N; i++){
        A[i] += A1[i] + sin(B[i]);
    }

    t1 = omp_get_wtime() - t1;

    suma = 0.0;
    for(i=0;i<N+2;i++) suma+=A[i];
    printf("suma %lf, czas obliczen rownoleglych %lf\n", suma, t1);



    t1 = omp_get_wtime();


#pragma omp parallel for
    for(i=0; i<N; i++){
        A[i] += A[i] + sin(B[i]);
    }

    t1 = omp_get_wtime() - t1;

    suma = 0.0;
    for(i=0;i<N+2;i++) suma+=A[i];
    printf("suma %lf, czas obliczen rownoleglych dla wariantu idealnego %lf\n", suma, t1);




    printf("N:%d threads:%d\n",N,num);

}