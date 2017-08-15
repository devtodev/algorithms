/*
 * binaryGap.c
 *
 *  Created on: Aug 14, 2017
 *      Author: Carlos Miguens
 *
 *      Description:
			A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

			For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps.

			Write a function:

			int solution(int N);
			that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

			For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5.

			Assume that:

			N is an integer within the range [1..2,147,483,647].
			Complexity:

			expected worst-case time complexity is O(log(N));
			expected worst-case space complexity is O(1).
 *
 */

#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int decimal, char *binary)
{
	int i = 0;
	char temp[64];
	while (decimal / 2 >= 1)
	{
		temp[i] = '0' + decimal % 2;
		decimal = decimal / 2;
		i++;
	}
	temp[i] = '0' + decimal;
	for (int j = i; j >= 0; j--)
	{
		binary[i - j] = temp[j];
	}
	binary[i+1] = '\0';
}

int solution(int N)
{
	int i = 0;
	int count = 0;
	int max = 0;
    char binary[65];
	decimalToBinary(N, binary);
	while (binary[i] != '\0')
	{
		if (binary[i] == '1')
		{
			if (count > max) max = count;
			count = 0;
		} else {
			count++;
		}
		i++;
	}
	return max;
}

int mainBinaryGap(void)
{
	int n = 0, reply = 0;
	scanf("%d", &n);
	reply = solution(n);
	printf("%d", reply);
}
