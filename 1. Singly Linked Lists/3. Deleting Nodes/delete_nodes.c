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

// Deleting First Node
struct node *del_first(struct node *head){
    if (head==NULL){
        printf("List is Empty\n");
    }
    else{
        struct node *temp = head;
        head = head->link;
        free(temp);
        temp=NULL;
    }
    return head;
};

// Deleting Last Node Method 1
void del_last(struct node *head){
    if (head==NULL){
        printf("List is Empty\n");
    }
    else if (head->link == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node *temp = head;
        struct node *temp2 = head;
        while(temp->link != NULL){
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        free(temp);
        temp=NULL;
    }
};

// Deleting Last Node Method 2 using Single Pointer
void del_last_2(struct node *head){
    if (head==NULL){
        printf("List is Empty\n");
    }
    else if (head->link == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node *temp = head;
        while(temp->link->link != NULL){
            temp = temp->link;
        }
        free(temp->link);
        temp->link=NULL;
    }
};

// Deleting Node at Particular Position
void del_pos(struct node **head, int position){
    struct node *current = *head;
    struct node *previous = *head;
    if (*head==NULL){
        printf("List is Empty\n");
    }
    else if(position==1){
        *head = current->link;
        free(current);
        current = NULL;
    }
    else{
        while(position!=1){
            previous = current;
            current = current->link;
            position--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
};

// Deleting Entire List
struct node *del_list(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        temp = head->link;
        free(head);
        head = temp;
    }
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

    // After this 11 to 1
    printf("Linked List After first Node Deletion is : \n");
    head = del_first(head);
    print_ll(head);

    // After this 11 to 2
    printf("Linked List After Last Node Deletion is : \n");
    del_last(head);
    print_ll(head);

    // After this 11 to 3
    printf("Linked List After Last Node Deletion using Single Pointer is : \n");
    del_last_2(head);
    print_ll(head);

    // After this 11 to 8 + 6 to 3
    printf("Linked List After Certain Position Node Deletion is : \n");
    del_pos(&head, 5);
    print_ll(head);

    // After this list Becomes Empty
    head = del_list(head);
    print_ll(head);

    return 0;
}
