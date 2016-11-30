/*
 * ArmyGameSupply.c
 *
 *  Created on: 28 de nov. de 2016
 *      Author: karl
 */


#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int armyMain(){
    int n;
    int m;
    scanf("%d %d",&n,&m);
    int total = (n / 2) * (m / 2);
    total = total + (n % 2) * (m/2);
    total = total + (n / 2) * (m%2);
    total = total + (n % 2) * (m%2);
    printf("%d", total);
    return 0;
}
