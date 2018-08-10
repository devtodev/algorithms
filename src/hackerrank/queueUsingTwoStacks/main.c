/*
 * main.c
 *
 *  Created on: Aug 10, 2018
 *      Author: karl
 */

#include "stdio.h"
#include "stdlib.h"

// https://www.hackerrank.com/challenges/queue-using-two-stacks/problem

struct node {

    int data;
    struct node *next;

};

struct node *push(struct node *last, int data)
{
	struct node *newTail = malloc(sizeof(struct node));
	newTail->next = NULL;
	newTail->data = data;
	if (last == NULL)
		return newTail;
	last->next = newTail;
	return newTail;
}

int read(struct node *root)
{
	return (root != NULL)?root->data:0;
}

struct node* pull(struct node *root)
{
	struct node *tmp = root;
	if (root == NULL) return NULL;
	root = root->next;
	free(tmp);
	return root;
}

int main() {
	//13 47 74 12 89 74 18 38
	struct node* root = NULL;
	struct node* last = NULL;
	int q = 0, action, value;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &action);
		if (action == 1) {
			scanf("%d", &value);
			last = push(last, value);
			if (root == NULL)
			{
				root = last;
			}
		}
		if (action == 2) {
			root = pull(root);
			if (root == NULL)
				last = NULL;
		}
		if (action == 3) printf("%d\r\n", read(root));
	}
	return 0;
}



