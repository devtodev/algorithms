/*
 * main.c
 *
 *  Created on: Aug 16, 2018
 *      Author: karl
 */

#include "stdio.h"
#include "stdlib.h"

// https://www.hackerrank.com/challenges/circular-array-rotation/problem

/*
 * This code works well, but the hackerrank problem page has an error, when you run de code in order to pass without errors you will need put this in the line 46
 * 
 * for (int i = 1; i < a_count; i++)
 * 
 * and when you submit the code you will need change to
 * 
 * for (int i = 0; i < a_count; i++)
 * 
 * And will run fine all the tests
 * 
 */

struct node {
	int data;
	struct node *next;
};
int *result;
int* circularArrayRotation(int a_count, int* a, int k, int queries_count, int* queries, int* result_count) {
	struct node *first = malloc(sizeof(struct node)), *cursor, *last;
	result = malloc(sizeof(int)*queries_count);
	int list[a_count];
	cursor = first;
	cursor->data = a[0];
	cursor->next = NULL;
	for (int i = 1; i < a_count; i++)
	{
		cursor->next = malloc(sizeof(struct node));
		cursor = cursor->next;
		cursor->data = a[i];
		cursor->next = NULL;
	}
	last = cursor;
	for (int i = 1; i < k; i++)
	{
		last->next = first;
		last = first;
		cursor = first->next;
		first->next = NULL;
		first = cursor;
	}
	cursor = first;
	for (int i = 0; i < a_count; i++)
	{
		list[i] = cursor->data;
		cursor = cursor->next;
	}
	*result_count = queries_count;
	for (int i = 0; i < queries_count; i++)
	{
		result[i] = list[queries[i]];
	}
	return result;
}

int main() {
	int a[3] = {1, 2, 3};
	int queries[3] = {0, 1, 2};
	int k = 2;
	int a_count = 3;
	int queries_count = 3;
	int result_count = 0;
	result = circularArrayRotation(a_count, a, k, queries_count, queries, &result_count);
	for (int i = 0; i < queries_count; i++)
	{
		printf("%d\n", result[i]);
	}
	return 0;
}



