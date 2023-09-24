#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int suma (int *p, int len);
void wypisz_i (int *poczatek, int *koniec);
int cmp_1(const void *a, const void *b);
int cmp_2(const void *a, const void *b);
int cmp_3(const void *a, const void *b);
int cmp_4(const void *a, const void *b);
int cmp_5(const void *a, const void *b);

int main(void) {

    srand(time(NULL));

    int var, *ptr_var = NULL;

    // creating tabs

    int **tab_3 = malloc( 15*sizeof(int*));
    for(int i = 0; i < 15; i++)  
    tab_3[i] = malloc(10 * sizeof(int));

    int **tab_33 = malloc( 15 * sizeof(int*));
    tab_33[0] = malloc(10 * 15 * sizeof(int));
    for(int i = 1; i < 15; i++)  
        tab_33[i] = tab_33[i-1] + 10 ;

    int (*tab_333)[10] = malloc(10 * 15 * sizeof(int));

    //

    // inserting values
    for(int i=0;i<15;i++) for(int j=0;j<10;j++) { tab_3[i][j]  =  rand() % 21; tab_33[i][j]  =  rand() % 21; tab_333[i][j]  =  rand() % 21;}

    // (1)

    for(int i=0;i<15;i++) {
        qsort(tab_3[i],10,sizeof(int), cmp_1);
        qsort(tab_33[i],10,sizeof(int), cmp_1);
        qsort(tab_333[i],10,sizeof(int) , cmp_1);
    }

    //
    
    for(int i=0;i<15;i++) wypisz_i(tab_333[i],tab_333[i]+10);

    qsort(tab_3,15,sizeof(int *), cmp_2);
    qsort(tab_33,15,sizeof(int *), cmp_2);
    qsort(tab_333,15,sizeof(int)*10, cmp_3);

    printf("\n\n");

    for(int i=0;i<15;i++) wypisz_i(tab_333[i],tab_333[i]+10);

    printf("\nEnter var value: "); scanf("%d",&var);
    ptr_var = &var;

    int **ptr_1 = NULL;
    int **ptr_2 = NULL;
    int *ptr_3 = NULL;

    ptr_1=bsearch(&ptr_var,tab_3,15,sizeof(int *),cmp_4);
    ptr_2=bsearch(&ptr_var,tab_33,15,sizeof(int *),cmp_4);

    for(int i=0;i<15;i++) if(!ptr_3) ptr_3=bsearch(ptr_var,tab_333,15,sizeof(int)*10,cmp_5);

    if(ptr_1) { printf("\nFOUND var in tab_3\n"); wypisz_i(*ptr_1,*ptr_1+10);}
    if(ptr_2) { printf("\nFOUND var in tab_33\n"); wypisz_i(*ptr_2,*ptr_2+10);}
    if(ptr_3) { printf("\nFOUND var in tab_333\n"); wypisz_i(ptr_3,ptr_3+10);}
}
int suma (int *p, int len) { 
    int sum = 0;
  
    for (int i = 0; i < len; i++)
        sum += p[i];
  
    return sum;
}


int cmp_1(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int cmp_2(const void *a, const void *b) {
    if(suma(*(int **)a,10) - suma(*(int **)b,10) < 0) return -1;
    else if(suma(*(int **)a,10) - suma(*(int **)b,10) == 0) return 0;
    return 1;
}

void wypisz_i (int *poczatek, int *koniec) { 
    int *temp = poczatek;
    while (poczatek < koniec) 
        printf ("%4d ", *poczatek++);   
     printf ("%d\n",suma(temp,10));    
    return;
}

int cmp_3(const void *a, const void *b) {
    return suma((int *)a,10) - suma((int *)b,10);
}

int cmp_4(const void *a, const void *b) {
    return **(int **)a - suma(*(int **)b,10);
}

int cmp_5(const void *a, const void *b) {
    return *(int *)a - suma((int *)b,10);

}