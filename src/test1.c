/*
 * test1.c
 *
 *  Created on: Apr 24, 2020
 *      Author: karl
 */

#include <stdio.h>

int solution1(int A[], int N) {
    int p = -1;
    int max = -1;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if ((p < 0) && (A[i] > 0))
        {
            p = i;
            count = 0;
        }
        if ((i + 1 < N) && (A[i+1] >= 0) && (A[i] >= 0))
        {
            // sum
            count += A[i] + A[i+1];
            i++;
        }
        if ((p >= 0) && ((i + 1 >= N)  || (A[i+1] < 0) || (A[i] < 0)))
        {
            // close and compare
        	if (p != i)
        	{
        		max = (max < count)?count:max;
        	} else {
        		max = (max < A[i])?A[i]:max;
        	}
        	count = 0;
        	p = -1;
        }
    }
    return max;
}


int main123123()
{
	int A[] = {-8, 3, 0, 5, -3, 12};
	printf("%d", solution1(A, 6));
	return 0;
}
