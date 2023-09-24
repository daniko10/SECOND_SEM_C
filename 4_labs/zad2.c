#include<stdio.h>

void swap(int *a, int *b);
void swap_tab(int *A, int *B, int n);
void swap_rows(int n, int (*TAB)[n], int x, int y);
int suma (int *tab, int len);
void wypisz_i (int *poczatek, int *koniec);

int main(void) {
    int tab_A[3][6] = {{1,-4,1,2,11},{12,2,-32,2},{72,2,-32,2}};
    printf("BEFORE : \n");
    for(int i=0;i<3;i++)    wypisz_i(tab_A[i],tab_A[i]+6);
    
    proc(6,tab_A,3);
    
    printf("\nAFTER : \n");
    for(int i=0;i<3;i++)    wypisz_i(tab_A[i],tab_A[i]+6);
}
void proc(int y, int TAB[][y], int x) {
    int tab_sum_el[x];
    int min_index;
    
    for(int i=0;i<x;i++) tab_sum_el[i]=suma(TAB[i],y);
    for(int i=0;i<x-1;i++) {
        min_index=i;
        for(int j=i+1;j<x;j++) {
            if(tab_sum_el[min_index]>tab_sum_el[j]) min_index=j;
        }
        if(i!=min_index) swap_rows(y,TAB,i,min_index);
    }
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

int suma (int *tab, int len) { 
    int ss = 0.0;
    for (int i = 0; i < len; i++)  
        ss+= tab[i]; 
    return ss;
}

void wypisz_i (int *poczatek, int *koniec) { 
    while (poczatek < koniec) 
        printf ("%4d ", *poczatek++);   
    printf ("\n");    
    return;
}