#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode() {
    struct node *newNode;
    int value;
    newNode=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data");
    scanf("%d",&value);
    if(value==-1) return 0;
    newNode->data=value;
    newNode->left=createNode();
    newNode->right=createNode();
    return newNode;
}

// preorderTraversal traversal
void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("-> %d ", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}


int main() {
    struct node *root=createNode();


    printf("PreOredr Traversal");
    preorderTraversal(root);
    return 0;
}