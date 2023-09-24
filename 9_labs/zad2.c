#include<stdio.h>
#include<stdarg.h>
#include<string.h>
#include<stdlib.h>

char *va_cat(int n, ...);

int main(void) {
    char *string_1 = "If you never did You should.";
    char *string_2 = " These things are fun";
    char *string_3 = " and Fun is good.";
    char *string_4 = "I love you all!";

    char *result = va_cat(4,string_1,string_2,string_3,string_4);
    
    FILE * fp = fopen("file.txt","w");
    
    if(!fp) return 1;

    fputs(result,fp);
    fclose(fp);
}

char *va_cat(int n, ...) {

    va_list argptr; // pointer to list of arguments
    va_start(argptr,n); // inicialization of argptr

    char *result = NULL, *temp = NULL;
    int var = 0;

    for(int i=0;i<n;i++) {
        temp = va_arg(argptr, char *);
        var+=strlen(temp) + 1;
        result = realloc(result,sizeof(char) * var);
        result[var-1] = '\0';
        if(var-strlen(temp) - 1 == 0) strcpy(result,temp);
        else strcat(result,temp);
    }

    va_end(argptr); // close reading

    return result;
}