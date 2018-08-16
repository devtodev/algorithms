/*
 * main.c
 *
 *  Created on: Aug 16, 2018
 *      Author: karl
 */

#include "stdio.h"
#include "stdlib.h"

// https://www.hackerrank.com/challenges/magic-square-forming/problem

/*
 * This code works well, but the hackerrank problem you will need change the function declaration
 *
 * int formingMagicSquare(int s_rows, int s_columns, int (* s)[3])
 *
 * to
 *
 * int formingMagicSquare(int s_rows, int s_columns, int ** s);
 *
 */

int magicSqueares[8][3][3] ={{{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
							 {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
							 {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
							 {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
							 {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
							 {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
							 {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
							 {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}};

int formingMagicSquare(int s_rows, int s_columns, int (* s)[3]) {
	int diff;
	int min = -1;
	for (int i = 0; i < 8; i++)
	{
		diff = 0;
		for (int col = 0; col < 3; col++)
		{
			diff =  diff + abs(s[col][0] - magicSqueares[i][col][0]);
			diff =  diff + abs(s[col][1] - magicSqueares[i][col][1]);
			diff =  diff + abs(s[col][2] - magicSqueares[i][col][2]);
		}
		if (diff == 0)
			return 0;
		min = ((min == -1) || (diff < min))?diff:min;
	}
	return min;
}

int main() {
	int square[3][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 5}};
	int diff = formingMagicSquare(3, 3, square);
	printf("%d\n", diff);

	return 0;
}



