#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

int isFull(struct node* newNode){
    if(newNode==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(int data, struct node** top){
    struct node* newNode ;
    newNode = malloc(sizeof(newNode));
    if(isFull(newNode)){
        printf("Stack Overflow");
        return;
    }
    newNode->data = data;
    newNode->link = NULL;

    newNode->link = *top;
    *top = newNode;
}

int isEmpty(struct node* top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int pop(struct node** top){
    if(isEmpty(top)){
        printf("Stack Underflow");
        exit(1);
    }
    struct node* temp;
    int val;
    temp = *top;
    val = temp->data;
    *top = (*top)->link;
    free(temp);
    temp = NULL;
    return val;
}

int peek(struct node* top){
    if(isEmpty(top)){
        printf("Stack Underflow");
        exit(1);
    }
    return top->data;
}

void reverse_stack(struct node** top){
    struct node *top1 = NULL;
    struct node *top2 = NULL;

    // Pushing onto temp stack 1 from original stack
    while(*top!=NULL){
        push(pop(top), &top1);
    }

    // Pushing onto temp stack 2 from temp stack 1
    while(top1!=NULL){
        push(pop(&top1), &top2);
    }

    // Pushing onto original stack from temp stack 2
    while(top2!=NULL){
        push(pop(&top2), top);
    }
}

void print(struct node* top){
    if(isEmpty(top)){
        printf("Stack Underflow\n");
        return;
    }
    struct node* temp;
    temp = top;
    printf("The stack elements are : ");
    while(temp){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){
    int choice, data;
    struct node* top = NULL;
    while(1){
        printf("\n");
        printf("1. Push\n");
        printf("2. Print\n");
        printf("3. Reverse the Stack\n");
        printf("4. Quit\n");
        printf("Please enter your choice: ");
        scanf("%d",&choice);

        switch (choice){
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d",&data);
                push(data, &top);
                break;
            case 2:
                print(top);
                break;
            case 3:
                reverse_stack(&top);
                printf("Stack is reversed.\n");
                break;
            case 4:
                exit(1);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
