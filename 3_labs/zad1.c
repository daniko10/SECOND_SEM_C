#include<stdio.h>

void wypelnij(double tab[][6],int rows);
void wypisz_d (double *poczatek, double *koniec);

int main(void) {
    double A_1[8][6]={0.0};
    double A_2[10][6]={1.0};

    wypelnij(A_1,8);
    wypelnij(A_2,10);

    printf("First table (1):\n");
    for(int i=0;i<8;i++)    wypisz_d(A_1[i],A_1[i]+6);
    printf("\nSecond table (1):\n");
    for(int i=0;i<10;i++) wypisz_d(A_2[i],A_2[i]+6);
    
    printf("\n\n");
    
    printf("First table (2):\n");
    wypisz_d(A_1[0],A_1[7]+6);
    printf("\nSecond table (2):\n");
    wypisz_d(A_2[0],A_2[9]+6);
    
}

void wypelnij(double tab[][6],int rows) {
    double var=0.0;
    for(int i=0;i<rows;i++) 
        for(int j=0;j<6;j++) { 
            tab[i][j]=var+=0.4; 
        }
}

void wypisz_d (double *poczatek, double *koniec) { 
while (poczatek < koniec) 
    printf ("%6.2f", *poczatek++); 
printf ("\n");    
return;
}