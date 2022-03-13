# Implementation-of-Binary-Search-Trees
Hi! My aim is to illustrate what a Binary Search Tree is look like by writing the code. 

![binarysearchtree](https://user-images.githubusercontent.com/75504698/158083818-17a80a0d-7ae5-4833-b078-bf58d67bed33.PNG)


In this repo, there are a bunch of functions : 


## Inserting Data to Tree
~~~bash
BST* AddItem(BST* root, int adding);
~~~

## Printing/Traversing Tree
~~~bash
void TraverseInfix_LNR(BST* root);
void TraverseInfix_RNL(BST* root);
void TraversePrefix_NLR(BST* root);
void TraversePrefix_NRL(BST* root);
void TraversePostfix_LRN(BST* root);
void TraversePostfix_RLN(BST* root);
~~~

## Searching an Item in Tree
~~~bash
int SearchData(BST* root, int x);
~~~

## To Find the Smallest and Biggest Items of BST
~~~bash
int FindMaxItem(BST* root);
int FindMinItem(BST* root);
~~~









