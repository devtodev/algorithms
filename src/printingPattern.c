/*
 * evenOdd.c
 *
 *  Created on: Apr 22, 2020
 *      Author: Carlos Miguens
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main9()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int cursorI = abs(n - i);
        for (int ii = 0; ii < n; ii++)
        {
            int value = (i <= ii) ? cursorI : n - ii;
            printf("%d ", value);
        }
        for (int ii = n - 2; ii >= 0; ii--)
        {
            int value = (i <= ii) ? cursorI : n - ii;
            printf("%d ", value);
        }
        printf("\n");
    }
        for(int i = n - 2; i >= 0; i--)
    {
        int cursorI = abs(n - i);
        for (int ii = 0; ii < n; ii++)
        {
            int value = (i <= ii) ? cursorI : n - ii;
            printf("%d ", value);
        }
        for (int ii = n - 2; ii >= 0; ii--)
        {
            int value = (i <= ii) ? cursorI : n - ii;
            printf("%d ", value);
        }
        printf("\n");
    }
    return 0;
}
