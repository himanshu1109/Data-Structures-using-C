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

// Deleting the last node
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

// Deleting the first node method 1
struct node* del_first_1(struct node* head){
    struct node* temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    head->prev = NULL;
    return head;
};

// Deleting the first node method 2
struct node* del_first_2(struct node* head){
    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
};

// Deleting the last Node
struct node* del_last(struct node* head){
    struct node* temp = head;
    struct node* temp2;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);
    return head;
};

// Deleting the Node at specific Position or intermediate node
struct node* del_pos(struct node* head, int position){
    struct node* temp = head;
    struct node* temp2 = NULL;
    if (position==1){
        head = del_first_1(head);
        return head;
    }
    while(position>1){
        temp = temp->next;
        position--;
    }
    if(temp->next == NULL){
        head = del_last(head);
    }
    else{
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
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

    for (int i=2; i<=10; i++){
        head = add_at_end(head, i);
    }

    // After this 3 to 10
    head = del_first_1(head);
    head = del_first_1(head);

    // After this 5 to 10
    head = del_first_2(head);
    head = del_first_2(head);

    // After this 5 to 8
    head = del_last(head);
    head = del_last(head);

    // After this 5 8
    head = del_pos(head, 3);
    head = del_pos(head, 2);

    print_ll(head);

    return 0;
}
