/*
 * DrawingBook.c
 *
 *  Created on: 19 de dic. de 2016
 *      Author: karl
 */


#include "stdio.h"

int mainDrawingBook()
{
	int n, p, rst;
	scanf("%d %d", &n, &p);
	if ((n/2) >= p)
	{
		rst = p / 2;
	}
	else
	{
		rst = (n - p) / 2;
		if (rst == 0)
			rst = ((n != p) && (n % 2 == 0))?1:0;
	}
	printf("%d", rst);
	return 0;
}

