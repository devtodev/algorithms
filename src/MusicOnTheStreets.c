/*
 * MusicOnTheStreets.c
 *
 *  Created on: 1 dic. 2016
 *      Author: charly
 */


/*
 * Twins_Primes.c
 *
 *  Created on: 30 nov. 2016
 *      Author: Carlos Miguens
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int musinOnTheStreetsMain() {
	long long N, a0, aN, h1, h2, m, rst;
	scanf("%lld", &N);
	for (int i = 0; i < N; i++)
	{
		long temp = 0;
		scanf("%lld", &temp);
		if (i == 0)
			a0 = temp;
		if (i == N-1)
			aN = temp;
	}

	scanf("%lld %lld %lld", &m, &h1, &h2);

	rst = a0 - h1;

	while (rst+m >= aN+h2)
		rst--;

	printf("%lld", rst);
    return 0;
}
