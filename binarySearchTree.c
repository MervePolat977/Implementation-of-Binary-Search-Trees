#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}BST;

BST* AddItem(BST* root, int adding);
void TraverseInfix_LNR(BST* root);
void TraverseInfix_RNL(BST* root);
void TraversePrefix_NLR(BST* root);
void TraversePrefix_NRL(BST* root);
void TraversePostfix_LRN(BST* root);
void TraversePostfix_RLN(BST* root);
int SearchData(BST* root, int x);
int FindMaxItem(BST* root);
int FindMinItem(BST* root);


//INSERTING ITEMS TO THE TREE
BST* AddItem(BST* root, int adding)
{
    if(root == NULL){
        BST* newNode = (BST*)malloc(sizeof(BST));
        newNode->data = adding;
        newNode->right = NULL;
        newNode->left = NULL;
        
        return newNode;
    }
    
    BST* temp = root;
    if(temp->data < adding){
        temp->right = AddItem(temp->right, adding);
    }else{
        temp->left = AddItem(temp->left, adding);
    }
    
    return temp;
}


//Infix (left-node-right)
void TraverseInfix_LNR(BST* root)
{
    if(root == NULL)
        return;
    TraverseInfix_LNR(root->left);
    printf("%d ", root->data);
    TraverseInfix_LNR(root->right);
}


//Infix (right-node-left)
void TraverseInfix_RNL(BST* root)
{
    if(root == NULL)
        return;
    TraverseInfix_RNL(root->right);
    printf("%d ", root->data);
    TraverseInfix_RNL(root->left);
}


//Prefix (node-left-right) 
void TraversePrefix_NLR(BST* root)
{
    if(root == NULL)
        return;
    printf("%d ", root->data);
    TraversePrefix_NLR(root->left);
    TraversePrefix_NLR(root->right);
}


//Prefix (node-right-left)
void TraversePrefix_NRL(BST* root)
{
    if(root == NULL)
        return;
    printf("%d ", root->data);
    TraversePrefix_NRL(root->right);
    TraversePrefix_NRL(root->left);
}


//Postfix (left-right-node)
void TraversePostfix_LRN(BST* root)
{
    if(root == NULL)
        return;
    TraversePostfix_LRN(root->left);
    TraversePostfix_LRN(root->right);
    printf("%d ", root->data);
    
}


//Postfix (right-left-node)
void TraversePostfix_RLN(BST* root)
{
    if(root == NULL)
        return;
    TraversePostfix_RLN(root->right);
    TraversePostfix_RLN(root->left);
    printf("%d ", root->data);
}


//SEARCHING DATA 
int SearchData(BST* root, int x)
{
    if(root == NULL)
        return -1;
    if(root->data == x)
        return 1;
    if(SearchData(root->left, x) == 1)
        return 1;
    if(SearchData(root->right, x) == 1)
        return 1;
    
    return -1;
}


//FINDING THE BIGGEST ELEMENT
int FindMaxItem(BST* root)
{
    while(root->right != NULL)
        root = root->right;
    return root->data;
}

//FINDING THE SMALLEST ELEMENT
int FindMinItem(BST* root)
{
    while(root->left != NULL)
        root = root->left;
    return root->data;
}



int main(){
    BST* root = NULL;
    
    root = AddItem(root, 56);
    root = AddItem(root, 26);
    root = AddItem(root, 200);
    root = AddItem(root, 18);
    root = AddItem(root, 28);
    root = AddItem(root, 190);
    root = AddItem(root, 213);
    root = AddItem(root, 12);
    root = AddItem(root, 24);
    root = AddItem(root, 27);
    
    
    printf("TraverseInfix (left-node-right) : ");
    TraverseInfix_LNR(root);
    
    printf("\n\nTraverseInfix (right-node-left) : ");
    TraverseInfix_RNL(root);
    
    printf("\n\nTraversePrefix (node-left-right): ");
    TraversePrefix_NLR(root);
    
    printf("\n\nTraversePrefix (node-right-left): ");
    TraversePrefix_NRL(root);
    
    printf("\n\nTraversePostfix (right-left-node): ");
    TraversePostfix_RLN(root);
    
    printf("\n\nTraversePostfix (left-right-node): ");
    TraversePostfix_LRN(root);
    
    //Searching data
    printf("\n\nResult of searching for '%d' = %d", 26, SearchData(root, 26));
    printf("\n\nResult of searching for '%d' = %d", 100, SearchData(root, 100));
    printf("\n\nResult of searching for '%d' = %d", 39, SearchData(root, 39));
    printf("\n\nResult of searching for '%d' = %d", 200, SearchData(root, 200));
    printf("\n\nResult of searching for '%d' = %d", 18, SearchData(root, 18));
        
    
    //Finding max-min elements
    printf("\n\nThe smallest item : %d\n", FindMinItem(root));
    printf("The biggest item : %d\n", FindMaxItem(root));
    
    
    
    
    
    return 0;
}
