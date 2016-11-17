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

int Handshake(){
    int T;
    unsigned long rst[1000000];
    unsigned long i;
    int N[1000];

    rst[0] = 0;
    rst[1] = 0;
    for (i = 2; i < 1000000; i++)
    {
    	rst[i] = rst[i-1] + i - 1;
    }

    scanf("%d",&T);
        for(int a0 = 0; a0 < T; a0++){
            scanf("%d",&N[a0]);
        }

    for (i = 0; i < T; i++)
    {
    	printf("%lu\n", rst[N[i]]);
    }

    return 0;
}

