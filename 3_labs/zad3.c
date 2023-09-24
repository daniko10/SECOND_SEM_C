#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5
#define M 8

int find_min_ind (int *T_F, int *T_L);
int tab_min(int tab[][M], int rows);
int row_number(int TAB[][M], int rows);
void wypisz_i (int *poczatek, int *koniec);

int main() {
    srand(time(NULL));
    
    int TAB[N][M];
    
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) TAB[i][j]=rand()%2323-5;
    int *tab_index=tab_min(TAB,N);
    //finding smallest one in TAB by tab_index
    int minimal_val=TAB[0][tab_index[0]];
    for(int i=1;i<N;i++) {
        if(minimal_val>TAB[i][tab_index[i]]) minimal_val=TAB[i][tab_index[i]];
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) printf("%d ",TAB[i][j]); printf("\n");
    }
    // smallest value anywhere
    printf("\nSmallest : %d\n",minimal_val);
    
    int minimal_row = row_number(TAB,N);
    //after finding row with minimal value : 
    wypisz_i(TAB[minimal_row],TAB[minimal_row]+M);
    free(tab_index);
}

int find_min_ind (int *T_F, int *T_L) { 
    int min = 0;
    for (int i = 1; i < T_L - T_F; i++)
        if(T_F[min] > T_F[i]) min = i;  
    return min;
}

int tab_min(int TAB[][M], int rows) {
    int *tab_index=malloc(sizeof(int)*rows);
    int var=0;
    for(int i=0;i<rows;i++) tab_index[i]=find_min_ind(TAB[i],TAB[i]+M);
    return tab_index;
}

int row_number(int TAB[][M], int rows) {
    int min=TAB[0][0];
    int row=0;
    for(int i=0;i<rows;i++) {
        int *col=tab_min(TAB+i,1);
        if(min>TAB[i][*col]) {
            min=TAB[i][*col];
            row=i;
        }
    }
    return row;
}

void wypisz_i (int *poczatek, int *koniec) { 
    while (poczatek < koniec) 
        printf ("%4d ", *poczatek++);   
    printf ("\n");    
    return;
}