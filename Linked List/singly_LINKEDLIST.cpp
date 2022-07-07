#include <stdio.h>
#include <stdlib.h>

//SINGLY LINKED LIST
struct node
{
	int data;
	struct node *next;
};

struct node *Head = NULL;

//Take INPUT FROM USER as data
int takeInput() {
	int val;
	printf("\nEnter node value :  ");
	scanf("%d", &val);
	return val;
}


//Node Creation
struct node *createNode(int val)
{
	struct node *newNode;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = NULL;

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
	return count;
}

//Node Insertion
void insertNode()
{

	//Insert At Beginning if NO NODES ARE PRESENT
	if (Head == NULL)
	{
		Head = createNode(takeInput());
	}
	else
	{
		//Insert AT END
		struct node *temp;
		temp = Head;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = createNode(takeInput());
	}
}

//INSERT AT FIRT POSITION
void insertAtBeginning() {
	
	struct node *newNode;
	newNode=createNode(takeInput());
	
	if (Head!= NULL)
	{
		newNode->next=Head;
		Head=newNode;
	}

}

//INSERT AFTER a Position  
void insertAfterPosition() {
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
		while(i<pos) {
			temp=temp->next;
			i++;
		}
		
		newNode=createNode(takeInput());
		newNode->next=temp->next;
		temp->next=newNode;
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
		free(temp);
	}
}

//DELETE from end
void delefromEnd()
{
	struct node *temp;
	struct node *previousNode;
	temp = Head;
	while(temp->next!=NULL) {
		previousNode=temp;
		temp=temp->next;
	}
	if(Head==NULL) {
		printf("No Node Present in List");
	}
	else {
		previousNode->next=NULL;
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
	free(temp);
}


//REVERSE a LINKED LIST
void reverseLinkedList()
{
	struct node *temp;
	struct node *previousNode=NULL,*currNode,*nextNode;
	currNode=Head;
	while (currNode != NULL)
	{
		nextNode = currNode->next;
		currNode->next=previousNode;
		previousNode=currNode;
		currNode=nextNode;
	}

	//TO DISPLAY REVERSE LINKED LIST
	for(temp = previousNode;temp != NULL ;temp = temp->next)
	{
		printf("--> %d", temp->data);
	}
}

//TO DISPLAY LINKED LIST
void display()
{
	struct node *temp;
	printf("\n\nEntered Linklist : \n");
	for(temp = Head;temp != NULL ;temp = temp->next)
	{
		printf("--> %d", temp->data);
	}
}


int main()
{
	int choice;
	while (1)
	{
		printf("\n\n1. Create or Insert Node \n2. InsertAt Beginning \n3. Insert After Position \n4. Display \n5. Exit\n6. Length \n7. Delete From Beg \n8. Delete From end\n9. Delete from Position");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			insertNode();
			break;
		case 2:
			insertAtBeginning();
			break;
		case 3:
			insertAfterPosition();
			break;
		case 4:
			display();
			break;
		case 5:
			exit(1);
		case 6:
			getLength();
			break;
		case 7:
			deleAtBeginning();
			break;
		case 8:
			delefromEnd();
			break;
		case 9:
			deletefromValue();
			break;
		case 10:
			reverseLinkedList();
			break;
		default:
			printf("\nError......\nEnter correct option");
			break;
		}
	}
	return 0;
}
