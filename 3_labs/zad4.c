#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int *fun(double *ptr_1, double * ptr_2);

int main(void) {
    double first = 14.0;
    double second = 21.3;
    double *ptr_1=&first, *ptr_2=&second;
    
    int *var = fun(ptr_1,ptr_2);
    printf("result : %d",*var);
    free(var);
}

int *fun(double *ptr_1, double * ptr_2) {
    int *wynik=malloc(sizeof(double));
    wynik[0]=floor(*ptr_1 * *ptr_2);
    return wynik;
}