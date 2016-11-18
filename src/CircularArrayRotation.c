/*
 * CircularArrayRotation.c
 *
 *  Created on: 18/11/2016
 *      Author: Carlos Miguens
 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


struct tNode {
	struct tNode *next;
	unsigned long value;
};

struct tNode first;
struct tNode *cursor = &first;

void addNode(unsigned long value, int last)
{
	cursor->value = value;
	if (last == 1)
	{
		cursor->next = &first;
	} else {
		cursor->next = malloc(sizeof(struct tNode));
		cursor = cursor->next;
	}
}

int main(){
    int n;
    int k;
    int q;
    scanf("%d %d %d",&n,&k,&q);
    int rst[q], final[n];
    int a = 0;
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a);
       addNode(a, n-1 == a_i);
    }
    cursor = &first;
    for (int move = 0; move < k; move++)
    {
		cursor = cursor->next;
    }
    for (int move = 0; move < n; move++)
	{
		final[move]= cursor->value;
		cursor = cursor->next;
	}

    for(int a0 = 0; a0 < q; a0++){
        int m;
        scanf("%d",&m);
        rst[a0] = final[m];
    }

    for (int i = 0; i < n; i++)
	{
		printf("%d\n", rst[i]);
	}


    return 0;
}



