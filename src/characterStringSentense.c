/*
 ============================================================================
 Name        : characterStringSentense.c
 Author      : Carlos Miguens
 Description : Hacker Rank C test
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int characterStringSentense(void) {
	char s[10], sens[60], c;
	scanf("%c %s %[^\n]%*c", &c, s, sens);
	printf("%c\n%s\n%s", c, s, sens);
	return EXIT_SUCCESS;
}
