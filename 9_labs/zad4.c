#include<stdio.h>
#include<stdlib.h>

struct tnode {
  char value;
  struct tnode * next;
};

void add_front(struct tnode **head, char val);
void print(struct tnode *head);
struct tnode *delete(struct tnode **head, char val);

int main(void) {
    struct tnode *head = NULL;
    
    add_front(&head,'a');
    add_front(&head,'a');
    add_front(&head,'A');
    add_front(&head,'a');
    add_front(&head,' ');
    add_front(&head,'a');
    add_front(&head,'A');
    add_front(&head,' ');
    add_front(&head,'a');
    add_front(&head,'A');
    add_front(&head,'A');
    add_front(&head,' ');
    
    printf("\nHEAD before deleting: \n");
    print(head);

    struct tnode *left = delete(&head,'a');
    printf("\nNEW list: \n");
    print(left);

    printf("\nHEAD after deleting: \n");
    print(head);
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

struct tnode *delete(struct tnode **head, char val) {
    struct tnode *temp = *head;
    struct tnode *t = NULL;
    struct tnode *left = NULL;

    for(;temp; temp = temp->next) {
        if(temp->value == val || temp->value == val - 32) {
            if(temp == *head) {
                 add_front(&left,temp->value);
                *head = (*head)->next;
            }
            else {
                add_front(&left,temp->value);
                struct tnode *ptr = temp->next;
                for(;ptr;ptr=ptr->next) {
                    if(ptr->value != val && ptr->value != val - 32) { t->next = ptr; break;}
                }
                if(!ptr) t->next = NULL;
            }
        }
        t = temp;
    }

    return left;
}

void print(struct tnode *head) {
    printf("head -> ");
    for(;head;head=head->next)  printf("['%c'] -> ",head->value);
    printf("NULL\n");
}