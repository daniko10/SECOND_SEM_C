#include<stdio.h>
#include<time.h>
#include<stdlib.h>

struct liczba {
    char var;
    union {
        int integer;
        double doub;
    } union_in_struct;
};

void struct_prn(struct liczba *temp, int n);
void sort(struct liczba *temp, int n);
int cmp(const void *a, const void *b);
int cmp2(const void *a, const void *b);
int cmp_d(const void *a, const void *b);
int cmp_i(const void *a, const void *b);

int main(int arg, char *argv[]) {
    
    if(arg!=3) return 1;
    
    srand(time(NULL));

    int len = rand()%10 + 10;
    struct liczba NUMBERS[len];
    
    for(int i=0;i<len;i++) {
        int var = rand()%2;
        if(var == 0) { // 0 = integer
            NUMBERS[i].var = 'i';
            NUMBERS[i].union_in_struct.integer = rand()%11 - 5;
        }
        else {
            NUMBERS[i].var = 'd';
            NUMBERS[i].union_in_struct.doub = (double)rand()/(RAND_MAX + 1) * 10 - 5;
        }
    }

    struct_prn(NUMBERS,len);

    printf("\n\n");

    FILE * fp = fopen("plik.dat","wb");

    if(!fp) return 1;
    //     what write|   sizeof it        many  to_where
    fwrite(NUMBERS   ,   sizeof(NUMBERS), 1   , fp      );

    fseek(fp,0,SEEK_END);
    int size_fp = ftell(fp), n = size_fp/sizeof(struct liczba);
    printf("Total size of binary file : %d\n\n",size_fp);
    fclose(fp);

    FILE *to_read = fopen("plik.dat","rb");
    
    if(!to_read) return 1;
    struct liczba TAB[n];
    fread(TAB,sizeof(TAB),1,to_read);

    struct_prn(TAB,n);

    printf("\nSORTED: \n");
    sort(NUMBERS,n);
    struct_prn(NUMBERS,n);

    // bsearch function

    int temp_1;
    double temp_2;

    if(*argv[1] == 'd')  {
        temp_2 = atof(argv[2]);
        if(bsearch(&temp_2,NUMBERS,n,sizeof(struct liczba), cmp_d)) {
            printf("\nINDEXs : \n");
            for(int i=0;i<n;i++) {
                if(NUMBERS[i].union_in_struct.doub == temp_2) printf("%d\n",i);
            }
        }
    }
    else if(*argv[1] == 'i') { 
        temp_1 = atoi(argv[2]);
        if(bsearch(&temp_1,NUMBERS,n,sizeof(struct liczba), cmp_i)) {
            printf("\nINDEXs : \n");
            for(int i=0;i<n;i++) {
                if(NUMBERS[i].union_in_struct.integer == temp_1) printf("%d\n",i);
            }
        }
    }
    else return 1;
}

void struct_prn(struct liczba *temp, int n) {
    for(int i=0;i<n;i++) if(temp[i].var == 'i') printf("%4d --- %c\n",temp[i].union_in_struct.integer,temp[i].var);
        else if(temp[i].var == 'd') printf("%4.1f --- %c\n",temp[i].union_in_struct.doub,temp[i].var);
}

void sort(struct liczba *temp, int n) {
    qsort(temp,n,sizeof(struct liczba), cmp);
    qsort(temp,n,sizeof(struct liczba), cmp2);
}

int cmp(const void *a, const void *b) {
    struct liczba *ptr_1 = (struct liczba *)a;
    struct liczba *ptr_2 = (struct liczba *)b;

    if(ptr_1->var == 'd' && ptr_2->var == 'd') return ptr_1->union_in_struct.doub - ptr_2->union_in_struct.doub;
    else if(ptr_1->var == 'i' && ptr_2->var == 'i') return ptr_1->union_in_struct.integer - ptr_2->union_in_struct.integer;
}

int cmp2(const void *a, const void *b) {
    struct liczba *ptr_1 = (struct liczba *)a;
    struct liczba *ptr_2 = (struct liczba *)b;

    if(ptr_1->var == 'd' && ptr_2->var == 'i') return -1;
    else if(ptr_1->var == 'i' && ptr_2->var == 'd') return 1;
    else {
        if(ptr_1->var == 'd') return ptr_1->union_in_struct.doub - ptr_2->union_in_struct.doub;
        else return ptr_1->union_in_struct.integer - ptr_2->union_in_struct.integer;
    }
}

int cmp_d(const void *a, const void *b) {
    struct liczba *ptr_2 = (struct liczba *)b;

    return *(double *)a - ptr_2->union_in_struct.doub;
}

int cmp_i(const void *a, const void *b) {
    struct liczba *ptr_2 = (struct liczba *)b;

    return *(int *)a - ptr_2->union_in_struct.integer;
}