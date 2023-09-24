#include<stdio.h>
#include<stdlib.h>

#define len_1 6
#define len_2 3

//prototypes

int suma (int *p, int len);
void proc_1(int col, int tab[][col], int rows);
int cmp_rows(const void *a, const void *b);
int cmp_sum_rows(const void *a, const void *b);
void print_tab_all(int y,int a[][y], int x);


// main

int main(void) {
    int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
    int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};

    proc_1(6,tab_A,3);
    print_tab_all(6,tab_A,3);
    
    printf("\n");

    proc_2(6,tab_A,3);
    print_tab_all(6,tab_A,3);
}

//


// functions

int suma (int *p, int len) { 
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += p[i];
    return sum;
}

void proc_1(int col, int tab[][col], int rows) {
    for(int i=0;i<rows;i++) qsort(tab[i],col,sizeof(int),cmp_rows);
}

void proc_2(int col, int tab[][col], int rows) {
    qsort(tab,rows,col*sizeof(int), cmp_sum_rows);
}

int cmp_rows(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int cmp_sum_rows(const void *a, const void *b) {
    return suma((int *)a,len_1)-suma((int *)b,len_1);
}

void print_tab_all(int y,int a[][y], int x) {
    int i, j;
    for (i = 0; i < x; i++){
        for (j = 0; j < y; j++)
            printf ("%3d", a[i][j]);
        printf ("\n");   }
    return;
}