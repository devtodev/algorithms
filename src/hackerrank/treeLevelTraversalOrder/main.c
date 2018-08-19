/*
 * main.c
 *
 *  Created on: Aug 19, 2018
 *      Author: karl
 *
 * https://www.hackerrank.com/challenges/tree-level-order-traversal/problem
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

struct Level {
	int data[250];
	int size;
};

struct Level *level[250];

void addDataToLevel(int data, int deep)
{
	if (level[deep] == NULL)
	{
		level[deep] = malloc(sizeof(struct Level));
		level[deep]->size = 0;
	}
	level[deep]->data[level[deep]->size] = data;
	level[deep]->size++;
}

void tripTree(struct node *root, int deep)
{
	if (root == NULL) return;
	addDataToLevel(root->data, deep);
	if (root->left != NULL) tripTree(root->left, deep+1);
	if (root->right != NULL) tripTree(root->right, deep+1);
}

void levelOrder( struct node *root) {
	tripTree(root, 0);
	for (int i = 0; level[i] != NULL; i++)
	{
		for (int j = 0; j < level[i]->size; j++)
			printf("%d ", level[i]->data[j]);
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

	levelOrder(root);
    return 0;
}

