#include<stdio.h>
#include<stdlib.h>

void wypisz_i (int *poczatek, int *koniec);
int fun(int y, int tab[][y], int x, int *value);
int cmp(const void *a, const void *b);

int main(void) {
    int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
    int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};
    int value = -32;

    int row_index = fun(6,tab_A,3,&value);
    
    if(row_index == -1) return 1;
    printf("Index : %d\n",row_index/6);

    wypisz_i(tab_A[row_index/6],tab_A[row_index/6]+6);
}

void wypisz_i (int *poczatek, int *koniec) { 
    while (poczatek < koniec) 
        printf ("%4d ", *poczatek++);   
    printf ("\n");    
    return;
}

int fun(int y, int tab[][y], int x, int *value) {
    int *row = NULL;

    for(int i=0;i<x;i++) qsort(tab[i],y,sizeof(int),cmp);
    for(int i=0;i<x;i++) if(!row) row = bsearch(value,tab[i],y,sizeof(int),cmp);
    
    
    if(!row) {printf("Nie znaleziono!"); return -1;}

    return row-tab[0];
}

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}
