#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* addToEmpty(int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
};

struct node* add_at_end(struct node* tail, int data){
    struct node *newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->next = NULL;

    newP->next = tail->next;
    tail->next = newP;
    tail = tail->next;
    return tail;
};

// Deleting the First Node
struct node* del_at_beg(struct node* tail){
    if(tail==NULL){
        return tail;
    }
    if(tail->next==tail){
        free(tail);
        tail = NULL;
        return tail;
    }
    struct node* temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp=NULL;
    return tail;
};

// Deleting the Last Node
struct node* del_at_end(struct node* tail){
    if(tail==NULL){
        return tail;
    }
    struct node* temp = tail->next;
    if(tail->next == tail){
        free(tail);
        tail = NULL;
        return tail;
    }
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail=temp;
    return tail;
};

// Deleting the Intermediate Node 
struct node* del_at_pos(struct node* tail, int pos){
    if(tail==NULL){
        return tail;
    }
    struct node* temp = tail->next;
    if(tail->next == tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    while(pos>2){
        temp=temp->next;
        pos--;
    }
    struct node* temp2 = temp->next;
    temp->next = temp2->next;
    if(temp2==tail){
        tail=temp;
    }
    free(temp2);
    temp2=NULL;
    return tail;
};

struct node* createList(struct node* tail){
    int data, i;
    tail = addToEmpty(1);

    for(i=2; i<=10; i++){
        tail = add_at_end(tail, i);
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
    tail = createList(tail);

    // After this 4 to 10
    tail = del_at_beg(tail);
    tail = del_at_beg(tail);
    tail = del_at_beg(tail);

    // After this 4 to 7
    tail = del_at_end(tail);
    tail = del_at_end(tail);
    tail = del_at_end(tail);

    // After this 6
    tail = del_at_pos(tail, 2);
    tail = del_at_pos(tail, 3);
    tail = del_at_pos(tail, 1);

    print_ll(tail);

    return 0;
}
