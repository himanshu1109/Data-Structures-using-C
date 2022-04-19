#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* add_at_beg(struct node* head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = NULL;

    ptr->link = head;
    head = ptr;
    return head;
}

// Reversing the List
struct node* reverse(struct node *head){
    struct node *prev = NULL;
    struct node *next = NULL;
    while(head!=NULL){
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
};

void print_ll(struct node* head){
    if (head==NULL){
        printf("List is empty\n");
    }
    struct node *ptr = head;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;

    for (int i=2; i<=12; i++){
        head = add_at_beg(head, i);
    }

    printf("Original Linked List is : \n");
    print_ll(head);

    // After Reversing 1 to 12
    printf("Reversed Linked List is : \n");
    head = reverse(head);
    print_ll(head);

    return 0;
}
