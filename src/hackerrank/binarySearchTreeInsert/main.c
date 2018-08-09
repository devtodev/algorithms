/*
 * main.c
 *
 *  Created on: Aug 8, 2018
 *      Author: karl
 */
#include "stdio.h"
#include "stdlib.h"

//	https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem

struct node {

    int data;
    struct node *left;
    struct node *right;

};

void preOrder( struct node *root) {

	if( root == NULL )
      return;
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);

}

void findPlace(struct node *root, int data) {
    if (data < root->data)
    {
        if (root->left != NULL)
        {
            findPlace(root->left, data);
        } else {
            root->left = malloc(sizeof(struct node));
            root->left->data = data;
            root->left->left = NULL;
            root->left->right = NULL;
        }
    } else {
        if (root->right != NULL)
        {
            findPlace(root->right, data);
        } else {
            root->right = malloc(sizeof(struct node));
            root->right->data = data;
            root->right->left = NULL;
            root->right->right = NULL;
        }
    }
}

struct node* insert( struct node* root, int data ) {
    struct node* first = root;
    if (root == NULL)
        {
			first = malloc(sizeof(struct node));
			first->data = data;
			first->left = NULL;
			first->right = NULL;
        }
    else
    	findPlace(root, data);
    return first;
}

int main() {
	//13 47 74 12 89 74 18 38
	struct node* root = NULL;
	int cant = 6;
	int a[6] = {4, 2, 3, 1, 7, 6};
	for (int i = 0; i < cant; i++)
	{
		root = insert(root, a[i]);
	}
	preOrder(root);

	return 0;
}

