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

#define MAXLENGTH 300

char *permutations[MAXLENGTH];
unsigned int npermutations = 0;

void Permutaciones(char * cad, int l) {
   char c;
   int i, j;
   int n = strlen(cad);
   for(i = 0; i < n-l; i++) {
      if(n-l > 2)
    	  Permutaciones(cad, l+1);
      else
    	  printf(cad);
      /* Intercambio de posiciones */
      c = cad[l];
      cad[l] = cad[l+i+1];
      cad[l+i+1] = c;
      printf("\n");
      if(l+i == n-1) {
         for(j = l; j < n; j++) cad[j] = cad[j+1];
         cad[n] = 0;
      }
   }
}

int main() {
    char txt[MAXLENGTH] = "12345\0";
    Permutaciones(txt,0);
    return 0;
}
