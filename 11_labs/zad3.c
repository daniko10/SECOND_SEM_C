#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 20
#define TRUE 1

struct sorted_list {
    struct person_data *data; 
    struct sorted_list *next;
};

struct person_data {
    char l_name[SIZE + 1];
    char f_name[SIZE + 1];
    int birth_year;
};

struct sorted_list *add_sorted_lname(struct sorted_list *head, struct person_data *to_add, struct sorted_list **head_age);
void print_lname(struct sorted_list *head);

int main(void) {
    struct sorted_list *head = NULL;
    struct sorted_list *head_age = NULL;

    int choice;
    while(TRUE) {
        printf("If you want to add a person -> (1) else quits : "); scanf("%d",&choice);
        if(choice == 1) {
            if(!head) head = add_sorted_lname(head,NULL,&head_age);
            else head = add_sorted_lname(head,head->data,&head_age);
        } else break;
        system("cls");
    }
    system("cls");
    
    print_lname(head);
    print_lname(head_age);
}

struct sorted_list *add_sorted_lname(struct sorted_list *head, struct person_data *to_add, struct sorted_list **head_age) {
    struct sorted_list *temp = malloc(sizeof(struct sorted_list));
    to_add = malloc(sizeof(struct person_data));
    
    to_add->l_name[SIZE] = '\0';
    to_add->f_name[SIZE] = '\0';


    printf("\nENTER your :\n");
    printf("LAST name : "); scanf("%s",to_add->l_name);
    printf("FIRST name : "); scanf("%s",to_add->f_name);
    printf("AGE : "); scanf("%d",&(to_add->birth_year));

    temp->data = to_add;

    if(!head) {
        head = temp;
        head->next = NULL;
        return head;
    }

    struct sorted_list *t = head;
    struct sorted_list *t_t = head;
    for( ; t ; t = t->next ) {
        if(strcmp(temp->data->l_name,t->data->l_name) < 0) break;
        t_t = t;
    }
    if(t == head) {
        temp->next = head;
        head = temp;
    } else {
        t_t->next = temp;
        temp->next = t;
    }

    struct sorted_list *temp_1 = malloc(sizeof(struct sorted_list));
    temp_1->data = malloc(sizeof(struct person_data));
    
    temp_1->data->l_name[SIZE] = '\0';
    temp_1->data->f_name[SIZE] = '\0';
    strcpy(temp_1->data->l_name,temp->data->l_name);
    strcpy(temp_1->data->f_name,temp->data->f_name);
    temp_1->data->birth_year = temp->data->birth_year;

    struct sorted_list *to_head_2 = *head_age;
    if(to_head_2 == NULL) {
        *head_age = temp_1;
        (*head_age)->next = NULL;
    } else {
        struct sorted_list *t_age = NULL; 
        for( ;to_head_2; to_head_2 = to_head_2->next) {
            if(to_head_2->data->birth_year > temp_1->data->birth_year) break;
            t_age = to_head_2;
        }
        if(to_head_2 == *head_age) {
            temp_1->next = *head_age;
            *head_age = temp_1;
        } else {
            t_age->next = temp_1;
            temp_1->next = to_head_2;
        }
    }

    return head;
}

void print_lname(struct sorted_list *head) {
    for( ;head; head = head->next ) printf("%s %s %d\n",head->data->l_name,head->data->f_name,head->data->birth_year);
    printf("\n");
}
