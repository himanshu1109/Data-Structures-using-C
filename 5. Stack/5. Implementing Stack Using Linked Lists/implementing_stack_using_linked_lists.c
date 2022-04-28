#include<stdio.h>
#include<stdlib.h>

// Creating Node of Linked List
struct node{
    int data;
    struct node* link;
} *top=NULL;

// Checking if stack is full or not
int isFull(struct node* newNode){
    if(newNode==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// Pushing Element in Stack
void push(int data){
    struct node* newNode ;
    newNode = malloc(sizeof(newNode));
    if(isFull(newNode)){
        printf("Stack Overflow");
        return;
    }
    newNode->data = data;
    newNode->link = NULL;

    newNode->link = top;
    top = newNode;
}

// Checking if stack is empty or not
int isEmpty(){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

// Popping Element from Stack
int pop(){
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    struct node* temp;
    temp = top;
    int value;
    value = temp->data;

    top = top->link;
    free(temp);
    temp = NULL;
    return value;
}

// TopMost Element of Stack
int peek(){
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    return top->data;
}

// Printing Stack
void print(){
    if(isEmpty()){
        printf("Stack Underflow\n");
        return;
    }
    struct node* temp;
    temp = top;
    printf("The Stack Elements are: ");
    while(temp){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){
    int choice, data;
    while(1){
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print all the elements of the stack\n");
        printf("5. Quit\n");
        printf("Please enter your choice: ");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                data = pop();
                printf("Deleted element is %d\n",data);
                break;
            case 3:
                printf("The topmost element of the stack is %d\n",peek());
                break;
            case 4:
                print();
                break;
            case 5:
                exit(1);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
