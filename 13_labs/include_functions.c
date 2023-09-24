#include "include_functions.h"

struct tnode* div_list(struct tnode** head) {
    struct tnode *new = NULL;
    struct tnode *deleted = NULL;
    struct tnode *temp = *head;

    for( ;temp; temp = temp->next) {
        if(temp->value%2 == 0)  { deleted = del_el_one(head, temp->value); new = add_first(new,deleted); }

    }

    return new;
}

struct tnode* del_el_one(struct tnode** head, int var) {
    struct tnode *temp = *head;
    struct tnode *result = NULL;

    for( ;temp && temp->value != var; temp = temp->next);

    if(temp) {
        if(*head == temp) {
            if((*head)->next) {
                (*head)->next->prev = NULL;
                *head = (*head)->next;
            }
            else *head = NULL;
        }
        else if(temp->prev && temp->next) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        } else if(temp->prev && temp->next == NULL) {
            temp->prev->next = NULL;
        }
        else if(temp->prev == NULL && temp->next) {
            temp->next->prev = NULL;
        }
        else if(temp->prev == NULL && temp->next == NULL) {
            temp = NULL;
        }
        result = malloc(sizeof(struct tnode)); result->value = var; result->next = NULL; result->prev = NULL;
    }
    
    return result;
}

struct tnode* del_el_all(struct tnode** head, int var) {
    struct tnode *temp = *head;
    struct tnode **tab = NULL;
    struct tnode *result = NULL;
    struct tnode *t = NULL;
    int times = 0;

    while(temp) {
        if(temp->value == var) {
            if(*head == temp) *head = (*head)->next;
            else {
                t->next = temp->next;
                if(temp->next) temp->next->prev = t;
            }
            times++;
            tab = realloc(tab,sizeof(struct tnode *) * times);
            tab[times - 1] = malloc(sizeof(struct tnode)); tab[times - 1]->value = var;
            result = add_first(result,tab[times - 1]);
        }
        t = temp;
        temp=temp->next;  
    }
    return result;
}

struct tnode* add_last(struct tnode* head, struct tnode* el) {
    if(!head) {
        head = el;
        head->next = NULL;
        head->prev = NULL;
        return head;
    }

    struct tnode *temp = head;
    for(;temp->next; temp = temp->next);
    temp->next = el;
    el->prev = temp;
    el->next = NULL;

    return head;
}

struct tnode* add_first(struct tnode* head, struct tnode* el) {
    if(!head) {
        head = el;
        head->next = NULL;
        head->prev = NULL;
        return head;
    }
    struct tnode *t = head;
    t->prev = el;
    el->next = t;
    el->prev = NULL;
    return el;
}

void print_list_next(struct tnode* head) {
    printf("\nHEAD -> ");
    for(;head;head=head->next) printf("%d -> ",head->value);
    printf("NULL\n");
}

void print_list_prev(struct tnode* head) {
    struct tnode *last = NULL;

    for(;head;head=head->next) last = head;

    printf("\nNULL <- ");
    for(;last; last = last->prev) printf("%d <- ",last->value);
    printf("HEAD\n");
}

void add_sort(struct tnode** head, struct tnode* el) {
    if(!(*head)) {

        *head = el;
        (*head)->next = NULL;
        (*head)->prev = NULL;

    } else {

        if((*head)->value > el->value) {

            (*head)->prev = el;
            el->next = *head;
            el->prev = NULL;
            *head = el;

        } else {

            struct tnode *temp = *head;
            struct tnode *t = NULL;

            for( ;temp && temp->value <= el->value; temp = temp->next) t = temp;
            t->next = el;
            el->prev = t;
            el->next = temp;

        }
    }
}

void free_list(struct tnode** head) {
    struct tnode *temp = NULL;

    if(*head)
        while(*head) {
            temp = (*head)->next;
            free(*head);
            *head = temp;
        }
}