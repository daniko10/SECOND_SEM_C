#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 20

char ** podziel(char *, int *);
void sort(char **, int);
char * sklej(char **, int);

int main(int n_arg, char *argv[]) {
    if(n_arg!=2) return 1;

    int n=0;
    char **tab = podziel(argv[1],&n);

    sort(tab,n);

    printf("NUMBER OF WORDS : %d\n\n",n);
    for(int i=0;i<n;i++) printf("%s\n",tab[i]);
    printf("\n");

    char *string = sklej(tab,n);
    printf("\n%s\n",string);
}

char ** podziel(char *string, int *n_words) {
    char **tab = malloc(sizeof(char *));
    int n=1;
    int var;

    char *temp = strtok(string,", ;.:-");
    tab[0] = malloc(sizeof(char) * (strlen(temp) + 1)); // one for '\0'
    strcpy(tab[0],temp);
    strcat(tab[0],"\0");

    temp = strtok(NULL,", ;.:-");

    while(temp!=NULL) {
        n++;
        tab = realloc(tab,sizeof(char *) * n);
        tab[n-1] = malloc(sizeof(char) * (strlen(temp) + 1));
        var = 0; // says if word occured before
        for(int i=0;i<n-1;i++) if(strcmp(temp,tab[i])==0) var++;
        if(var == 0) {
            strcpy(tab[n-1],temp);
            strcat(tab[n-1],"\0");
        }
        else n--;
        temp = strtok(NULL,", ;.:-");
    }

    *n_words = n;
    return tab;
}

void sort(char **tab, int n) {
    char *ptr = malloc(sizeof(char) * N);
    int index;
    int n1;
    int n2;

    ptr[N-1]='\0';
    //temp[N-1]='\0';
    for(int i=0;i<n;i++) {
        
        index=i;
        for(int j=i+1;j<n;j++) if(strcmp(tab[index],tab[j]) > 0) index=j;
        
        n1=strlen(tab[index])+1;
        n2=strlen(tab[i])+1;
        
        strcpy(ptr,tab[index]);
        tab[index] = realloc(tab[index], sizeof(char) * n2);
        strcpy(tab[index],tab[i]);
        strcat(tab[index],"\0");

        tab[i] = realloc(tab[i], sizeof(char) * n1);
        strcpy(tab[i],ptr);
        strcat(tab[i],"\0");
        
    }

    free(ptr);
}

char *sklej(char **tab, int n) {
    int var = strlen(tab[0]) + 1;
    char *table = malloc(sizeof(char) * var);
    table[var-1]='\0';
    strcpy(table,tab[0]);
    strcat(table," ");

    for(int i=1;i<n;i++) {
        var+=strlen(tab[i]);
        var+=1;
        table=realloc(table, sizeof(char) * var);
        table[var-1]='\0';
        strcat(table,tab[i]);
        strcat(table," ");
        strcat(table,"\0");
    }
    table=realloc(table,var + 1);
    table[var] = '\0';

    return table;
}