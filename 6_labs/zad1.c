#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void add_values(int **tab, int rows, int col);
void print(int **tab, int rows, int col);

int main(void) {
    
    srand(time(NULL));

    int rows = rand()%5 + 3;
    int columns = rand()%5 + 3;

    // MEMORY ORGANIZATION
    int **array_1 = malloc(sizeof(int *) * rows);
    for(int i=0;i<rows;i++) array_1[i] = malloc(sizeof(int) * columns);

    int **array_2 = malloc(sizeof(int * ) * rows);
    array_2[0]=malloc(sizeof(int) * rows * columns);
    for(int i=1;i<rows;i++) array_2[i] = array_2[i-1] + columns;

    int (*array_3)[columns] = malloc(sizeof(int) * rows * columns);
    // -------------------

    add_values(array_1,rows,columns);
    add_values(array_2,rows,columns);

    print(array_1,rows,columns);
    print(array_2,rows,columns);

    // array_3
    for(int i=0;i<rows;i++) {
        for(int j=0;j<columns;j++) array_3[i][j] = rand()%15 + 1;
    }
    for(int i=0;i<rows;i++) {
        for(int j=0;j<columns;j++) printf("%3d ",array_3[i][j]);
        printf("\n");
    }
    //

    printf("\nAFTER changing rows : \n");
    int new_rows = rand()%5 + 3;

    //array_1
    array_1 = realloc(array_1,sizeof(int *) * new_rows);
    //array_2
    array_2 = realloc(array_2,sizeof(int *) * new_rows);
    //array_3
    array_3 = realloc(array_3,sizeof(int) * new_rows * columns);

    if(new_rows > rows) {
        for(int i=rows;i<new_rows;i++)
            for(int j=0;j<columns;j++) {
                array_1[i][j] = rand()%15 - 15;
                array_2[i][j] = rand()%15 - 15;
                array_3[i][j] = rand()%15 - 15;
            }
    }

    print(array_1,new_rows,columns);
    print(array_2,new_rows,columns);
    // array_3
    for(int i=0;i<new_rows;i++) {
        for(int j=0;j<columns;j++) printf("%3d ",array_3[i][j]);
        printf("\n");
    }
    //

    // FREE MEMORY
    
    // array_3 is just a pointer which holds new_rows * columns ints and moves for [columns] ints
    free(array_3);
    // array_1 i have to free each allocation of malloc in [i] row and then free the pointer wich holds these pointers
    for(int i=0;i<new_rows;i++) free(array_1[i]); free(array_1);
    // array_2 i have to free a pointers array_2[0] which holds entire tab and then pointer which holds other pointers
    free(array_2[0]); free(array_2);

    printf("\nEND\n");
}

void add_values(int **tab, int rows, int col) {
    for(int i=0;i<rows;i++) {
        for(int j=0;j<col;j++) tab[i][j] = rand()%15 + 1;
    }
}

void print(int **tab, int rows, int col) {
    for(int i=0;i<rows;i++) {
        for(int j=0;j<col;j++) printf("%3d ",tab[i][j]); printf("\n");
    }
    printf("\n\n");
}