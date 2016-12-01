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

long getPrimes(long N, long M)
{
	long iterator, primeBuffer = -1, twins = 0;

	for (int value = N; value <= M; value++)
	{
		iterator = 2;
		while ((iterator <= (value/2)+1) && (value % iterator != 0))
		{
			iterator++;
		}
		if (iterator > (value/2)+1)
		{
			if (value - primeBuffer == 2)
			{
				twins++;
			}
			primeBuffer = value;
		}
	}
	return twins;
}

int TwinsPrimesMain() {
	long N, M;
	scanf("%ld %ld", &N, &M);
	printf("%ld", getPrimes(N, M));
    return 0;
}
