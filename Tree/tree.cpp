#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value) {
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

// preorderTraversal traversal
void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("-> %d ", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {
  root->left = createNode(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {
  root->right = createNode(value);
  return root->right;
}

int takeInput() {
    int value;
    printf("Enter Node VAlue");
    scanf("%d",value);
    return value;
}

int main() {
    struct node *root=createNode(takeInput());

     insertLeft(root, 2);
     insertRight(root, 3);

     insertLeft(root->left, 4);
     insertLeft(root->left->left,8);
     insertRight(root->left->left,9);

     insertRight(root->left, 5);
     insertLeft(root->left->right,10);
     insertRight(root->left->right,11);
    
     insertLeft(root->right, 6);
     insertRight(root->right, 7);

    printf("PreOredr Traversal");
    preorderTraversal(root);
    return 0;
}