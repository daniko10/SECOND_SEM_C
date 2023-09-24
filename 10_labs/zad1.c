#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct elem {
    char var;
    int how_many;
    struct elem *next;
};

struct elem *create(char var);
struct elem *add_lis(struct elem *head, char var);
void print(struct elem *head);

int main(int arg, char *argv[]) {
    if(arg!=4) return 1;

    int len = strlen(argv[1]);

    FILE *fp = fopen(argv[2],"w");
    if(!fp) return 1;

    struct elem *head = NULL;
    for(int i=0;i<len;i++) head = add_lis(head,argv[1][i]);

    print(head);
    struct elem *tt = head;


    for(;head;head = head->next) { 
        fputc(head->var,fp);
        fputc(':',fp);
        fprintf(fp,"%d",head->how_many);
        fputc('\n',fp);
    }

    fclose(fp);

    FILE * fp_1 = fopen(argv[3],"wb");
    if(!fp_1) return 1;

    for(;tt;tt = tt->next)  fwrite(tt,sizeof(struct elem),1,fp_1);
    fclose(fp_1);

    FILE * file = fopen(argv[3],"rb");
    if(!file) return 1;

    fseek(file,0,SEEK_END);
    int size = ftell(file)/(sizeof(struct elem));
    fseek(file,0,SEEK_SET);

    struct elem TAB[size];
    for(int i=0;i<size;i++) {
        fread(TAB + i,sizeof(struct elem),1,file);
        printf("%c : %d\n",TAB[i].var, TAB[i].how_many);
    }
   
}

struct elem *create(char var) {
    struct elem *new = malloc(sizeof(struct elem));
    new->var = var;
    new->how_many = 1;
    new->next = NULL;

    return new;
}

struct elem *add_lis(struct elem *head, char var) {
    if(var == ' ') return head;
    if(head == NULL) {
        head = create(var);
        return head;    
    }
    // we check IF var exist
    struct elem *temp = head;
    for(;temp;temp = temp->next) if(temp->var == var) break;
    if(temp) { // it means we found it
        temp->how_many+=1;
        return head;
    }
    else { // its not found, we have search for a good place to put var
        struct elem *t = NULL;
        temp = head;
        for(;temp;temp = temp->next) {
            if(temp == head && temp->var > var)  {
                    t = create(var);
                    t->next = head;
                    head = t;
                    return head;
                }
            else if(temp->var > var) {
                struct elem *new = create(var);
                t->next = new;
                new->next = temp;
                return head;
            }
            t = temp;
        }
            if(t->var <= var) {
                temp = create(var);
                t->next = temp;
                temp->next = NULL;
            }
        }
    return head;
}

void print(struct elem *head) {
    printf("head -> ");
    for(;head;head=head->next)  printf("[%c : %d] -> ",head->var,head->how_many);
    printf("NULL\n");
}