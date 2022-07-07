#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//STACK USING LINKED LIST
//from beginning


//STRUCTURE OF NODE
struct node
{
    int data;
    struct node *Link;
};
struct node *TOP=NULL;  //TOP POINTER

//TAKE INPUT FROM USER IN STACK
int takeInput() {
    int data;
    printf("ENTER DATA");
    scanf("%d", &data);
    return data;
}

//PUSH   TO INSERT ELEMENT IN STACK
void push() {

    int data=takeInput();

    struct node *newNode;

    newNode=(struct node *)malloc(sizeof(struct node));
    
    newNode->data = data;

    if(TOP=NULL) {
        newNode->Link=NULL;
    }
    else {
        newNode->Link = TOP;
    }
    
    TOP = newNode;

}


//POP   TO DELETE ELEMENT FROM STACK
void pop() {
    struct node *temp;
    temp=TOP;
    if(TOP=NULL) {
        printf("EMPTY");
    }
    else {
        printf("POPED ELEMENT %d", TOP->data);
        TOP=TOP->Link;
        free(temp);
    }
}


//PEEK   TO DISPLAY TOP ELEMENT
void peek() {

    if(TOP=NULL) {
        printf("STACK is EMPTY");
    }
    else {
        printf("TOP ELEMent is %d",TOP->data);
    }
}


// DISPLAY    TO DISPLAY ALL ELEMENTS FROM STACK
void display() {

    
   
    if(TOP=NULL) {
        printf("list is EMPTY");
    }
    else {
        struct node *temp=TOP;
        while(temp->Link!=NULL) {
            printf("%d",temp->data);
            temp=temp->Link;
        }
        printf("%d--->NULL\n\n", temp->data);
    }
}

int main() {
    int choice;
    while(choice!=0) {
        printf("\n\nChoose Option\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 0:
            break;
        default:
            printf("Invalid Choice");
            break;
        }
    }
}