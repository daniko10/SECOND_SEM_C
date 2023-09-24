#include<stdio.h>
#include<stdlib.h>

struct tnode {
       int value;
       struct tnode *next;
     };

struct tnode* create ( int value);
void print(struct tnode *head);
void sort(struct tnode *head);

int main() {
    struct tnode *head = create(33);
    struct tnode *temp = NULL;

    for(int i=0; i<9 ; i++) {
        temp = create(i*3);
        temp->next = head;
        head = temp;
    }
    printf("\n%10s %10s %10s\n","address","value","next");
    print(head);

    sort(head);

    printf("\nAFTER SORTING: \n%10s %10s %10s\n","address","value","next");
    print(head);
}

void sort(struct tnode *head) {
    struct tnode *temp = head;
    
    while(temp!=NULL) {
        struct tnode *min = temp;
        struct tnode *temp_next = temp->next;
        struct tnode *min_next = NULL;
        for(struct tnode *next = temp->next ; next; next = next->next) if(min->value > next->value) { min = next; min_next = min->next; }
        struct tnode *t = temp;
        temp = min;
        temp->next = temp_next;
        min = t;
        min->next = min_next;
    }
}

void print(struct tnode *head) {
    for(int i=0; i<10; i++) { if(head) { printf("%10p %10d %10p\n",head,head->value,head->next);
    head = head->next; }
    } 
}

struct tnode* create ( int value) {
    struct tnode *new = malloc(sizeof(struct tnode));
    new->value = value;
    new->next = NULL;

    return new;
}