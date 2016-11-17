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

int main2() {
    int i, j, p1, p2, p3, p4, p5, p6, p7, sum, max = -32768;

    int arr[6][6] = {{0, -4, -6, 0, -7, -6},
    		{-1, -2, -6, -8, -3, -1},
    		{-8, -4, -2, -8, -8, -6},
    		{-3, -1, -2, -5, -7, -4},
    		{-3, -5, -3, -6, -6, -6},
    		{-3, -6, 0, -8, -6, -7}};


    for(j = 0; j < 4; j++)
    {
    	for(i = 0; i < 4; i++)
    	{
    		p1 = arr[i][j];
    		p2 = arr[i][j+1];
    		p3 = arr[i][j+2];
    		p4 = arr[i+1][j+1];
    		p5 = arr[i+2][j];
    		p6 = arr[i+2][j+1];
    		p7 = arr[i+2][j+2];
    		sum = p1 + p2 + p3 + p4 + p5 + p6 + p7;
    		if (sum > max)
    			max = sum;
    	}
    }

    printf("%d ", max);

    return 0;
}
