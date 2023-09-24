#include<stdio.h>


void file_copy (FILE *to, FILE *which_being_copied);
int file_cmp (char *, char *);

int main(void) {
    FILE *which_being_copied = fopen("file.txt","rb");
    FILE *to = fopen("copied","wb");

    file_copy(to,which_being_copied);

    int var = file_cmp("file.txt","copied");
    if(var == 0 ) printf("\nFILES are equal!");
}

void file_copy (FILE *to, FILE *which_being_copied) {
    int var;
    while((var = fgetc(which_being_copied)) != EOF) fputc(var,to);
    
    fclose(to);
    fclose(which_being_copied);
}

int file_cmp (char *first, char *second) {
    FILE *file_1 = fopen(first,"rb"); if(!file_1) return -1;
    FILE *file_2 = fopen(second,"rb"); if(!file_2) return -1;

    int a, b;

    while((a = fgetc(file_1)) != EOF) {
        if((b = fgetc(file_2)) != EOF) {
        printf("%c",a);
        if(feof(file_1) || feof(file_2)) break;
        if(a != b) return 1;
        }
        else return 1;
    }

    b = fgetc(file_2);

    if(feof(file_1) && feof(file_2)) return 0;
    else return 1;

}