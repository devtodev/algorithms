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


void printNumber(int n)
{
    if (n == 0) printf("zero\n");
    if (n == 1) printf("one\n");
    if (n == 2) printf("two\n");
    if (n == 3) printf("three\n");
    if (n == 4) printf("four\n");
    if (n == 5) printf("five\n");
    if (n == 6) printf("six\n");
    if (n == 7) printf("seven\n");
    if (n == 8) printf("eight\n");
    if (n == 9) printf("nine\n");
    if ((n > 9) && (n%2==0)) printf("even\n");
    if ((n > 9) && (n%2==1)) printf("odd\n");
}

int main7()
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	for (int i = a; i <= b; i++)
        printNumber(i);
    return 0;
}
