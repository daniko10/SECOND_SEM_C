#include<stdio.h>

void swap(int *, int *);
void transplant(int abc[][5]);

int main() {
    int abc[5][5];
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) abc[i][j]=j;
    printf("Przed transplantacja: \n");
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++)    printf("TAB[%d][%d] = %d, ",i,j,abc[i][j]);
        printf("\n");
    }
    transplant(abc);
    printf("\nPo transplantacji: \n");
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++)    printf("TAB[%d][%d] = %d, ",i,j,abc[i][j]);
        printf("\n");
    }
    printf("\nWypisywanie wartosci nad jedna przekatna: \n");
    for(int i=0;i<5;i++){ for(int j=0;j<5;j++) if(j<i) printf(" "); else printf("%d",abc[i][j]); printf("\n");}

    
}

void transplant(int abc[][5]) {
    int var=0;
    for(int i=0;i<5;i++)
        for(int j=i;j<5;j++) {
            swap(abc[i]+j,abc[j]+i);
        }
}

void swap (int *p_1, int *p_2) { 
int temp = *p_1;
*p_1 = *p_2;
*p_2 = temp;
 return ;
 }