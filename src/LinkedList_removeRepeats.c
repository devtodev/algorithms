/*
 * LinkedList_removeRepeats.c
 *
 *  Created on: 6 dic. 2016
 *      Author: charly
 */


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* removeDuplicates(Node *head){
  //Write your code here
    Node *cursor = head;
    Node *checker, *temp;
    while (cursor != NULL)
    {
    	checker = cursor;
    	while (checker->next != NULL)
    	{
    		if (cursor->data == checker->next->data)
    		{
    			temp = checker->next;
    			cursor->next = checker->next->next;
    			checker = temp;
    		} else {
    			checker = checker->next;
    		}
    	}
    	cursor = cursor->next;
    }
    return head;
}

Node* insertNode(Node *head,int data)
{
  Node *p = (Node*)malloc(sizeof(Node));
  p->data = data;
  p->next=NULL;

  if(head==NULL){
   head=p;

  }
  else if(head->next==NULL)
  {
      head->next=p;

  }
  else{
  Node *start=head;
  while(start->next!=NULL)
    start=start->next;

  start->next=p;

  }
      return head;
}

void display(Node *head)
{
	Node *start=head;
	while(start)
	{
		printf("%d ",start->data);
		start=start->next;
	}
}

int mainLinkedinList()
{
	int T,data;
    scanf("%d",&T);
    Node *head=NULL;
    while(T-->0){
        scanf("%d",&data);
        head=insertNode(head,data);
    }
    head=removeDuplicates(head);
	display(head);
	return 0;
}
