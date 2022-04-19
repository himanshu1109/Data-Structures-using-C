#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void print_ll(struct node *head){
    if (head==NULL){
        printf("Linked List is empty");
    }
    struct node *ptr = head;
    printf("Linked List is : \n");
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

void count_nodes(struct node *head){
    if (head==NULL){
        printf("Linked List is empty");
    }
    struct node *ptr = head;
    int count = 0;
    while(ptr!=NULL){
        count++;
        ptr = ptr->link;
    }
    printf("\nLength of Linked List is : \n%d",count);
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 58;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));

    struct node *ptr = head;

    for (int i=1; i<=5; i++){
        current->data = i;
        current->link = NULL;
        ptr->link = current;
        ptr = ptr->link;
        current = malloc(sizeof(struct node));
    }

    print_ll(head);
    count_nodes(head);
    free(current);
}
