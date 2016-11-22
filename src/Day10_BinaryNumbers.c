/***
 * Carlos Miguens
 * 2016/11/22
 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    unsigned long num, max = 0, count = 0;

    scanf("%lu",&num);

    while (num > 0)
    {
    	if (num % 2 == 1)
    	{
    		count++;
    		if (count > max) max = count;
    	} else
    		count = 0;
    	num = num / 2;
    }
    printf("%lu\n", max);
    return 0;
}
