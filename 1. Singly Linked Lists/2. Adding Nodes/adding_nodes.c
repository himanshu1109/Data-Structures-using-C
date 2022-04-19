#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

// Adding Node at beginning of the list method 1
struct node* add_at_beg(struct node* head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = NULL;

    ptr->link = head;
    head = ptr;
    return head;
}

// Adding Node at beginning of the list method 2 using double pointers
void add_at_beg_2(struct node **head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = NULL;

    ptr->link = *head;
    *head = ptr;
}

// Adding Node at the end of the list
struct node* add_at_end(struct node* ptr, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp;
}

// Adding Node at Certain Position
void add_at_pos(struct node* head, int data, int pos){
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    pos--;
    while(pos!=1){
        ptr=ptr->link;
        pos--;
    }

    ptr2->link = ptr->link;
    ptr->link = ptr2;
}

void print_ll(struct node* head){
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

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;

    struct node *pt = head;
    // After this 4 3 2 1
    head = add_at_beg(head, 2);
    head = add_at_beg(head, 3);
    head = add_at_beg(head, 4);

    // After this 13 12 11 4 3 2 1
    add_at_beg_2(&head, 11);
    add_at_beg_2(&head, 12);
    add_at_beg_2(&head, 13);

    // After this 13 12 11 4 3 2 1 5 6 7
    pt = add_at_end(pt, 5);
    pt = add_at_end(pt, 6);
    pt = add_at_end(pt, 7);

    // After this 13 12 11 8 9 4 3 10 2 1 5 6 7
    add_at_pos(head, 8, 4);
    add_at_pos(head, 9, 5);
    add_at_pos(head, 10, 8);

    print_ll(head);

    return 0;
}
