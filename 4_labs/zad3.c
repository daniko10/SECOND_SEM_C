#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *delete_text(char *text1, char *text2);

int main(void) {
    char *TEXT_1="Jak sie nie ma, co sie lubi, to sie lubi, co sie ma.";
    char *TEXT_2="sie";
    char *napis=NULL;

    napis=delete_text(TEXT_1,TEXT_2);
    printf("%s",napis);

    free(napis);
}

char *delete_text(char *text1, char *text2) {
    char *wsk=strstr(text1,text2);
    char *ptr=text1;
    char *result=NULL;
    int var=0;
    if(!wsk) {
        result=realloc(result,sizeof(char)*(strlen(text1)+1));
        strcpy(result,text1);
        result[strlen(text1)]='\0';
        return result;
    }

    while(ptr!=wsk && wsk) {
        var++;
        result=realloc(result,sizeof(char)*var);
        result[var-1]=*ptr;
        ptr++;
        if(ptr==wsk) {
            ptr+=strlen(text2);
            wsk=strstr(ptr,text2);
        }
    }
    while(*ptr!=0) {
        var++;
        result=realloc(result,sizeof(char)*var);
        result[var-1]=*ptr;
        ptr++;
    }
    result=realloc(result,sizeof(char)*(var+1));
    result[var]='\0';
    
    return result;
}