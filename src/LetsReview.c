/***
 * Carlos Miguens
 * 2016/11/18
 */

 #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int letsreview() {
	int N;
	char strings[10][10001], odd[10001], even[10001];
    unsigned long i,j, cursor = 0;

    scanf("%d",&N);
        for(i = 0; i < N; i++){
        	scanf(" %[^\n]s",strings[i]);
        }

	for (j = 0; j < N; j++)
	{
		i = 0;
		cursor = 0;
		while ((strings[j][i] >= '!') && (strings[j][i] < 127))
		{
			if ((i % 2 == 0) || (i == 0))
			{
				even[cursor] = strings[j][i];
				even[cursor+1] = '\0';
			} else {
				odd[cursor] = strings[j][i];
				cursor++;
				odd[cursor] = '\0';
			}
			i++;
		}

		printf("%s %s\n", even, odd);
	}
    return 0;

}

