/*
 ============================================================================
 Name        : intFloat.c
 Author      : Carlos Miguens
 Description : Hacker Rank C test
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int intFloat(void) {
	int a, b;
	float c, d;
	scanf("%d %d", &a, &b);
	scanf("%f %f", &c, &d);
	printf("%d %d\n%.1f %.1f", a+b, a-b, c+d, c-d);
	return EXIT_SUCCESS;
}
