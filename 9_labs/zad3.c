#include<stdio.h>
#include<stdlib.h>

struct tnode {
    char value;
    struct tnode *next;
};

void add_front(struct tnode **head, char val);
void print(struct tnode *head);
void free_list(struct tnode **head);
struct tnode *add_end(struct tnode *head, struct tnode *elem);

int main(void) {
    struct tnode *head = NULL;
    
    add_front(&head,'a');
    add_front(&head,'c');
    add_front(&head,'v');
    add_front(&head,'f');
    add_front(&head,'t');

    printf("First list :\n");
    print(head);

    free_list(&head);

    struct tnode *head_1 = NULL;
    struct tnode el_1;
    struct tnode el_2;
    struct tnode el_3;
    struct tnode el_4;
    struct tnode el_5;

    el_1.value = 'a';
    el_2.value = 'c';
    el_3.value = 'v';
    el_4.value = 'f';
    el_5.value = 't';

    head_1 = add_end(head_1,&el_1);
    head_1 = add_end(head_1,&el_2);
    head_1 = add_end(head_1,&el_3);
    head_1 = add_end(head_1,&el_4);
    head_1 = add_end(head_1,&el_5);

    printf("\nSecond list :\n");
    print(head_1);
}

void add_front(struct tnode **head, char val) {
    struct tnode *temp = malloc(sizeof(struct tnode));
    temp->value = val;

    if(*head == NULL) {
        *head = temp;
        (*head)->next = NULL;
        return;
    }
    temp->next = *head;
    *head = temp;
}

struct tnode *add_end(struct tnode *head, struct tnode *elem) {
    struct tnode *temp = head;
    
    if(head == NULL) {
        head = elem;
        head->next = NULL;
        return head;
    }

    for(;temp->next;temp=temp->next);
    
    temp->next = elem;
    elem->next = NULL;

    return head;
}

void print(struct tnode *head) {
    printf("head -> ");
    for(;head;head=head->next)  printf("['%c'] -> ",head->value);
    printf("NULL\n");
}

void free_list(struct tnode **head) {
    while(*head) {
        struct tnode *temp = (*head)->next;
        free(*head);
        (*head)=temp;
    }
}