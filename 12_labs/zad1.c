#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MIN 100
#define MAX 150

struct elastyna {
    int len;
    int *tab;
};

struct elastyna * insert(struct elastyna *temp);
void print(struct elastyna *temp);
int cmp(const void *a, const void *b);

int main(void) {
    srand(time(NULL));

    struct elastyna *TAB_PTR[5];

    for(int i=0; i<5; i++) TAB_PTR[i] = insert(TAB_PTR[i]);
    
    printf("BEFORE SORTING:\n");
    
    for(int i=0; i<5; i++) print(TAB_PTR[i]);
    
    printf("\nAFTER SORTING:\n");
    
    qsort(TAB_PTR,5,sizeof(struct elastyna *), cmp);
    for(int i=0; i<5; i++) print(TAB_PTR[i]);

}

struct elastyna * insert(struct elastyna *temp) {
    temp = malloc(sizeof(struct elastyna));
    temp->len = rand()%(MAX - MIN + 1) + MIN;
    temp->tab = malloc(sizeof(int)*temp->len);

    temp->tab[0] = rand()%9 + 1;
    for(int i=1; i<temp->len ; i++) temp->tab[i] = rand()%10;

    return temp;
}

void print(struct elastyna *temp) {
    for(int i=0; i<temp->len ; i++) printf("%d",temp->tab[i]);
    printf("\n");
}

int cmp(const void *a, const void *b) {
    struct elastyna *first = *(struct elastyna **)a;
    struct elastyna *second = *(struct elastyna **)b;

    if(first->len < second->len) return -1;
    else if(first->len > second->len) return 1;
    else {
        for(int i=0; i<first->len; i++) {
            if(first->tab[i] < second->tab[i]) return -1;
            else if(first->tab[i] > second->tab[i]) return 1;
        }
    }

    return 0;
}