#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

int rand_i(int down, int up);
void func_numbers_string(char *wsk, int n);
int number_cmp(char *num_1, char *num_2);

int main(void) {
    srand(time(NULL));

    int n_1=rand_i(30,50);
    int n_2=rand_i(30,50);
    char number_1[n_1+1];
    char number_2[n_2+1];

    number_1[n_1] = '\0';
    number_2[n_2] = '\0';

    func_numbers_string(number_1,n_1);
    func_numbers_string(number_2,n_2);

    printf("Number 1 : %s\nNumber 2 : %s\n",number_1,number_2);

    int result=number_cmp(number_1,number_2);
    if(result == 0) printf("Equal");
    else if(result > 0) printf("First is greater");
    else printf("First is smaller");
    return 0;
}

int rand_i(int down, int up) {
    return rand()%(up-down + 1) + down;
}

void func_numbers_string(char *wsk, int n) {
    wsk[0]=rand()%9+1 + 48;
    for(int i=1;i<n;i++) wsk[i]=rand()%10 + 48;
}

int number_cmp(char *num_1, char *num_2) {
    char *wsk_1=num_1;
    char *wsk_2=num_2;
    int var_1=0, var_2=0;
    while(*wsk_1++!=0)
        var_1++;
    while(*wsk_2++!=0)
        var_2++;
    if(var_1==var_2) return strcmp(num_1,num_2);
    else if(var_1>var_2) return 1;
    else return -1;
}