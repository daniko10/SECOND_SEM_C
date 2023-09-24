#include "stack.h"

int main() {
    struct tnode *head = NULL;
    struct tnode el1;   el1.value = 4;
    struct tnode el2;   el2.value = 2;
    struct tnode el3;   el3.value = 1;
    struct tnode el4;   el4.value = 41;
    struct tnode el5;   el5.value = 9;

    push_one(&head,&el1);
    push_one(&head,&el2);
    push_one(&head,&el3);
    push_one(&head,&el4);
    push_one(&head,&el5);

    printf("First part of exercise: \n");
    print_stack(head);

    printf("\n\nAdding new list to previous :\n");
    struct tnode *head_2 = NULL;
    struct tnode el11;   el11.value = 41;
    struct tnode el22;   el22.value = 22;
    struct tnode el33;   el33.value = 31;
    struct tnode el44;   el44.value = 414;
    struct tnode el55;   el55.value = 911;

    push_one(&head_2,&el11);
    push_one(&head_2,&el22);
    push_one(&head_2,&el33);
    push_one(&head_2,&el44);
    push_one(&head_2,&el55);

    head = push_many(head,&head_2);
    print_stack(head);
    
    printf("\nAFTER deleting one: \n");
    struct tnode *deleted = pop_one(&head);
    print_stack(head);

    printf("\nAFTER deleting x elements: \n");
    struct tnode *result = pop_x(&head,5);
    print_stack(result);

    clear_st(&head);
}