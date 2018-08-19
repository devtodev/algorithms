/*
 * main.c
 *
 *  Created on: Aug 19, 2018
 *      Author: karl
 *
 * https://www.hackerrank.com/challenges/tree-inorder-traversal/problem
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {

    int data;
    struct node *left;
    struct node *right;

};

struct node* insert( struct node* root, int data ) {

	if(root == NULL) {

        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;

	} else {

		struct node* cur;

		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}

		return root;
	}
}

/************************************************************************************************/

struct Node {
	int data;
	struct Node *next;
};

void addToList(int data, struct Node *list){
	struct Node *new;
	while ((list->next != NULL) && (list->data < data))
	{
		list = list->next;
	}
	new = malloc(sizeof(struct Node));
	if (list->data < data)
	{
		new->data = data;
	} else {
		new->data = list->data;
		list->data = data;
	}
	new->next = list->next;
	list->next = new;
}

void tripTree( struct node *root, struct Node *list) {
	if (root == NULL) return;
	addToList(root->data, list);
	if (root->left != NULL)	tripTree(root->left, list);
	if (root->right != NULL)tripTree(root->right, list);
}

void inOrder( struct node *root) {
	struct Node list, *cursor;
	list.data = -1;
	list.next = NULL;
	tripTree(root, &list);
	cursor = list.next;
	while (cursor != NULL)
	{
		printf("%d ", cursor->data);
		cursor = cursor->next;
	}
}

/************************************************************************************************/

int main() {

    struct node* root = NULL;

    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }

	inOrder(root);
    return 0;
}

