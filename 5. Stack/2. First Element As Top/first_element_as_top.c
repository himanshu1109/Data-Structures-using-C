#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stack_arr[MAX];
int first = -1;

// Checking if stack is full or not
int isFull(){
    if(first==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}

// Pushing Element in Stack
void push(int data){
    if(isFull()){
        printf("Stack Overflow");
        return;
    }
    int i;
    first += 1;
    for(i=first;i>0;i--){
        stack_arr[i] = stack_arr[i-1];
    }
    stack_arr[0] = data;
}

// Checking if stack is empty or not
int isEmpty(){
    if(first==-1){
        return 1;
    }
    else{
        return 0;
    }
}

// Popping Element from Stack
int pop(){
    int i, value;
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    value = stack_arr[0];
    for(i=0; i<first; i++){
        stack_arr[i] = stack_arr[i+1];
    }
    first-=1;
    return value;
}

// TopMost Element of Stack
int peek(){
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    return stack_arr[0];
}

// Printing the Stack
void print(){
    int i;
    if(first == -1){
        printf("Stack Underflow\n");
        exit(1);
    }
    for(i=0;i<=first;i++){
        printf("%d ", stack_arr[i]);
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