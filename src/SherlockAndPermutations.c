/*
 * SherlockAndPermutations.c
 *
 *  Created on: 19 de nov. de 2016
 *      Author: Carlos Miguens
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXLENGTH 1010

unsigned long permutations[MAXLENGTH][MAXLENGTH];
unsigned long rtas[MAXLENGTH];


int SherlockAndPermutation() {
	unsigned long N = 0, zero, one, i;

    for (i = 0; i < MAXLENGTH; i++)
	{
		permutations[i][1] = 1;
		permutations[1][i] = i;
	}

	for (zero = 2; zero < MAXLENGTH; zero++)
		for (one = 2; one < MAXLENGTH; one++)
	{
		permutations[zero][one] = (permutations[zero-1][one] + permutations[zero][one-1]) %(1000000000+7);
	}
    scanf("%lu",&N);
	for(i = 0; i < N; i++){
		scanf("%lu %lu", &zero, &one);
		rtas[i] = permutations[zero][one];
	}

	for (i = 0; i < N; i++)
	{
		printf("%lu\n", rtas[i]);
	}
    return 0;
}
