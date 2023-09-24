#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void typical_sort(int tab[], int size);
void swap(int *, int *);

int main() {
    srand(time(NULL));
    int size=rand()%20+10;
    int tab[size], n=size;
    
    for(int i=0;i<size;i++) { tab[i]=rand()%20; printf("-"); }
    printf("\nBefore: \n");
    for(int i=0;i<size;i++) printf("%d ",tab[i]);
    
    typical_sort(tab,size);
    
    printf("\nAfter: \n");
    for(int i=0;i<n;i++) printf("%d ",tab[i]);
    printf("\n");
}
void typical_sort(int tab[], int size) {
    int i=-1;
    for(int j=0;j<size;j++) {
        if(tab[j]%2==0) {
            i++;
            if(i!=j) swap(tab + j, tab + i);
        }
    }
}

void swap(int *a, int *b) {
*a=*a+*b;
*b=*a-*b;
*a=*a-*b;
}