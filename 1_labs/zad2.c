#include<stdio.h>

void write_binar(unsigned n, char * wsk);
unsigned bits(unsigned int x);

int main(void) {
    unsigned number;
    int bits_number=sizeof(number)*8;
    char string_number[bits_number+1];
    unsigned result;

    string_number[bits_number] = '\0';

    scanf("%u",&number);
    write_binar(number,string_number);
    printf("\nScaned number %u : %s\n",number,string_number);
    
    result = bits((unsigned int)number);
    write_binar(result,string_number);
    printf("%u after 0`s even bits %u : %s",number,result,string_number);

}

void write_binar(unsigned n, char * wsk) {
    int var=0;
    for(int i=sizeof(n)*8-1;i>=0;i--) {
        if(n>>i & 1) wsk[var]='1';
        else wsk[var]='0';
        var++;
    }
}

unsigned bits(unsigned int x) {
    unsigned number=0;
    for(int i=sizeof(x)*8-1;i>=0;i--) {
        number=number<<1;
        if(!(i%2==0)) if(x>>i & 1) number+=1;
    }
    return number;
}