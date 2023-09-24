#include "include_functions.h"

int main() {
    srand(time(NULL));

    struct tnode *head = NULL;
    
    struct tnode el1; el1.value = rand()%100;
    struct tnode el2; el2.value = 5;
    struct tnode el3; el3.value = rand()%100;
    struct tnode el4; el4.value = rand()%100;
    struct tnode el5; el5.value = 5;
    struct tnode el6; el6.value = rand()%100;
    struct tnode el22; el22.value = rand()%100;
    struct tnode el33; el33.value = rand()%100;
    struct tnode el44; el44.value = rand()%100;
    struct tnode el55; el55.value = rand()%100;
    struct tnode el66; el66.value = 5;

    head = add_first(head,&el1);
    head = add_first(head,&el2);
    head = add_first(head,&el3);
    head = add_first(head,&el4);
    head = add_first(head,&el5);
    head = add_first(head,&el6);
    head = add_last(head,&el22);
    head = add_last(head,&el33);
    head = add_last(head,&el44);
    head = add_last(head,&el55);
    head = add_last(head,&el66);

    print_list_next(head);
    print_list_prev(head);

    struct tnode *deleted_one = del_el_one(&head,5);
    printf("\nDELETED one:");
    print_list_next(deleted_one);
    print_list_next(head);

    struct tnode *deleted_all = del_el_all(&head,5);
    printf("\nDELETED all:");
    print_list_next(deleted_all);
    print_list_next(head);

    printf("\nADDING elements increasing: ");
    struct tnode additional_1; additional_1.value = 77;
    struct tnode additional_2; additional_2.value = 56;

    add_sort(&head,&additional_1);
    add_sort(&head,&additional_2);
    print_list_next(head);

    printf("\nDIVIDIED for even and not even elements: ");
    struct tnode *divieded_list = div_list(&head);
    
    print_list_next(head);
    print_list_next(divieded_list);

    free_list(&deleted_one);
    free_list(&deleted_all);
    free_list(&divieded_list);
    free_list(&head);
}

