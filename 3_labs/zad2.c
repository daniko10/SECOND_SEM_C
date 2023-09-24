#include<stdio.h>
#include<stdlib.h>

int main() {
    int size, n;
    int *arg_p=NULL;
    int *arg_n=NULL;
    int *ptr=NULL;
    int even=0;
    int not_even=0;

    printf("Enter size: ");
    scanf("%d",&size);

    n=size;
    if(size==0) return 1;
    int *tab=malloc(sizeof(int)*size);
    for(int i=0;i<size;i++) { tab[i]=rand()%11-5; printf("%d ",tab[i]); }
    for(int i = size-1 ;i>=0;i--) {
        if(tab[i]%2==0 || tab[i]==0) {
            even++;
            arg_p=realloc(arg_p,sizeof(int)*even);
            arg_p[even-1]=tab[i];
        } else {
            not_even++;
            arg_n=realloc(arg_n,sizeof(int)*not_even);
            arg_n[not_even-1]=tab[i];
        }
        n--;
        tab=realloc(tab,sizeof(int)*n);
    }
    printf("\n");
    for(int i=0;i<even;i++) printf("%d ",arg_p[i]);
    printf("\n");
    for(int i=0;i<not_even;i++) printf("%d ",arg_n[i]);
    if(!tab) printf("\nTAB -> NULL");
    free(tab);
}