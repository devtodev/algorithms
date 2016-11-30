/*
 * Twins_Primes.c
 *
 *  Created on: 30 nov. 2016
 *      Author: Carlos Miguens
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct sNodo nodoPrime;

struct sNodo{
	long value;
	int prime;
	nodoPrime *next;
};

long getPrimes(long N, long M)
{
	nodoPrime *first, *cursor;
	long iterator, primeBuffer = -1, twins = 0;
	// init the list
	first = malloc(sizeof(struct sNodo));
	first->value = N;
	first->prime = 1;
	cursor = first;
	cursor->next = NULL;
	for (int i = N+1; i <= M; i++)
	{
		cursor->next = malloc(sizeof(struct sNodo));
		cursor = cursor->next;
		cursor->value = i;
		cursor->prime = 0;
		cursor->next = NULL;
	}
	// iterate
	cursor = first;
	while (cursor != NULL)
	{
		iterator = 2;
		while ((iterator < cursor->value) && (cursor->value % iterator != 0))
		{
			iterator++;
		}
		if (cursor->value == iterator)
		{
			cursor->prime = 1;
			if (cursor->value - primeBuffer == 2)
			{
				twins++;
				//printf("%ld %ld\n", primeBuffer, cursor->value);
			}
			primeBuffer = cursor->value;
		}
		cursor = cursor->next;
	}
	return twins;
}

int twinsPrime() {
	long N, M;
	scanf("%ld %ld", &N, &M);
	printf("%ld", getPrimes(N, M));
    return 0;
}
