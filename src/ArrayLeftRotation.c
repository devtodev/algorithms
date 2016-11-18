/***
 * Carlos Miguens
 * 2016/11/16
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
struct tNode *cursorALR = &first;

void addNodeALR(unsigned long value, int last)
{
	cursorALR->value = value;
	if (last == 1)
	{
		cursorALR->next = &first;
	} else {
		cursorALR->next = malloc(sizeof(struct tNode));
		cursorALR = cursorALR->next;
	}
}

int array2DDS() {
    unsigned long n, l, j, value;

    scanf("%lu",&n);
    scanf("%lu",&l);
    for(j = 0; j < n; j++)
    {
    	scanf("%lu",&value);
    	addNodeALR(value, n-1 == j);
    }
    cursorALR = &first;

    for (j = 0; j < l; j++)
    	cursorALR = cursorALR->next;

    for (j = 0; j < n; j++)
	{
		printf("%lu ", cursorALR->value);
		cursorALR = cursorALR->next;
	}
    return 0;
}
