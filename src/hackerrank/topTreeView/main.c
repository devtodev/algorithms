/*
 * main.c
 *
 *  Created on: Aug 19, 2018
 *      Author: karl
 *
 * https://www.hackerrank.com/challenges/tree-top-view/problem
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

#define MAXNODES 500
#define MIDDLE MAXNODES/2

int nodes[MAXNODES] = { 0 };
int nodes_deep[MAXNODES] = { 0 };
int minLevel = MIDDLE;
int maxLevel = MIDDLE;

void addnode(int data, int level, int deep) {
	if ((nodes[level] == 0) || ((nodes[level] != 0) && (nodes_deep[level] > deep)))
	{
		nodes[level] = data;
		nodes_deep[level] = deep;
	}
	minLevel = (minLevel > level)?level:minLevel;
	maxLevel = (maxLevel < level)?level:maxLevel;
}

void tripTheTree( struct node *root, int level, int deep) {
	if (root == NULL) return;
	addnode(root->data, level, deep);
	if (root->left != NULL) tripTheTree(root->left, level-1, deep + 1);
	if (root->right != NULL) tripTheTree(root->right, level+1, deep + 1);
}


void topView( struct node *root) {
	tripTheTree(root, MIDDLE, 0);
	for (int i = minLevel; i <= maxLevel; i++)
		printf("%d ", nodes[i]);
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

	topView(root);
    return 0;
}

