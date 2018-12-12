#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

#define WYMIAR 10

void main ()
{
#ifdef _OPENMP
    printf("Kompilator rozpoznaje dyrektywy OpenMP\n");
#endif

    double first = omp_get_wtime();
    double a[WYMIAR][WYMIAR];
    int n,i,j;

    for(i=0;i<WYMIAR;i++) for(j=0;j<WYMIAR;j++) a[i][j]=1.02*i+1.01*j;

    n=WYMIAR;

    double suma=0.0;
    for(i=0;i<WYMIAR;i++) {
        for(j=0;j<WYMIAR;j++) {
            suma += a[i][j];
        }
    }

    printf("Suma wyrazów tablicy: %lf\n", suma);

    omp_set_nested(1);
///////////////////////////////////////////////////
///////////////////////////////////////////////////
    first = omp_get_wtime();
    double suma_parallel=0.0;

    double tabLocW [omp_get_num_procs()];
    for(int i = 0;i<omp_get_num_procs();i++)tabLocW[i]=0;


#pragma omp parallel for ordered default(none) shared(suma_parallel,a,i,tabLocW)
    for(int i=0;i<WYMIAR;i++) {
        double sumaLoc = 0;
        for(int j=0;j<WYMIAR;j++) {
            int id_w = omp_get_thread_num();
            sumaLoc += a[i][j];
#pragma omp ordered
            printf("[%2d,%2d] W(%1d,%1d/%d) \t\t",i,j,id_w,omp_get_thread_num(),omp_get_num_procs());
        }
#pragma omp ordered
        printf("\n");
#pragma omp critical
        suma_parallel+= sumaLoc;
    }


    printf("Suma wyrazów tablicy równolegle: %lf czas:%lf\n", suma_parallel,omp_get_wtime()-first);
///////////////////////////////////////////////////
///////////////////////////////////////////////////
    first = omp_get_wtime();
    suma_parallel=0.0;
    for(int i = 0;i<omp_get_num_procs();i++)tabLocW[i]=0;


#pragma omp parallel for schedule(static,3) ordered default(none) shared(suma_parallel,a,i,tabLocW)
    for(int i=0;i<WYMIAR;i++) {
        double sumaLoc = 0;
        for(int j=0;j<WYMIAR;j++) {
            int id_w = omp_get_thread_num();
            sumaLoc += a[i][j];
#pragma omp ordered
            printf("[%2d,%2d] W(%1d,%1d/%d) \t\t",i,j,id_w,omp_get_thread_num(),omp_get_num_procs());
        }
#pragma omp ordered
        printf("\n");
#pragma omp critical
        suma_parallel+= sumaLoc;
    }


    printf("Suma wyrazów tablicy równolegle: %lf czas:%lf\n", suma_parallel,omp_get_wtime()-first);
///////////////////////////////////////////////////
///////////////////////////////////////////////////
    first = omp_get_wtime();
    suma_parallel=0.0;
    for(int i = 0;i<omp_get_num_procs();i++)tabLocW[i]=0;


#pragma omp parallel for schedule(static) ordered default(none) shared(suma_parallel,a,i,tabLocW)
    for(int i=0;i<WYMIAR;i++) {
        double sumaLoc = 0;
        for(int j=0;j<WYMIAR;j++) {
            int id_w = omp_get_thread_num();
            sumaLoc += a[i][j];
#pragma omp ordered
            printf("[%2d,%2d] W(%1d,%1d/%d) \t\t",i,j,id_w,omp_get_thread_num(),omp_get_num_procs());
        }
#pragma omp ordered
        printf("\n");
#pragma omp critical
        suma_parallel+= sumaLoc;
    }


    printf("Suma wyrazów tablicy równolegle: %lf czas:%lf\n", suma_parallel,omp_get_wtime()-first);
///////////////////////////////////////////////////
///////////////////////////////////////////////////
    first = omp_get_wtime();
    suma_parallel=0.0;
    for(int i = 0;i<omp_get_num_procs();i++)tabLocW[i]=0;


#pragma omp parallel for schedule(dynamic,2) ordered default(none) shared(suma_parallel,a,i,tabLocW)
    for(int i=0;i<WYMIAR;i++) {
        double sumaLoc = 0;
        for(int j=0;j<WYMIAR;j++) {
            int id_w = omp_get_thread_num();
            sumaLoc += a[i][j];
#pragma omp ordered
            printf("[%2d,%2d] W(%1d,%1d/%d) \t\t",i,j,id_w,omp_get_thread_num(),omp_get_num_procs());
        }
#pragma omp ordered
        printf("\n");
#pragma omp critical
        suma_parallel+= sumaLoc;
    }


    printf("Suma wyrazów tablicy równolegle: %lf czas:%lf\n", suma_parallel,omp_get_wtime()-first);
///////////////////////////////////////////////////
///////////////////////////////////////////////////
    first = omp_get_wtime();
    suma_parallel=0.0;
    for(int i = 0;i<omp_get_num_procs();i++)tabLocW[i]=0;


#pragma omp parallel for schedule(dynamic) ordered default(none) shared(suma_parallel,a,i,tabLocW)
    for(int i=0;i<WYMIAR;i++) {
        double sumaLoc = 0;
        for(int j=0;j<WYMIAR;j++) {
            int id_w = omp_get_thread_num();
            sumaLoc += a[i][j];
#pragma omp ordered
            printf("[%2d,%2d] W(%1d,%1d/%d) \t\t",i,j,id_w,omp_get_thread_num(),omp_get_num_procs());
        }
#pragma omp ordered
        printf("\n");
#pragma omp critical
        suma_parallel+= sumaLoc;
    }


    printf("Suma wyrazów tablicy równolegle: %lf czas:%lf\n", suma_parallel,omp_get_wtime()-first);
///////////////////////////////////////////////////
///////////////////////////////////////////////////

}
