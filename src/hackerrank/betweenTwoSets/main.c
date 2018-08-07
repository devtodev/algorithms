/*
 * main.c
 *
 *  Created on: Aug 7, 2018
 *      Author: karl
 */
#include "stdio.h"

// https://www.hackerrank.com/challenges/between-two-sets/problem

int getTotalX(int a_count, int* a, int b_count, int* b) {
    int y = 0, ok = 0, x = 0, maxa = a[0], mina = a[0], minb = b[0], maxb = b[0], first = 0, last = 0, cant = 0;
    for (x = 0; x < a_count; x++)
    {
        maxa = (maxa < a[x])?a[x]:maxa;
        mina = (mina > a[x])?a[x]:mina;
    }
    first = (maxa%mina == 0)?maxa:maxa*mina;
    for (x = 0; x < b_count; x++)
    {
        maxb = (maxb < b[x])?b[x]:maxb;
        minb = (minb > b[x])?b[x]:minb;
    }
    last = (maxb%minb == 0)?minb:maxb*minb;
    for (x = first; x <= last; x = x+maxa)
    {
    	ok = 0;
    	for (y = 0; ((y < b_count) && (ok == 0)); y++)
    	{
    		if (b[y]%x != 0) ok = 1;
    	}
    	for (y = 0; ((y < a_count) && (ok == 0)); y++)
		{
			if (x%a[y] != 0) ok = 1;
		}
    	if (ok == 0)
    		cant++;
    }
    return cant;
}

int main() {
	int a[2] = {2, 4};
	int b[3] = {16, 32, 96};
	printf("%d", getTotalX(2, a, 3, b));
	return 0;
}

