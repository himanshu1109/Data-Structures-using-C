#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
} *top=NULL;

int isFull(struct node* newNode){
    if(newNode==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

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

int isEmpty(){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

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

void palindrome_check(char* s){
    int i=0;
    while(s[i] != 'X'){
        push(s[i]);
        i++;
    }
    i++;
    while(s[i]){
        if(isEmpty() || s[i]!=pop()){
            printf("Given String is not a Palindrome.");
            exit(1);
        }
        i++;
    }
    if(isEmpty()){
        printf("Given String is a Palindrome.");
    }
    else{
        printf("Given String is not a Palindrome.");
    }
}

int main(){
    char s[100];
    printf("Please enter the string : ");
    scanf("%s",s);
    palindrome_check(s);
    return 0;
}
