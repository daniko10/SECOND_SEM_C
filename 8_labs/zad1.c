#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// structs

struct point { // 2D point
    double x;
    double y;
};

struct vect_point { // two 2D points (vector)
    struct point start;
    struct point end;
};

struct vect {
    struct vect_point vector;
    double length;
    double alfa;
};

// functions

double vect_len( struct vect_point );
double vect_slope( struct vect_point );
void fill_tab ( struct vect *, int );
void sort( struct vect *, int );
int cmp_len(const void *a, const void *b);
int cmp_alfa(const void *a, const void *b);
struct vect *func(struct vect *temp, int n, double *len, double beta);


int main(int nmbr_arg, char *argv[]) {
    srand(time(NULL));
    if(nmbr_arg!=2) return 1;

    int var = atoi(argv[1]);
    struct vect tab_vect[var];

    for(int i=0;i<var;i++) {
        tab_vect[i].vector.start.x = (double)rand()/(double)(RAND_MAX +1)*100;
        tab_vect[i].vector.start.y = (double)rand()/(double)(RAND_MAX +1)*100;
        tab_vect[i].vector.end.x = (double)rand()/(double)(RAND_MAX +1)*100;
        tab_vect[i].vector.end.y = (double)rand()/(double)(RAND_MAX +1)*100;
    }

    fill_tab(tab_vect,var);

    printf("BEFORE sorting\n\nNumber of struct Ax  Ay     Bx  By     length  alfa\n\n");
    for(int i=0;i<var;i++) printf("%d               %3.1f %3.1f %3.1f %3.1f   %3.1f     %3f\n",i,tab_vect[i].vector.start.x,tab_vect[i].vector.start.y,tab_vect[i].vector.end.x,tab_vect[i].vector.end.y,tab_vect[i].length,tab_vect[i].alfa);

    sort(tab_vect,var);

    printf("\n\nAFTER sorting\n\nNumber of struct Ax  Ay     Bx  By     length  alfa\n\n");
    for(int i=0;i<var;i++) printf("%d               %3.1f %3.1f %3.1f %3.1f   %3.1f     %3f\n",i,tab_vect[i].vector.start.x,tab_vect[i].vector.start.y,tab_vect[i].vector.end.x,tab_vect[i].vector.end.y,tab_vect[i].length,tab_vect[i].alfa);

    // test of function
    //tab_vect[0].length=1.0;
    //tab_vect[0].alfa=3.0;
    // function 
    double len = 1;
    struct vect *result = func(tab_vect,var,&len,3.0);

    printf("\n%f %f %f %f   %f %f\n",result->vector.start.x,result->vector.start.y,result->vector.end.x,result->vector.end.y,result->length,result->alfa);
}

// functions bodies

double vect_len( struct vect_point temp ) {
    double x = temp.end.x - temp.start.x;
    double y = temp.end.y - temp.start.y;

    return sqrt(x*x + y*y);
}

double vect_slope( struct vect_point temp) {
    double x = temp.end.x - temp.start.x;
    double y = temp.end.y - temp.start.y;

    if(temp.end.y - temp.start.y == 0) return 0;

    return asin((temp.end.y - temp.start.y)/sqrt(x*x + y*y));
}

void fill_tab( struct vect *temp, int n) {
    for(int i=0;i<n;i++) {
        temp[i].alfa = vect_slope(temp[i].vector);
        temp[i].length = vect_len(temp[i].vector);
    }
}

void sort( struct vect *temp, int n) {
    int key;
    int key_1;

    for(int i=0;i<n;i++) {
        key=i;
        for(int j=i+1;j<n;j++) 
            if(temp[key].alfa > temp[j].alfa) key=j;
            else if(temp[key].alfa == temp[j].alfa) {
                for(int k=j;k<n;k++) {
                    if(temp[key].alfa == temp[k].alfa) {
                        if(temp[key].length > temp[k].length) key=k;
                    }
                }
            }
        struct vect t = temp[i];
        temp[i] = temp[key];
        temp[key] = t;
    }
}

struct vect *func(struct vect *temp, int n, double *len, double beta) {
    qsort(temp,n,sizeof(struct vect), cmp_alfa);
    qsort(temp,n,sizeof(struct vect), cmp_len);

    struct vect *ptr = malloc(sizeof(struct vect));
    ptr->length = *len;
    
    struct vect *result = bsearch(ptr,temp,n,sizeof(struct vect), cmp_len);

    for(int i=0;i<n;i++) {
        if((beta-temp[i].alfa)<=0.01 && (beta-temp[i].alfa)>=-0.01) 
            if(temp + i == result) return result;
    }
    
    struct vect *t = malloc(sizeof(struct vect));
    
    t->vector.start.x=1000;
    t->vector.start.y=1000;
    t->vector.end.x=1000;
    t->vector.end.y=1000;

    t->alfa = vect_slope(t->vector);
    t->length = vect_len(t->vector);

    return t;
}


int cmp_len(const void *a, const void *b) {
    if(((struct vect *)a)->length - ((struct vect *)b)->length < 0) return -1;
    else if(((struct vect *)a)->length - ((struct vect *)b)->length == 0) return 0;
    return 1;
}

int cmp_alfa(const void *a, const void *b) {
    if(((struct vect *)a)->alfa - ((struct vect *)b)->alfa < 0) return -1;
    else if(((struct vect *)a)->alfa - ((struct vect *)b)->alfa == 0) return 0;
    return 1;
}
//