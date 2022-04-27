#include<stdio.h>
#include<stdlib.h>
#define MAX 32

int stack[MAX];
int top=-1;

int isFull(){
    if(top==MAX-1){
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
    top = top+1;
    stack[top] = data;
}

// Checking if stack is empty or not
int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

// Popping Element from Stack
int pop(){
    int value;
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    value = stack[top];
    top = top-1;
    return value;
}

// Decimal to Binary function
void dec2bin(int n){
    while(n!=0){
        push(n%2);
        n=n/2;
    }
}

// Printing Stack
void print(){
    int i;
    if(top == -1){
        printf("Stack Underflow\n");
        return;
    }
    printf("The number in binary is : ");
    for(i=top;i>=0;i--){
        printf("%d", stack[i]);
    }
    printf("\n");
}

int main(){
    int dec;
    printf("Enter the decimal number: ");
    scanf("%d",&dec);

    dec2bin(dec);
    print();
    return 0;
}