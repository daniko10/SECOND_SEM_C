#include<stdio.h>
#include<math.h>

int zero(double (*f)(double), double a, double b, double* m_z, double eps); 
double fun_1(double x);

int main(void) {
    double m_z, eps = 1e-5, a=0, b=8;
    int result = zero(fun_1,a,b,&m_z,eps);

    if(result == 1) printf("Found --> %.2f at [%.2f,%.2f]\n",m_z,a,b);
    else if(result == 0) printf("Not Found at [%.2f,%.2f]\n",a,b);
}

double fun_1(double x) {
    return x*x - 4;
}

int zero(double (*f)(double), double a, double b, double* m_z, double eps) {
    double mid;

    while(f(a)*f(b) <= 0 && fabs(b-a)>=eps ) {
        mid = (a+b)/2;
        if(f(a)*f(mid)<=0) b=mid;
        else a=mid;
    }
    if(f(a)*f(b) <= 0) { *m_z=mid; return 1; }
    else return 0;
}