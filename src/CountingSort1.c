/*
 * CountingSort1.c
 *
 *  Created on: 25 nov. 2016
 *      Author: charly
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long count(int arr[], int number, int N)
{
	long sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (number == arr[i])
			sum++;
	}
	return sum;
}

int main() {
	int N;
	int arr[1000000];

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 100; i++)
	{
			printf("%ld ", count(arr, i, N));
	}

    return 0;
}
