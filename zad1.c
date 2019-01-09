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
int i = 0;
    omp_set_num_threads(4);
#pragma omp parallel for schedule(static,1) ordered
    for(i = 0;i<9;i++){
    #pragma omp ordered
        printf("Watek no.%d i:%d\n",omp_get_thread_num(),i);
    }



//  double first = omp_get_wtime();
//  double a[WYMIAR][WYMIAR];
//  int n,i,j;
//
//  for(i=0;i<WYMIAR;i++) for(j=0;j<WYMIAR;j++) a[i][j]=1.02*i+1.01*j;
//
//  n=WYMIAR;
//
//  double suma=0.0;
//  for(i=0;i<WYMIAR;i++) {
//    for(j=0;j<WYMIAR;j++) {
//      suma += a[i][j];
//    }
//  }
//
//  printf("Suma wyrazów tablicy: %lf czas:%lf\n", suma,omp_get_wtime()-first);
//
//  omp_set_nested(1);
////////////////////////////////////////////////////
////////////////////////////////////////////////////
//  first = omp_get_wtime();
//  double suma_parallel=0.0;
//
//#pragma omp parallel for reduction(+:suma_parallel) ordered default(none) shared(a)
//  for(int i=0;i<WYMIAR;i++) {
//    int id_w = omp_get_thread_num();
//    for(int j=0;j<WYMIAR;j++) {
//      suma_parallel += a[i][j];
//#pragma omp ordered
//             printf("[%d,%d] W(%1d,%1d/%d) ",i,j,id_w,omp_get_thread_num(),omp_get_num_procs());
//    }
//#pragma omp ordered
//        printf("\n");
//
//  }
//  printf("Suma wyrazów tablicy równolegle: %lf czas:%lf\n", suma_parallel,omp_get_wtime()-first);
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
//  suma_parallel=0.0;
//    first = omp_get_wtime();
//#pragma omp parallel for schedule(static,3) reduction(+:suma_parallel) ordered default(none) shared(a)
//  for(int i=0;i<WYMIAR;i++) {
//    int id_w = omp_get_thread_num();
//    for(int j=0;j<WYMIAR;j++) {
//      suma_parallel += a[i][j];
//#pragma omp ordered
//             printf("[%d,%d] W(%1d,%1d/%d) ",i,j,id_w,omp_get_thread_num(),omp_get_num_procs());
//    }
//#pragma omp ordered
//    printf("\n");
//
//  }
//
//  printf("Suma wyrazów tablicy równolegle(static,3): %lf czas:%lf\n", suma_parallel,omp_get_wtime()-first);
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
//    suma_parallel=0.0;
//    first = omp_get_wtime();
//#pragma omp parallel for schedule(static) reduction(+:suma_parallel) ordered default(none) shared(a)
//    for(int i=0;i<WYMIAR;i++) {
//        int id_w = omp_get_thread_num();
//        for(int j=0;j<WYMIAR;j++) {
//            suma_parallel += a[i][j];
//#pragma omp ordered
//            printf("[%d,%d] W(%1d,%1d/%d) ",i,j,id_w,omp_get_thread_num(),omp_get_num_procs());
//        }
//#pragma omp ordered
//        printf("\n");
//
//    }
//
//    printf("Suma wyrazów tablicy równolegle(static): %lf czas:%lf\n", suma_parallel,omp_get_wtime()-first);
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
//    suma_parallel=0.0;
//    first = omp_get_wtime();
//#pragma omp parallel for schedule(dynamic,2) reduction(+:suma_parallel) ordered default(none) shared(a)
//    for(int i=0;i<WYMIAR;i++) {
//        int id_w = omp_get_thread_num();
//        for(int j=0;j<WYMIAR;j++) {
//            suma_parallel += a[i][j];
//#pragma omp ordered
//             printf("[%d,%d] W(%1d,%1d/%d) ",i,j,id_w,omp_get_thread_num(),omp_get_num_procs());
//        }
//#pragma omp ordered
//        printf("\n");
//
//    }
//
//    printf("Suma wyrazów tablicy równolegle(dynamic,2): %lf czas:%lf\n", suma_parallel,omp_get_wtime()-first);
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
//    suma_parallel=0.0;
//    first = omp_get_wtime();
//#pragma omp parallel for schedule(dynamic) reduction(+:suma_parallel) ordered default(none) shared(a)
//    for(int i=0;i<WYMIAR;i++) {
//        int id_w = omp_get_thread_num();
//        for(int j=0;j<WYMIAR;j++) {
//            suma_parallel += a[i][j];
//#pragma omp ordered
//            printf("[%d,%d] W(%1d,%1d/%d) ",i,j,id_w,omp_get_thread_num(),omp_get_num_procs());
//        }
//#pragma omp ordered
//        printf("\n");
//
//    }
//
//    printf("Suma wyrazów tablicy równolegle(dynamic): %lf czas:%lf\n", suma_parallel,omp_get_wtime()-first);
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////



}
