#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node *next;
};

struct node* addToEmpty(int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = temp;
    temp->data = data;
    temp->next = temp;
    return temp;
};

struct node* add_at_end(struct node* tail, int data){
    struct node* newP = addToEmpty(data);
    if(tail==NULL){
        return newP;
    }
    else{
        struct node* temp = tail->next;
        newP->next = temp;
        newP->prev = tail;
        tail->next = newP;
        temp->prev = newP;
        tail = newP;
        return tail;
    }
};

struct node* createList(struct node* tail){
    int n, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    if(n==0){
        return tail;
    }

    printf("Enter the element for the node 1: ");
    scanf("%d", &data);
    tail = addToEmpty(data);

    for(i=1; i<n; i++){
        printf("Enter the element for the node %d: ",i+1);
        scanf("%d",&data);
        tail = add_at_end(tail, data);
    }
    return tail;
};

void print_ll(struct node* tail){
    if(tail == NULL){
        printf("Linked List is empty.\n");
    }
    else{
        struct node* p = tail->next;
        printf("The Circular Doubly Linked list is: \n");
        do{
            printf("%d ", p->data);
            p=p->next;
        }
        while(p!=tail->next);
    }
}

void count_nodes(struct node *tail){
    int count = 0;
    struct node* temp = tail->next;
    while(temp != tail){
        temp = temp->next;
        count++;
    }
    count++;
    printf("\nLength of Linked List is : \n%d",count);
}

int main(){
    struct node *tail;
    tail = createList(tail);

    print_ll(tail);
    count_nodes(tail);

    return 0;
}
