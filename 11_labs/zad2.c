#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20

struct person {
    char l_name[SIZE + 1];
    char f_name[SIZE + 1];
    char code[SIZE + 1];
    int age;
};

struct person *create_tab(char *file_name, int *n);

int main(void) {
    int size = 0;
    struct person *TAB = create_tab("file.txt",&size);
    for(int i=0; i<size ; i++) printf("%s %s %s %d\n",TAB[i].l_name,TAB[i].f_name,TAB[i].code,TAB[i].age);
    
    FILE *file = fopen("file.dat","wb");
    if(!file) return 1;

    fwrite(TAB,sizeof(struct person), size, file);
    fclose(file);

    FILE *f_open = fopen("file.dat","rb");
    if(!f_open) return 1;

    fseek(f_open,0,SEEK_END);
    size = ftell(f_open) / sizeof(struct person);
    fseek(f_open,0,SEEK_SET);

    struct person TAB_1[size];

    fread(TAB_1,sizeof(struct person),size,f_open);
    printf("AFTER binary: \n");
    for(int i=0; i<size ; i++) printf("%s %s %s %d\n",TAB_1[i].l_name,TAB_1[i].f_name,TAB_1[i].code,TAB_1[i].age);
}

struct person *create_tab(char *file_name, int *n) {
    FILE *file = fopen(file_name,"r");
    if(!file) return NULL;

    char l_name[SIZE + 1]; l_name[SIZE] = '\0';
    char f_name[SIZE + 1]; f_name[SIZE] = '\0'; 
    char code[SIZE + 1]; code[SIZE] = '\0';
    int age;

    int size = 0;
    struct person *TAB = NULL;

    while(fscanf(file,"%s\n%s\n%s\n%d\n",l_name,f_name,code,&age)) {
        size++;
        TAB = realloc(TAB,sizeof(struct person *)*size);
        TAB[size-1].l_name[SIZE] = '\0';
        TAB[size-1].f_name[SIZE] = '\0';
        TAB[size-1].code[SIZE] = '\0';

        strcpy(TAB[size-1].l_name,l_name);
        strcpy(TAB[size-1].f_name,f_name);
        strcpy(TAB[size-1].code,code);
        TAB[size-1].age = age;

        l_name[SIZE] = '\0';
        f_name[SIZE] = '\0';
        code[SIZE] = '\0';

        if(feof(file)) break;
    }

    *n = size;

    return TAB;
}