/*
 * period.c
 *
 *  Created on: Apr 24, 2020
 *      Author: Carlos Miguens
 *
 *  NOTE: the function solutionOriginal(int n) is the original and function solution(int n) is the fixed
 *
 *  On the corrected solution it was solved:
 *
 *  1) Period needs to be equal or minus than the half of the binary length
 *  2) return -1 if N does not have a binary period
 *
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

// function to test the original decimal binary converter
void decimal_to_binary(int n, int len, char * pointer)
{
   int c, d, count;

   count = 0;

   if (pointer == NULL)
      return;

   for (c = 0 ; c < len ; c++)
   {
      d = n >> c;

      if (d & 1)
         *(pointer+count) = 1 + '0';
      else
         *(pointer+count) = 0 + '0';

      count++;
   }
   *(pointer+count) = '\0';
}

// from original function
void toBinary(int n, char *result)
{
    int d[30];
    int l = 0;
    while (n > 0) {
        d[l] = n % 2;
        n /= 2;
        l++;
    }

    for (int i = 0; i < l; i++)
    	result[i] = '0' + d[i];
    result[l] = '\0';
}

int solutionOriginal(int n) {
   int d[30];
	int l = 0;
	int p;
	while (n > 0) {
		d[l] = n % 2;
		n /= 2;
		l++;
	}
	for (p = 1; p < 1 + l; ++p) {
		int ok = 1;
		int i;
		for (i = 0; i < l - p; ++i) {
			if (d[i] != d[i + p]) {
				ok = 0;
				break;
			}
		}
		if (ok) {
			l = p;
		}
	}
	return l;
}

long long solution(int n) {
	   int d[30];
		int l = 0;
		int p;
		while (n > 0) {
			d[l] = n % 2;
			n /= 2;
			l++;
		}
		int len = l;  // ADD IT TO FIX IT!
		for (p = 1; p < 1 + l; ++p) {
			int ok = 1;
			int i;
			for (i = 0; i < l - p; ++i) {
				if (d[i] != d[i + p]) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				l = p;
			}
		}
		return (len/2 <= l)?-1:l;  // ADD IT TO FIX IT!
}

int main()
{
	char resultTest[30] = {0};
	char resultOriginal[30] = {0};

	for (int n = 0; n < 9999; n++)
	{
		// test binary
		toBinary(n, resultOriginal);
		int len = strlen(resultOriginal);
		decimal_to_binary(n, len, resultTest);
		if (strcmp(resultOriginal, resultTest))
		{
			printf("Error converting %d decimal", n);
		}
		// period calculation
		if (solution(n) != -1)
		{
			printf("{%d} period: %d length: %d %s \n", n, solution(n), len, resultOriginal);
		}
	}
	printf("finish");

  return 0;
}

