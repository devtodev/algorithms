/*
 * SherlockAndPermutations.c
 *
 *  Created on: 19 de nov. de 2016
 *      Author: Carlos Miguens
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXLENGTH 2010
#define MAXTESTCASES 210

char permutations[MAXLENGTH][MAXLENGTH];
unsigned int rtas[MAXTESTCASES];
unsigned int npermutations = 0;

void addPermutation(char *permutation, int permutationLen)
{
	int i = 0;
	for (i = 0; i < npermutations; i++)
	{
		int equals = 0, cursor = 0;
		while ((equals == cursor) && (cursor < permutationLen))
		{
			if (permutations[i][cursor] == permutation[cursor]) equals++;
			cursor++;
		}
		if (equals == permutationLen)
			return; // found equals
	}
	// add
	for (i = 0; i < permutationLen; i++)
	{
		permutations[npermutations][i] = permutation[i];
	}
	npermutations++;
}

void Permutaciones(char * cad, int l, int n) {
   char c;
   int i, j;
   for(i = 0; i < n-l; i++) {
      if(n-l > 2)
    	  Permutaciones(cad, l+1, n);
      else
      {
    	  if (cad[0] == '1')
		  {
    		  addPermutation(cad, n);
		  }
      }
      /* Intercambio de posiciones */
      c = cad[l];
      cad[l] = cad[l+i+1];
      cad[l+i+1] = c;
      if(l+i == n-1) {
         for(j = l; j < n; j++) cad[j] = cad[j+1];
         cad[n] = 0;
      }
   }
}

int SAP2() {
    char txt[MAXLENGTH] = "\0";
    int zeros[MAXTESTCASES], ones[MAXTESTCASES];
    int N = 0, i, zero, one, cursor;
    scanf("%d",&N);
	for(i = 0; i < N; i++){
		scanf("%d %d", &zero, &one);
		zeros[i] = zero;
		ones[i] = one;
	}
	for (i = 0; i < N; i++)
	{
		for (cursor = 0; cursor < zeros[i]; cursor++)
			txt[cursor] = '0';
		for (cursor = zeros[i]; cursor < zeros[i]+ones[i]; cursor++)
			txt[cursor] = '1';
		txt[zeros[i]+ones[i]] = '\0';
		Permutaciones(txt,0, zeros[i]+ones[i]);
		printf("%d\n", npermutations);
		npermutations = 0;
	}
    return 0;
}
