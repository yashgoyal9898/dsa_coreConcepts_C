#include<stdio.h>
#include<conio.h>

//STACK USING ARRAY

int TOP=-1;
int stack[5];
int size=5;

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
    if(TOP==size-1) {
        printf("OverFlow");
    }
    else {
        TOP++;
        stack[TOP] = data;
    }

}


//POP   TO DELETE ELEMENT FROM STACK
void pop() {

    if(TOP==-1) {
        printf("UnderFlow");
        return;
    }
    else {
        TOP--;
    }
}


//PEEK   TO DISPLAY TOP ELEMENT
void peek() {
    if(TOP==-1) {
        printf("STACK IS EMPTY");
    }
    else {
        printf("TOP MOST ELEMENT is %d", stack[TOP]);
    }
}


// DISPLAY    TO DISPLAY ALL ELEMENTS FROM STACK
void display() {
    int i;
    printf("Stack Elements");
    for(i=TOP; i>=0; i--) {

        printf("-->%d ",stack[i]);
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