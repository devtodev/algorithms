/*
 * BestDivisor.c
 *
 *  Created on: 30 nov. 2016
 *      Author: charly
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* itoa(long val, int base){

	static char buf[32] = {0};

	int i = 30;

	for(; val && i ; --i, val /= base)

		buf[i] = "0123456789abcdef"[val % base];

	return &buf[i+1];

}

int bestDivisor() {
     long n, rst = -1;
     long max=0;
     scanf("%ld", &n);
     char *temp;

     for (int i = 1; i <= n; i++)
     {
         if (n%i==0)
         {
             //String temp = new Integer(i).toString();
        	 temp = itoa(i, 10);
             int buf =0;
             for(int j = 0; j < strlen(temp); j++)
                 buf = buf + (temp[j]-'0');
             if (buf>=rst)
             {
                 rst = buf;
                 max=i;
             }
         }
     }
     printf("%ld", max);

    return 0;
}
