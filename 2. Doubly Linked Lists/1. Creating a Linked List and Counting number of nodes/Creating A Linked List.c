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

struct node* createList(struct node* head){
    int n, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    if(n==0){
        return head;
    }

    printf("Enter the element for the node 1: ");
    scanf("%d", &data);
    head = addToEmpty(head, data);

    for(i=1; i<n; i++){
        printf("Enter the element for the node %d: ",i+1);
        scanf("%d",&data);
        head = add_at_end(head, data);
    }
    return head;
};

void print_ll(struct node *head){
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

void count_nodes(struct node *head){
    if (head==NULL){
        printf("Linked List is empty");
    }
    struct node *ptr = head;
    int count = 0;
    while(ptr!=NULL){
        count++;
        ptr = ptr->next;
    }
    printf("\nLength of Linked List is : \n%d",count);
}

int main(){
    struct node *head = NULL;
    head = createList(head);

    print_ll(head);
    count_nodes(head);

    return 0;
}
