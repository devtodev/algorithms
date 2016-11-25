/*
 * CountingSort2.c
 *
 *  Created on: 25 nov. 2016
 *      Author: charly
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

 void BubbleSort(int a[], int array_size)
 {
	 int i, j, temp;
	 for (i = 0; i < (array_size - 1); ++i)
	 {
		  for (j = 0; j < array_size - 1 - i; ++j )
		  {
			   if (a[j] > a[j+1])
			   {
					temp = a[j+1];
					a[j+1] = a[j];
					a[j] = temp;
			   }
		  }
	 }
 }

 int partition( int a[], int l, int r) {
    int pivot, i, j, t;
    pivot = a[l];
    i = l; j = r+1;

    while( 1)
    {
    	do ++i; while( a[i] <= pivot && i <= r );
    	do --j; while( a[j] > pivot );
    	if( i >= j ) break;
    	t = a[i]; a[i] = a[j]; a[j] = t;
    }
    t = a[l]; a[l] = a[j]; a[j] = t;
    return j;
 }

 void quickSort( int a[], int l, int r)
 {
    int j;

    if( l < r )
    {
        j = partition( a, l, r);
        quickSort( a, l, j-1);
        quickSort( a, j+1, r);
    }

 }

int CountingSort2main() {
	int N;
	int arr[1000000];
	// FILE * fp;
	// fp = fopen ("/home/charly/workspace.kds/Hackerrank/src/input.txt", "r");
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	//BubbleSort(arr, N);
	quickSort(arr, 0, N);
	for (int i = 1; i <= N; i++)
		printf("%d ", arr[i]);
    return 0;
}
