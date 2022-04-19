#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node *next;
};

struct node* addToEmpty(struct node* head, int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
};

struct node* add_at_end(struct node* head, int data){
    struct node* temp, *tp;
    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    tp=head;
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    return head;
};

// Reversing the list
struct node* reverse(struct node* head){
    struct node* ptr1 = head;
    struct node* ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while(ptr2!=NULL){
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;

    return head;
};

void print_ll(struct node* head){
    if (head==NULL){
        printf("Linked List is empty");
    }
    struct node *ptr = head;
    printf("Linked List is : \n");
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct node *head = NULL;
    head = addToEmpty(head, 1);

    for (int i=2; i<=10; i++){
        head = add_at_end(head, i);
    }

    // After this 10 to 1
    head = reverse(head);
    print_ll(head);

    return 0;
}
