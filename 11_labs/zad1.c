#include<stdio.h>
#include<stdlib.h>

struct tnode {
    int value;
    struct tnode *next;
};

struct tnode* add_el(struct tnode* head, struct tnode* el);
void print_list(struct tnode *head);
void del_el(struct tnode** head, int var);
struct tnode* add_list(struct tnode* head1, struct tnode* head2);
void free_list(struct tnode** head);

int main(void) {

    struct tnode *head = NULL;
    struct tnode el_1;
    struct tnode el_2;
    struct tnode el_3;
    struct tnode el_4;
    struct tnode el_5;
    struct tnode el_6;

    el_1.value = 3;
    el_2.value = 1;
    el_3.value = 5;
    el_4.value = 6;
    el_5.value = 2;
    el_6.value = 5;

    head = add_el(head,&el_6);
    head = add_el(head,&el_1);
    head = add_el(head,&el_2);
    head = add_el(head,&el_3);
    head = add_el(head,&el_4);  
    head = add_el(head,&el_5);

    printf("\nBEFORE deleting: \n");
    print_list(head);

    del_el(&head,5);
    printf("\nAFTER deleting: \n");
    print_list(head);

    struct tnode *head_1 = NULL;
    struct tnode el_11;
    struct tnode el_22;
    struct tnode el_33;
    struct tnode el_44;

    el_11.value = 7;
    el_22.value = 45;
    el_33.value = 78;
    el_44.value = 1;

    head_1 = add_el(head_1,&el_11);
    head_1 = add_el(head_1,&el_22);
    head_1 = add_el(head_1,&el_33);
    head_1 = add_el(head_1,&el_44);

    printf("\nNEW list: \n");
    print_list(head_1);

    struct tnode *new_list = add_list(head,head_1);
    printf("OLD + NEW list: \n");
    print_list(new_list);

    free_list(&new_list);
    free_list(&head);
    free_list(&head_1);

}

struct tnode* add_el(struct tnode* head, struct tnode* el) {
    if(head == NULL) {
        head = el;
        head->next=head;
        return head;
    }

    struct tnode *temp = head;

    for( ;temp->next != head; temp=temp->next);

    temp->next = el;
    el->next = head;

    return head;
}

void print_list(struct tnode *head) {
    struct tnode *temp = head;

    printf("HEAD -> ");

    for( ;temp->next != head; temp = temp->next) printf("%d -> ",temp->value);
    printf("%d -> ",temp->value);
    
    printf("HEAD\n");
}

void del_el(struct tnode** head, int var) {
    struct tnode *temp = *head;
    struct tnode *t = NULL;

    for( ;temp->next != *head; temp = temp->next) {
        if(temp == *head && temp->value == var) {
            t = *head;
            for( ;t->next != *head; t = t->next);
            *head = (*head)->next;  
            t->next = *head;
        }
        else if(temp != *head && temp->value == var) {
            t->next = temp->next; 
        }
        t = temp;
    }
}

struct tnode* add_list(struct tnode* head1, struct tnode* head2) {
    struct tnode *list = head1;
    struct tnode *temp = head1;

    for( ;temp->next != head1; temp = temp->next);
    temp->next = head2;

    temp = head2;
    for( ;temp->next!=head2; temp = temp->next);
    temp->next = head1;

    return list;
}

void free_list(struct tnode** head) {
    struct tnode *temp = *head;
    struct tnode *t = NULL;

    if(temp->next == *head) {
        free(*head); return;
    }

    while(temp != *head) {
        t = (*head)->next;
        free(*head);
        temp = t;
    }
}