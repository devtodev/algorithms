/*
 * SherlockandValidString.c
 *
 *  Created on: 16 dic. 2016
 *      Author: charly
 */
#include "stdio.h"
#include "string.h"

int mainSherlockAndValidString()
{
	char S[100000], find;
	int diff = 0, i = 0, j = 0, count = 0, ocurrs[2][2];
	ocurrs[0][0] = 0;
	ocurrs[1][0] = 0;
	ocurrs[0][1] = 0;
	ocurrs[1][1] = 0;

	scanf("%s", S);

	while ((i < strlen(S)) && (diff <= 1))
	{
		count = 0;
		j = i;
		// count the index char
		if (S[i] != ' ')
		{
			find = S[i];
			while (j < strlen(S))
			{
				if (find == S[j])
				{
					count++;
					S[j] = ' ';
				}
				j++;
			}

			if (ocurrs[0][0] == 0)
			{
				ocurrs[0][0] = count;
			} else
			if ((ocurrs[1][0] == 0) && (count != ocurrs[0][0]))
			{
				ocurrs[1][0] = count;
			}

			if (ocurrs[0][0] == count)
			{
				ocurrs[0][1]++;
				if ((ocurrs[0][1] > 1) && (ocurrs[1][1] > 1))
					diff = 2;
			} else
			if (count == ocurrs[1][0])
			{
				ocurrs[1][1]++;
				if ((ocurrs[0][1] > 1) && (ocurrs[1][1] > 1))
					diff = 2;
			} else
				diff = 2;

		}
		i++;
	}

	if (diff == 2)
	{
		printf("NO");
	} else {
		printf("YES");
	}
	return 0;
}

