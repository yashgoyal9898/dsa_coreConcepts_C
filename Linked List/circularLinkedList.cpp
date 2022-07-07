#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *Tail=NULL;

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
	int count=1;
	temp=Tail->next;
	while(temp->next!=Tail->next) {
		count++;
		temp=temp->next;
	}
	//printf("length %d",count);
	return count;
}


//Node Insertion
void insertNode()
{

    struct node *newNode;
    newNode = createNode(takeInput());
	
    //Insert At Beginning if NO NODES ARE PRESENT
	if (Tail == NULL)
	{
		Tail = newNode;
		Tail->next=newNode;
	}
	else
	{
		//Insert AT END
		newNode->next=Tail->next;
		Tail->next=newNode;
		Tail=newNode;	
	}
    
}


//INSERT AT FIRT POSITION
void insertAtBeginning() {
	
	struct node *newNode;
	newNode=createNode(takeInput());
	
	if (Tail!= NULL)
	{
		newNode->next=Tail->next;
		Tail->next=newNode;
	}

}


//INSERT AFTER a Position  
void insertAfterPosition() {
	int pos,i=1,count;
	count=getLength();
	
	printf("\nEnter position value :  ");
	scanf("%d", &pos);
	
	struct node *temp,*newNode;
	temp=Tail->next;
	
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
		
		newNode->next=temp->next;
		temp->next=newNode;
	}	
}

//Node Deletion from beginning
void deleAtBeginning()
{
	struct node *temp;

	temp = Tail->next;
	if(Tail==NULL) {
		printf("No Node Present in List");
	}
	else if (temp->next == temp) {
		Tail = NULL;
		free(temp);
	}
	else {
		Tail->next=temp->next;
		free(temp);
	}
}

//DELETE from end
void delefromEnd()
{
	struct node *currNode;
	struct node *previousNode;
	currNode = Tail->next;

	if(Tail==NULL) {
		printf("No Node Present in List");
	}
	else if (currNode->next == currNode) {
		Tail = NULL;
		free(currNode);
	}
	else {
		while(currNode->next!=Tail->next) {
			previousNode=currNode;
			currNode=currNode->next;
		}
		previousNode->next=Tail->next;
		Tail=previousNode;
		free(currNode);
	}
}


//DELETE NODE From Linked list by its value enetred by USER
void deletefromValue()
{
	
	struct node *temp;
	struct node *previousNode;
	
	temp = Tail->next;
	
	if(Tail==NULL) {
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
	struct node *previousNode=NULL,*currNode,*nextNode;
	
	currNode=Tail->next;
	nextNode=currNode->next;
	
	if(Tail==NULL) {
		printf("No Node Present in List");
	}

	while (currNode != Tail)
	{
		previousNode=currNode;
		currNode=nextNode;
		nextNode=currNode->next;
		currNode->next=previousNode;
	}
	nextNode->next = Tail;
	Tail = nextNode;
}


//TO DISPLAY LINKED LIST
void display()
{
	struct node *temp;
	printf("\n\nEntered Linklist : \n");
	for(temp = Tail->next; temp->next!= Tail->next; temp = temp->next)
	{
		printf("--> %d", temp->data);
	}
    printf("--> %d", temp->data);
}


int main()
{
	int choice;
	while (1)
	{
        printf("\n\nChoose Option\n");
		//printf("\n\n1. Create or Insert Node \n2. InsertAt Beginning \n3. Insert After Position \n4. Display \n5. Exit\n6. Length \n7. Delete From Beg \n8. Delete From end\n9. Delete from Position");
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
