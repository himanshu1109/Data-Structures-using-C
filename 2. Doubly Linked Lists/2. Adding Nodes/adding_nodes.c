#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

// Adding Node at the Empty list
struct node* addToEmpty(struct node* head, int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
};

// Adding Node at beginning of the list
struct node* add_at_beg(struct node* head, int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
};

// Adding Node at Ending of the list
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

// Adding Node between nodes after position
struct node* add_after_pos(struct node* head, int data, int position){
    struct node* newP = NULL;
    struct node* temp = head;
    struct node* temp2 = NULL;
    newP = addToEmpty(newP, data);

    while(position!=1){
        temp = temp->next;
        position--;
    }
    if(temp->next == NULL){
        temp->next = newP;
        newP->prev = temp;
    }
    else{
        temp2 = temp->next;
        temp->next = newP;
        temp2->prev = newP;
        newP->prev = temp;
        newP->next = temp2;
    }
    return head;
};

// Adding Node between nodes before position
struct node* add_before_pos(struct node* head, int data, int position){
    struct node* newP = NULL;
    struct node* temp = head;
    struct node* temp2 = NULL;
    newP = addToEmpty(newP, data);
    while(position>2){
        temp=temp->next;
        position--;
    }
    if(position==1){
        head = add_at_beg(head, data);
    }
    else{
        temp2 = temp->next;
        temp->next = newP;
        temp2->prev = newP;
        newP->next = temp2;
        newP->prev = temp;
    }
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

    // After this 4 3 2 1
    head = add_at_beg(head, 2);
    head = add_at_beg(head, 3);
    head = add_at_beg(head, 4);

    // After this 4 3 2 1 5 6 7
    head = add_at_end(head, 5);
    head = add_at_end(head, 6);
    head = add_at_end(head, 7);

    // After this 4 3 2 1 8 9 5 6 10 7
    head = add_after_pos(head, 8, 4);
    head = add_after_pos(head, 9, 5);
    head = add_after_pos(head, 10, 8);

    // After this 4 3 2 11 12 1 8 13 9 5 6 10 7
    head = add_before_pos(head, 11, 4);
    head = add_before_pos(head, 12, 5);
    head = add_before_pos(head, 13, 8);

    print_ll(head);

    return 0;
}
