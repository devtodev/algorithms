/***
 * Carlos Miguens
 * 2016/11/16
 */
 
 #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int Restaurant() {
	int N;
    unsigned long rst;
    unsigned long i, j;
    int xy[1000][2];

    scanf("%d",&N);
        for(int a0 = 0; a0 < N; a0++){
            scanf("%d",&xy[a0][0]);
            scanf("%d",&xy[a0][1]);
        }

    for (i = 0; i < N; i++)
    {
    	j = (xy[i][0] < xy[i][1])?xy[i][0]:xy[i][1];
    	rst = 0;

    	while ((j > 0) && (rst == 0))
    	{
    		if ((xy[i][0] % j == 0) && (xy[i][1] % j == 0))
    		{
    			rst = (xy[i][0]*xy[i][1]) / (j*j);
    		}
    		j--;
    	}
    	printf("%lu\n", rst);
    }
    return 0;

}
 
