#ifndef INCLUDE_H
#define INCLUDE_h

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct tnode {
    int value;
    struct tnode *next;
    struct tnode *prev;
};

struct tnode* add_last(struct tnode* head, struct tnode* el);
struct tnode* add_first(struct tnode* head, struct tnode* el);
struct tnode* del_el_all(struct tnode** head, int var);
struct tnode* del_el_one(struct tnode** head, int var);
struct tnode* div_list(struct tnode** head);
void print_list_next(struct tnode*);
void print_list_prev(struct tnode*);
void add_sort(struct tnode** head1, struct tnode* el);
void free_list(struct tnode**);

#endif