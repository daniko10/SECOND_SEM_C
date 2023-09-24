#include<stdio.h>

float * min(float *tab, int n);
float * max(float *tab, int n);
float *min_or_max(float *tab, int n, float * (*f)(float *, int));

int main(void) {
    float tab_A[ ] = {-12.0, 41.5, 3.6, 1.23, 6.15, -32.1};
    float tab_B[ ] = {2.0, 4.0, 6.5, -2.1};

    int n_A = sizeof(tab_A)/sizeof(int);
    int n_B = sizeof(tab_B)/sizeof(int);

    float * min_A = min_or_max(tab_A,n_A,min);
    float * max_A = min_or_max(tab_A,n_A,max);
    printf("tab_A : %.1f\n",*max_A - *min_A);

    float * min_B = min_or_max(tab_B,n_B,min);
    float * max_B = min_or_max(tab_B,n_B,max);
    printf("tab_B : %.1f\n",*max_B - *min_B);
}

float * min(float tab[], int n) {
    if(n<1) return NULL;
    float *minimal_value = tab;
    for(int i=1;i<n;i++) if(*minimal_value>tab[i]) minimal_value = tab + i;
    return minimal_value;
}

float * max(float tab[], int n) {
    if(n<1) return NULL;
    float *maximal_value = tab;
    for(int i=1;i<n;i++) if(*maximal_value<tab[i]) maximal_value = tab + i;
    return maximal_value;
}

float * min_or_max(float *tab, int n, float * (*f)(float *, int)) {
    return (*f)(tab,n);
}