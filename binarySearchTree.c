#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* right;
    struct node* left;
}BST;

BST* AddItem(BST* root, int adding)
{
    if(root == NULL)
    {
        BST* newNode = (BST*)malloc(sizeof(BST));
        newNode->data = adding;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    BST* temp = root;
    if(temp->data < adding)
        temp->right = AddItem(temp->right, adding);
        
    else{
        temp->left = AddItem(temp->left, adding);
    }

    return root;
}


void Traverse(BST* root)
{
    if(root == NULL)
        return;
    Traverse(root->left);
    printf("%d ", root->data);
    Traverse(root->right);
}

int SearchData(BST* root, int x)
{
    if(root == NULL)
        return -1;
    if(root->data == x)
        return 1;
    if(SearchData(root->right, x) == 1)  
        return 1;
    if(SearchData(root->left, x) == 1)
        return 1;
        
    else -1;
}

//max
int Max(BST* root)
{
    while(root->right != NULL)
        root = root->right;
    return (root->data);
}

//Min 
int Min(BST* root)
{
    while(root->left != NULL)
        root = root->left;
    return (root->data);
}
int main(){
    
    BST* root = NULL;
    
    root = AddItem(root, 23);
    root = AddItem(root, 13);
    root = AddItem(root, 26);
    root = AddItem(root, 29);
    root = AddItem(root, 60);
    root = AddItem(root, 48);
    root = AddItem(root, 67);
    root = AddItem(root, 49);
    
    Traverse(root);
    
    
    printf("\n%d\n", SearchData(root, 28));
    
    printf("Max: %d  - Min: %d\n", Max(root), Min(root));
    
    
    
    
    
    
    return 0;
}
