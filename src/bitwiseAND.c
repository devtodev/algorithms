/*
 * bitwiseAND.c
 *
 *  Created on: 11 de dic. de 2016
 *      Author: karl
 */

#include "stdio.h"

int getBitwiseAnd(int N, int K)
{
	int i, j, max = 0;

	for (i = 0; i < N; i++)
		for (j = i+1; j < N; j++)
		{
			if (((i & j) > max) && ((i & j) < K))
			{
				max = i & j;
			}
		}

	return max;
}

int main()
{
	int S[10000];
	int T, N, K, i;
	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d %d", &N, &K);
		S[i] = getBitwiseAnd(N, K);
	}

	for (i = 0; i < T; i++)
	{
		printf("%d\n", S[i]);
	}
	return 0;
}
