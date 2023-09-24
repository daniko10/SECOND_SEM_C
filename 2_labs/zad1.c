#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void wypisz_i (int *poczatek, int *koniec);
int suma(int *tab, int len);

int main() {
    srand(time(NULL));
    int abc[5][4];
    for(int i=0;i<5;i++) for(int j=0;j<4;j++) abc[i][j]=rand()%21-10;
    for(int i=0;i<5;i++) 
        wypisz_i(abc[i],abc[i]+4);
    
    int suma_all = suma(abc[0],sizeof(abc)/sizeof(int));
    printf("\nSum all: %d\n",suma_all);
    int suma_1 = suma(abc[0],(sizeof(abc)/sizeof(int))/2);
    printf("Sum first half: %d\n",suma_1);
    int suma_2 = suma(abc[2]+2,(sizeof(abc)/sizeof(int))/2);
    printf("Sum second half: %d\n",suma_2);

    int MIN_IND_1=find_min_ind(abc[0],abc[2]+2);
    int MIN_IND_2=find_min_ind(abc[2]+2,abc[4]+4);
    int row_1=MIN_IND_1/5;
    int col_1=MIN_IND_1 % 4;
    int row_2=(MIN_IND_2+12)/5;
    int col_2=(MIN_IND_2+2) % 4;
    printf("first [%d][%d]\nsecond [%d][%d]\n",row_1,col_1,row_2,col_2);
    printf("Minimal first half: %d, adress %p\nMinimal second half: %d, adress %p\n",abc[row_1][col_1],abc[row_1]+col_1,abc[row_2][col_2],abc[row_2]+col_2);
}

void wypisz_i (int *poczatek, int *koniec) { 
while (poczatek < koniec) 
    printf ("%4d ", *poczatek++);   
printf ("\n");    
return;
}

int suma(int *tab, int len) { 
int ss = 0.0;
for (int i = 0; i < len; i++)  
    ss+= tab[i]; 
return ss;
}

int find_min_ind (int *T_F, int *T_L) { 
int min = 0;
for (int i = 1; i < T_L - T_F; i++)
    if(T_F[min] > T_F[i]) min = i;
return min;
}