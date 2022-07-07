#include<stdio.h>
#include<stdlib.h>

//DOUBLY LINKED LIST
struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *Head, *Tail;

//Take INPUT FROM USER as data
int takeInput() {
	int val;
	printf("\nEnter node value :  ");
	scanf("%d", &val);
	return val;
}


//NODE CREATION
struct node *createNode(int val)
{
	struct node *newNode;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = NULL;
    newNode->prev = NULL;

	return newNode;
}

//RETURN Length of Linked list
int getLength() {
	struct node *temp,*newNode;
	int count=0;
	temp=Head;
	while(temp!=NULL) {
		count++;
		temp=temp->next;
	}
	//printf("length %d",count);
	return count;
}


void insertNode()
{
    struct node *newNode;
    
    newNode=createNode(takeInput());
    //Insert At Beginning if NO NODES ARE PRESENT
	if (Head == NULL)
	{
		Head = Tail = newNode;
	}
	else
	{
		//Insert At the END
		Tail->next=newNode;
		newNode->prev=Tail;
		Tail=newNode;
	}
}


//INSERT AT FIRT POSITION
void insertAtBeginning() {
	
	struct node *newNode;
	newNode=createNode(takeInput());
	
	if (Head!= NULL)
	{
		Head->prev=newNode;
		newNode->next=Head;
		Head=newNode;
	}

}

//INSERT At Position  
void insertAtPosition() {
	int pos,i=1,count;
	count=getLength();
	printf("\nEnter position value :  ");
	scanf("%d", &pos);

	struct node *temp,*newNode;
	
	temp=Head;
	
	if(pos>count) {
		printf("Invalid position");
	}
	else 
	{
		while(i<pos-1) {
			temp=temp->next;
			i++;
		}
		
		newNode=createNode(takeInput());
		newNode->prev=temp;
		newNode->next=temp->next;
		temp->next=newNode;
		newNode->next->prev=newNode;
	}	
}


//Node Deletion from beginning
void deleAtBeginning()
{
	struct node *temp;

	temp = Head;
	if(Head==NULL) {
		printf("No Node Present in List");
	}
	else {
		Head=temp->next;
		Head->prev=NULL;
	}
	free(temp);
}

//DELETE from END
void delefromEnd()
{
	struct node *temp;
	struct node *previousNode;
	temp = Tail;
	if(Head==NULL) {
		printf("No Node Present in List");
	}
	else {
        Tail=Tail->prev;
		Tail->next=NULL;
	}
	free(temp);
	
}


//DELETE NODE From Linked list by its value enetred by USER
void deletefromValue()
{
	struct node *temp;
	struct node *previousNode;
	temp = Head;
	if(Head==NULL) {
		printf("No Node Present in List");
	}
	int DELETE_ELEMENT=takeInput();
	while (temp->data != DELETE_ELEMENT)
	{
		previousNode = temp;
		temp = temp->next;
	}
	previousNode->next=temp->next;
	temp->next->prev=previousNode;
	free(temp);
}


//REVERSE a LINKED LIST
void reverseLinkedList()
{
	struct node *currNode,*nextNode;
	currNode=Head;
	while (currNode != NULL)
	{
		nextNode = currNode->next;
		currNode->next=currNode->prev;
		currNode->prev=nextNode;
		currNode=nextNode;
	}

	currNode=Head;
	Head=Tail;
	Tail=currNode;
}


//DISPLAY LINKED LIST
void display()
{
	struct node *temp;
	printf("\n\nEntered Linklist : \n");
	for(temp = Head;temp != NULL ;temp = temp->next)
	{
		printf("--> %d", temp->data);
	}
}

int main() {
	int choice;
	while(1) {
		printf("\n\nChoose Option\n");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:
			insertNode();
			break;
		case 2:
			insertAtBeginning();
			break;
		case 3:
			insertAtPosition();
			break;
		case 4:
			deleAtBeginning();
			break;
        case 5:
			delefromEnd();
			break;
		case 6:
			deletefromValue();
			break;
		case 7:
			reverseLinkedList();
			break;
		case 10:
			display();
			break;
		case 11:
			getLength();
			break;
		case 0:
			exit(1);
		default:
			printf("\nError......\nEnter correct option");
			break;
		}
	}
    return 0;
}