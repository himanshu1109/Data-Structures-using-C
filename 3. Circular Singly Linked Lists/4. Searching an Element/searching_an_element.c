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

// Searching Element
int searchElement(struct node* tail, int element){
    struct node* temp = temp;
    int index = 0;
    if(tail==NULL){
        return -2;
    }
    temp=tail->next;
    do{
        if(temp->data==element)
            return index;
        temp=temp->next;
        index++;
    }
    while(temp!=tail->next);
    return -1;
}

struct node* createList(struct node* tail){
    int data, i;
    tail = addToEmpty(1);

    for(i=2; i<=10; i++){
        tail = add_at_end(tail, i);
    }
    return tail;
};

int main(){
    struct node *tail;
    tail = createList(tail);

    printf("Element is found at index : %d",searchElement(tail, 4));

    return 0;
}
