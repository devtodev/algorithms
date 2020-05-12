/*
 * qsortExample.c
 *
 *  Created on: Apr 21, 2020
 *      Author: Carlos Miguens
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

float getArea(triangle t)
{
	float area = 0;
	float p = (float) (t.a + t.b + t.c) / 2.0;
	area = sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
	return area;
}

int compare(const void* t1, const void* t2)
{
    float arg1 = getArea(*(const triangle*)t1);
    float arg2 = getArea(*(const triangle*)t2);

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}


void sort_by_area(triangle* tr, int n) {
	qsort(tr, n, sizeof(triangle), &compare);
}

int main3()
{
	int n = 80;
	triangle tr[] = {
			{10, 61, 65},
			{49, 54, 14},
			{66, 66, 19},
			{43, 32, 62},
			{39, 35, 19},
			{43, 58, 67},
			{65, 49, 24},
			{48, 6, 48},
			{44, 17, 54},
			{63, 32, 67},
			{41, 62, 56},
			{6 ,19, 21},
			{62, 45, 35},
			{62, 4, 63},
			{52, 37, 62},
			{32, 69, 41},
			{42, 38, 57},
			{17, 15, 13},
			{57, 38, 56},
			{48, 28, 33},
			{31, 40, 63},
			{46, 33, 60},
			{39, 38, 46},
			{9 ,35 ,32},
			{67, 28, 53},
			{31, 45, 22},
			{23, 12, 12},
			{69, 50, 61},
			{6 ,52 ,56},
			{56, 52, 59},
			{60, 38, 35},
			{45, 41, 37},
			{46, 47, 20},
			{22, 35, 49},
			{35, 53, 65},
			{49, 9 ,49},
			{62, 6 ,57},
			{55, 55, 43},
			{64, 33, 42},
			{21, 50, 44},
			{56, 43, 44},
			{15, 23, 33},
			{2 ,25 ,26},
			{11, 46, 54},
			{68, 26, 68},
			{54, 46, 53},
			{36, 51, 51},
			{21, 11, 14},
			{53, 19, 38},
			{2 ,24 ,24},
			{3 ,29 ,30},
			{52, 26, 64},
			{54, 31, 42},
			{30, 30, 42},
			{41, 45, 64},
			{21, 18, 24},
			{44, 53, 36},
			{54, 49, 28},
			{63, 35, 35},
			{51, 59, 58},
			{25, 63, 57},
			{40, 27, 51},
			{57, 15, 57},
			{65, 47, 43},
			{36, 36, 53},
			{57, 46, 26},
			{35, 69, 43},
			{56, 19, 49},
			{59, 59, 20},
			{24, 66, 64},
			{58, 24, 54},
			{36, 18, 41},
			{46, 54, 15},
			{55, 66, 68},
			{31, 59, 39},
			{23, 10, 32},
			{51, 38, 50},
			{46, 35, 41},
			{30, 38, 46},
			{15, 66, 61}
	};
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
