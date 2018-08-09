/*
 * main.c
 *
 *  Created on: Aug 9, 2018
 *      Author: karl
 */

#include "stdio.h"
#include "stdlib.h"

// https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem

struct node {

    int data;
    struct node *left;
    struct node *right;

};

struct nodeList {
    struct node *node;
    struct nodeList *next;
};

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

int findNode( struct node *root, int valueToFind, struct nodeList *path) {
	int foundItOut = 0;
	if( root == NULL )
      return -1;
	if (root->data == valueToFind)
	{
		foundItOut = 1;
	} else {
		if (root->left != NULL)
		{
			foundItOut = findNode(root->left, valueToFind, path);
		}
		if ((root->right != NULL) && (foundItOut == 0))
		{
			foundItOut = findNode(root->right, valueToFind, path);
		}
	}

	if (foundItOut == 1)
	{
		while (path->next != NULL)
		{
			path = path->next;
		}
		path->next = malloc(sizeof(struct nodeList));
		path->next->node = root;
		path->next->next = NULL;
	}

	return foundItOut;
}

struct node *lca( struct node *root, int v1, int v2 ) {
	struct nodeList pathToV1, pathToV2, *pv1, *pv2;
	pathToV1.node = NULL;
	pathToV1.next = NULL;
	pathToV2.node = NULL;
	pathToV2.next = NULL;
	if (findNode(root, v1, &pathToV1) == 0) return NULL;
	if (findNode(root, v2, &pathToV2) == 0) return NULL;
	pv1 = pathToV1.next;
	while (pv1 != NULL)
	{
		pv2 = pathToV2.next;
		while (pv2 != NULL)
		{
			if ((pv1->node == pv2->node) && (pv1->node != NULL))
				return pv1->node;
			pv2 = pv2->next;
		}
		pv1 = pv1->next;
	}
	return NULL;
}

int main() {
	//13 47 74 12 89 74 18 38
	struct node* root = NULL;
	struct node* lcaNode = NULL;
	int cant = 6;
	int a[6] = {4, 2, 3, 1, 7, 6};
	for (int i = 0; i < cant; i++)
	{
		root = insert(root, a[i]);
	}
	lcaNode = lca(root, 1, 3 );
	if (lcaNode != NULL)
		printf("%d", lcaNode->data);
	else
		printf("NODE NOT FOUND");
	return 0;
}

