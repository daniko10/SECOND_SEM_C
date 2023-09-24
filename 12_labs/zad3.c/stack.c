#include "stack.h"

void push_one(struct tnode** head, struct tnode* el) {
    if(*head) {
        el->next = *head;
        *head = el;
    } else {
        *head = el;
        (*head)->next = NULL;
    }
}

void print_stack(struct tnode* head) {
   if(head && head->next) print_stack(head->next);
   printf("%d -> ",head->value);
}

struct tnode* push_many(struct tnode* head, struct tnode** list_elements_to_add){
    if(!head) return *list_elements_to_add;
    else {
        struct tnode *temp = *list_elements_to_add;
        if(temp) { for(;temp->next;temp=temp->next);
            temp->next = head;
        }
    }
    return *list_elements_to_add;
}

struct tnode* pop_one(struct tnode** head) {
    struct tnode *temp = *head;
    if(!(*head)) return NULL;
    else {
        *head = (*head)->next;
        return temp;
    }
}

struct tnode* pop_x(struct tnode** head, int x) {
    if(x<=0) return NULL;

    struct tnode *result = NULL;

    for(int i=0; i<x ; i++) push_one(&result,pop_one(head));


    return result;
}

void clear_st(struct tnode** head) {
    struct tnode *temp = NULL;

    while(*head) {
        temp = (*head)->next;
        free(*head);
        *head = temp;
    }
}