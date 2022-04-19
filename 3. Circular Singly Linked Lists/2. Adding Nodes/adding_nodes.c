#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

// Adding Node to the Empty list
struct node* addToEmpty(int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
};

// Adding Node at beginning of the list
struct node* add_at_beg(struct node* tail, int data){
    struct node *newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->next = tail->next;
    tail->next = newP;
    return tail;
};

// Adding Node at end of the list
struct node* add_at_end(struct node* tail, int data){
    struct node *newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->next = NULL;

    newP->next = tail->next;
    tail->next = newP;
    tail = tail->next;
    return tail;
};

// Adding between Nodes or at certain position
struct node* add_after_pos(struct node* tail, int data, int pos){
    struct node* p = tail->next;
    struct node* newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->next = NULL;
    while(pos>1){
        p=p->next;
        pos--;
    }
    newP->next = p->next;
    p->next = newP;
    if (p==tail){
        tail=tail->next;
    }
    return tail;
};

void print_ll(struct node* tail){
    if(tail == NULL){
        printf("Linked List is empty.\n");
    }
    else{
        struct node* p = tail->next;
        printf("The Circular Singly Linked list is: \n");
        do{
            printf("%d ", p->data);
            p=p->next;
        }
        while(p!=tail->next);
    }
}

int main(){
    struct node *tail;
    tail = addToEmpty(1);

    // After this 4 3 2 1
    tail = add_at_beg(tail, 2);
    tail = add_at_beg(tail, 3);
    tail = add_at_beg(tail, 4);

    // After this 4 3 2 1 5 6 7
    tail = add_at_end(tail, 5);
    tail = add_at_end(tail, 6);
    tail = add_at_end(tail, 7);

    // After this 4 3 2 1 8 5 9 6 7 10
    tail = add_after_pos(tail, 8, 4);
    tail = add_after_pos(tail, 9, 6);
    tail = add_after_pos(tail, 10, 9);

    print_ll(tail);

    return 0;
}
