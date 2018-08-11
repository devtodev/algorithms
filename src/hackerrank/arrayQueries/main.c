/*
 * main.c
 *
 *  Created on: Aug 11, 2018
 *      Author: karl
 */

#include "stdio.h"
#include "stdlib.h"

// https://www.hackerrank.com/challenges/array-and-simple-queries/problem
// note: works well, but in some cases need improve the performance

struct Node {

    int data;
    struct Node *next;

};

struct Node* root = NULL; // for do it in a production code use getters and setters
struct Node* last = NULL;


struct Node *push(struct Node *last, int data)
{
	struct Node *newTail = malloc(sizeof(struct Node));
	newTail->next = NULL;
	newTail->data = data;
	if (last == NULL)
		return newTail;
	last->next = newTail;
	return newTail;
}
struct Node* toFront(struct Node* node, int v1, int v2)
{
	struct Node* oldFirst = node;
	struct Node* newFirst = NULL;
	struct Node* previous = NULL;

	for (int i = 2; i < v1; i++)
		node = node->next;

	newFirst = node->next;
	previous = node;

	for (int i = v1; i <= v2; i++)
		node = node->next;

	previous->next = node->next;
	node->next = oldFirst;

	return newFirst;
}

void toBack(struct Node* node, int v1, int v2)
{
	struct Node* firstOfLasts = root;
	struct Node* previous = NULL;

	for (int i = 1; i < v1; i++)
	{
		previous = node;
		node = node->next;
	}

	firstOfLasts = node;

	for (int i = v1; i < v2; i++)
		node = node->next;

	if (v1 == 1) {
		root = node->next;
	} else
		previous->next = node->next;

	node->next = NULL;
	last->next = firstOfLasts;
	last = node;
}

int main() {
	int n, m;
	int action, value1, value2;
	scanf("%d %d", &n, &m);
	scanf("%d", &value1);
	last = push(last, value1);
	root = last;

	for (int i = 1; i < n; i++)
	{
		scanf("%d", &value1);
		last = push(last, value1);
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &action, &value1, &value2);
		if ((action == 1) && (value1 != 1))
			root = toFront(root, value1, value2);
		else
			if ((action == 2) && (value1 != n))
				toBack(root, value1, value2);
	}
	printf("%d\r\n", abs(root->data - last->data));
	while (root != NULL)
	{
		printf("%d ", root->data);
		root = root->next;
	}
	return 0;
}



