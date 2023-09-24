#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double fun0(double x);
double fun1(double x);
double fun2(double x);
double fun3(double x);
double (*find_max(double (*TAB_FUN[5])(double), double x))(double );
int cmp_1(const void *a, const void *b);

int main(void) {
    char *nazwy[]={"log", "pow","sin","cos"};
    double data[8] = { 3.5, 1.0, 2.5, 2.0, 1.5, 3.0, 0.5, 4.0 }; 
    double (*TAB_FUN[5])(double); // table of 5 pointers to functions with double arguments

    TAB_FUN[0] = fun0; 
    TAB_FUN[1] = fun1; 
    TAB_FUN[2] = fun2; 
    TAB_FUN[3] = fun3;
    TAB_FUN[4] = NULL;

    // test of procedure
    //print_fun(fun0,"log",data,8);

    char *(*str)[4] = nazwy; // str is a pointer to table of 4 pointers to char -> nazwa[0] is a pointer
    double (*(*wsk_fun)[5])(double) = TAB_FUN;
    double x = 1;
    double (*ptr_nazwa)(double);
    int var = 0;
    for(int i=0;i<4;i++) print_fun(wsk_fun[0][i],str[0][i],data,8);

    ptr_nazwa = find_max(TAB_FUN,x);
    for(int i=0;i<5;i++) if(ptr_nazwa==TAB_FUN[i]) break; else var++;
    printf ("dla x= %.3f najwieksza wartosc wynosi %.5f dla funkcji %s\n", x, ptr_nazwa(x),nazwy[var]);

    printf("\nBEFORE SORTING by fun1:\n");
    for(int i=0;i<8;i++) printf("%.1f ",data[i]); printf("\nAFTER:\n");
    qsort(data,8,sizeof(double),cmp_1); for(int i=0;i<8;i++) printf("%.1f ",data[i]);

    printf("\nEND\n");
}

double fun0(double x) { return log(x); }
double fun1(double x) { return x*x;    }
double fun2(double x) { return sin(x); }
double fun3(double x) { return cos(x); }

void print_fun(double (*f)(double), char *name, double *data, int n) {
    printf("\n%s :\n",name);
    for(int i=0; i<n; i++) printf("%s(%.2f) = %.4f\n",name,data[i],f(data[i]));
    printf("\n");
}

double (*find_max(double (*TAB_FUN[5])(double), double x))(double) {
    
    double (*maximal_value)(double) = TAB_FUN[0];

    for(int i=1;i<4;i++) {
        if(TAB_FUN[i](x) > maximal_value(x)) maximal_value = TAB_FUN[i];
    }

    return maximal_value;
}

int cmp_1(const void *a, const void *b) {
    if(fun1(*(double *)a)<fun1(*(double *)b)) return -1;
    else if(fun1(*(double *)a)>fun1(*(double *)b)) return 1;
    return 0;
}