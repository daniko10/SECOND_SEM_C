#include<stdio.h>
#include<stdlib.h>

int (* multi_tab(int y1,int tab_A[][y1], int x1, int y2, int tab_B[][y2], int x2))[];
void print_tab_all(int y,int a[][y], int x);

int main(void) {
    printf("FIRST: \n");
    int tab_A [2][3] = {{1,2,3},{4,5,6}};
    int tab_B [3][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1}};

    int (*result_1)[4]=multi_tab(3,tab_A,2,4,tab_B,3);
    
    print_tab_all(4,result_1,2);

    printf("SECOND: \n");
    int tab_C [4][2] = {{1,2},{2,5},{1,0},{1,5}};
    int tab_D [2][2] = {{1,-1},{1,0}};

    int (*result_2)[2]=multi_tab(2,tab_C,4,2,tab_D,2);

    print_tab_all(2,result_2,4);
}

int (* multi_tab(int y1,int tab_A[][y1], int x1, int y2, int tab_B[][y2], int x2))[] {
    if(x2!=y1) return NULL;
    
    int (*result)[y2]=malloc(sizeof(int) * x1 * y2);
    
    for(int i=0;i<x1;i++) {
        for(int j=0;j<y2;j++) {
            result[i][j]=0;
            for(int k=0;k<x2;k++) {
                result[i][j]= result[i][j] + tab_A[i][k]*tab_B[k][j];
            }
        }
    }
    
    return result;
}

void print_tab_all(int y,int a[][y], int x) {
    int i, j;
    for (i = 0; i < x; i++){
        for (j = 0; j < y; j++)
            printf ("%3d", a[i][j]);
        printf ("\n");   }
    return;
}