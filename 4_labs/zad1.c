#include<stdio.h>

void swap(int *a, int *b);
void swap_tab(int *A, int *B, int n);
void swap_rows(int n, int (*TAB)[n], int x, int y);
void wypisz_i (int *poczatek, int *koniec);

int main() {
    int tab_1[4][5] = {{1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3},{4,4,4,4,4}};
    int tab_22 [5][2] = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    printf("TAB 1: \n");
    printf("Before : \n");
    for(int i=0;i<4;i++)    wypisz_i(tab_1[i],tab_1[i]+5);
    printf("\nAfter : \n");
    swap_rows(5,tab_1,0,2);
    for(int i=0;i<4;i++)    wypisz_i(tab_1[i],tab_1[i]+5);
    printf("\nTAB 2: \n");
    printf("Before : \n");
    for(int i=0;i<5;i++)    wypisz_i(tab_22[i],tab_22[i]+2);
    printf("\nAfter : \n");
    swap_rows(2,tab_22,0,1);
    for(int i=0;i<5;i++)    wypisz_i(tab_22[i],tab_22[i]+2);
}

void swap_tab(int *A, int *B, int n) {
    for(int i=0;i<n;i++) swap(A+i,B+i);
}

void swap_rows(int n, int (*TAB)[n], int x, int y) {
    swap_tab(TAB[x],TAB[y],n);
}

void swap(int *a, int *b) {
*a=*a+*b;
*b=*a-*b;
*a=*a-*b;
}

void wypisz_i (int *poczatek, int *koniec) { 
    while (poczatek < koniec) 
        printf ("%4d ", *poczatek++);   
    printf ("\n");    
    return;
}