#include<stdio.h>

void wypisz_f (float *poczatek, float *koniec);
void swap(int *a, int *b);

int main(void) {
    float TAB_2[7]={3.21,3.1,24.2,13.43,1.2,0.54}, *TAB_1[7];
    float *(*WSK)[7]=TAB_1;
    float *(*WSK_1)[7]=TAB_1; // wsk is a pointer to 7-el tab of pointers to floats

    for(int i=0;i<7;i++) TAB_1[i]=TAB_2 + i; // i-el of TAB_1 points for i-el of TAB_2

    printf("TAB_2 --> ");   wypisz_f(WSK[0][0],WSK[0][6]);
    
    /*printf("\n%p\n%p\n",(**WSK)++, TAB_1[0]);
    printf("\n%p\n%p\n",**WSK, TAB_1[1]); // very important
    */
    int var = 0;
    int var_1 = 6;

    while(WSK[0][var] != TAB_1[7]) {
        printf("TAB_1 [%d] = %p\n",var++,WSK[0][var]);
    }
    var = 0;
    for(int i=0;i<7/2;i++) {
        swap(WSK[0][var++],WSK[0][var_1--]);
    }

    printf("\nTAB_2 --> ");   wypisz_f(WSK[0][0],WSK[0][6]);

    int *ptr=WSK[0][0];
    for(int i=0;i<7;i++) {
        if(i!=6) WSK[0][i]=WSK[0][i+1];
        else WSK[0][i]=ptr; 
    }

    printf("\nTAB_2 by TAB_2 -> "); for(int i=0;i<7;i++) printf("%f ",TAB_2[i]);
    printf("\nTAB_2 by TAB_1 -> "); for(int i=0;i<7;i++) printf("%f ",*TAB_1[i]); 
}

void wypisz_f (float *poczatek, float *koniec) { 
    while (poczatek <= koniec) 
        printf ("%6.2f", *poczatek++); 
    printf ("\n");    
    return;
}

void swap(int *a, int *b) {
*a=*a+*b;
*b=*a-*b;
*a=*a-*b;
}