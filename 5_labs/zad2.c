#include<stdio.h>
#include<string.h>
#define N 100

int main(int number_of_arg, char *argv[]) {
    if(number_of_arg!=2) return 1;
    char string[N];
    char *min=NULL;
    char *temp=NULL;
    int var = 0;

    string[N-1]='\0';

    strcpy(string,argv[1]);
    
    min=strtok(argv[1],"; ,.:"); // get first 
    temp=strtok(NULL,"; ,.:");

    while(temp!=NULL) {
        
        if(strcmp(min,temp)<0) { min=temp; var=1; }
        else if(strcmp(min,temp)==0) var++;
        temp=strtok(NULL,"; ,.:");
    }
    printf("Biggest word: %s, appeared %d",min,var);
}