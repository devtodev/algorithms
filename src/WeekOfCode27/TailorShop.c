
/*
 * TailorShop.java
 *
 *  Created on: 20 de dic. de 2016
 *      Author: karl
 */

#include "stdio.h"

int tailorMain() {
	int N, P;
	int rst[1000000] = {0};
	int total = 0, minCostCluster, nButton;
	scanf("%d %d", &N, &P);
	for (int i = 0 ; i < N; i++)
	{
		scanf("%d", &minCostCluster);
		nButton = (minCostCluster % P == 0)?minCostCluster / P: (minCostCluster / P) +1;

		while (rst[nButton] != 0)
		{
			nButton++;
		}
		total = total + nButton;
		rst[nButton] = 1;
	}
	printf("%d", total);
}
