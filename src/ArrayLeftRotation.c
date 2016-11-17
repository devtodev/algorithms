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

int main() {
    unsigned long n, l, j, value;

    scanf("%lu",&n);
    scanf("%lu",&l);
    for(j = 0; j < n; j++)
    {
    	scanf("%lu",&value);
    	addNode(value, n-1 == j);
    }
    cursor = &first;

    for (j = 0; j < l; j++)
    	cursor = cursor->next;

    for (j = 0; j < n; j++)
	{
		printf("%lu ", cursor->value);
		cursor = cursor->next;
	}
    return 0;
}
