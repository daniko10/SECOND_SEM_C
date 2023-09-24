#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double *my_alloc(int i_min, int i_max); 
void my_free(double **my_tab, int i_min);

int main(void) {
    double *tab=my_alloc(-10,5);
    for(int i=-10;i<=5;i++) { tab[i]=rand()%10; printf("%f ",tab[i]); }

    my_free(&tab,-10);
}

double *my_alloc(int i_min, int i_max) {
    double *tab=malloc(sizeof(double) * (i_max-i_min + 1));
    return tab-i_min;
}

void my_free(double **my_tab, int i_min) {
    free(*my_tab + i_min);
    *my_tab=NULL;
}