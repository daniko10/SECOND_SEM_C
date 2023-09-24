#include<stdio.h>
#include<stdlib.h>
#define N 5
#define M 8

void print_table(int TAB[][M]);

int main() {
    int TAB[N][M];
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) TAB[i][j]=rand()%10;
    //pointer version
    //printing table
    print_table(TAB);
    // 0`s even columns
    int (*wsk)[M]=TAB+2;
    int var=-2;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(j%2) *(*(wsk+var)+j)=0;
        }
        var++;
    }
    printf("\n\n");
    //printing changed table
    print_table(TAB);
    //
    //table version
    var=-2;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(j%2) wsk[var][j]=0;
        }
        var++;
    }
    printf("\n\n");
    print_table(TAB);
}

void print_table(int TAB[][M]) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            printf("%d ",TAB[i][j]);
        }
        printf("\n");
    }
}