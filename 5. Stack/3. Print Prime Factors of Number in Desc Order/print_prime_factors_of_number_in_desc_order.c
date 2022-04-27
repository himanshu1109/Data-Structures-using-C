#include<stdio.h>
#include<stdlib.h>
#define MAX 6

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

// Prime fact function that will push prime factors of number in stack
void prime_fact(int num){
    int i=2;
    while(num!=1){
        while(num%i==0){
            push(i);
            num=num/i;
        }
        i++;
    }
    printf("Prime factors of the number in descending order are as follows: ");
    while(top!=-1){
        printf("%d ",pop());
    }
}

int main(){
    int number;
    printf("Enter the number: ");
    scanf("%d",&number);

    prime_fact(number);
    return 0;
}