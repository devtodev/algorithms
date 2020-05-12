/*
 * velocity.c
 *
 *  Created on: Apr 24, 2020
 *      Author: Carlos Miguens
 */
#include <limits.h>
#include <stdio.h>


int solution3(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
	int diff = INT_MAX;
	int rep = 0;
	int count = 0;
	int k = 0;
	for (k = 1; k < N - 1; k+=2)
	{
		if (diff != (A[k - 1] - A[k]))
		{
			diff = (A[k - 1] - A[k]);
			if (rep > 1) count += 3 * (rep-1);
			if (rep == 1) count ++;
			rep = 0;
		} else {
			rep++;
		}
		if (diff == (A[k] - A[k + 1]))
		{
			rep++;
		} else {
			k--;
		}
	}
	if ((k+1 == N) && (A[N - 2] - A [N - 1] == diff)) rep++;
	if (rep > 1) count += 3 * (rep-1);
	if (rep == 1) count ++;
	return count;
}

int mainVelocity()
{
	int A[] = {-1, 1, 3, 3, 3, 2, 3, 2, 1, 0};
	printf("%d", solution3(A, 10));
}
