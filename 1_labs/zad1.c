#include<stdio.h>
#include<stdlib.h>

void swap(int*a, int*b);
int *find_min_wsk (int *, int );
void sort(int *,int *);

int main(void) {
    int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,22,12,6,8,4,44,6,42,2,16,5,33,1,7,9,55,1,11,22,34,78,11,21,9,12,5,3,9};
    int size_tab=sizeof(tab_A)/sizeof(int);
    printf("Sizeof tab: %d\n",size_tab);
    int *minimal_pts=find_min_wsk(tab_A,size_tab);
    printf("Minimal int TAB_A: %d\n",*minimal_pts);

    int *minimal_10_each=find_min_wsk(tab_A,10);
    int first = 0;
    int last = 9;
    for(int i=0;i<=size_tab/10;i++) {
        printf("Zakres %d - %d --> ",i*10,i*10+9);
        for(int j=first;j<=last;j++) {
            printf("tab[%d] = %d, ",j,tab_A[j]);
        }
        printf("\nMinimal = %d, adress = %p, index = %d",*minimal_10_each,minimal_10_each,minimal_10_each-tab_A);
        if((i+1)*10<size_tab && (last+10)<size_tab) {
            first+=10;
            last+=10;
            minimal_10_each=find_min_wsk(tab_A+(i+1)*10,10);
        }
        else {
            
            last=size_tab-1;
            first+=10;
            minimal_10_each=find_min_wsk(tab_A+(i+1)*10,size_tab-first);
        }
        printf("\n\n");
    }
    //sort each 10 by sort procedure
    sort(tab_A,tab_A+size_tab);
    for(int i=0;i<sizeof(tab_A)/sizeof(int);i++) printf("%d ",tab_A[i]);
}

int *find_min_wsk(int *tab, int n) {
    int *min_local=tab;
    for(int i=1;i<n;i++) {
        if(*min_local>tab[i]) min_local = tab+i;
    }
    return min_local;
}

void swap(int*a, int*b){
int temp = *a;
*a = *b;
*b = temp;
return;
}

void sort(int *first, int *last){
    
    int size_tab=last-first;
    int i=0, var=0, up=10;

    int *min=NULL;
    
    while(i<size_tab) {
        while(var<up) {
            min=find_min_wsk(first+i+var,up-var);
            swap(min,first+i+var); // we check it as a 10 elements table and then sort it
            var++;
        }
        var=0;
        if((i+1)<size_tab && (i+9+10)<size_tab) up=10; // no changes
        else up=size_tab-i;
        i+=10;
    }
}

