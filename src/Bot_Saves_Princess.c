/*
 * Bot_Saves_Princess.c
 *
 *  Created on: 22 nov. 2016
 *      Author: Carlos Miguens
 */


#include <stdio.h>
#include <string.h>
#include <math.h>

void displayPathtoPrincess(int n, char grid[101][101]){
    char *mov1, *mov2;
    //  LEFT or RIGHT or UP or DOWN.
    if (grid[0][0] == 'p')
    {
    	mov1 = "LEFT\0";
    	mov2 = "UP\0";
    } else
    if (grid[n-1][0] == 'p')
	{
    	mov1 = "LEFT\0";
		mov2 = "DOWN\0";
	} else
    if (grid[0][n-1] == 'p')
	{
    	mov1 = "RIGHT\0";
		mov2 = "UP\0";
	} else
	{
		mov1 = "RIGHT\0";
		mov2 = "DOWN\0";
	}
    for (int i = 1; i < n-1; i++)
    {
    	printf("%s\n%s\n", mov1, mov2);
    }
}

int botSavePrincess(void) {

    int m;
    scanf("%d", &m);
    char grid[101][101]={};
    char line[101];

    for(int i=0; i<m; i++) {
        scanf("%s", line);
        strcpy(grid[i], line);
    }
    displayPathtoPrincess(m,grid);
    return 0;
}
