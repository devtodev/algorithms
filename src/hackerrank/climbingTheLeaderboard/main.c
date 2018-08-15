/*
 * main.c
 *
 *  Created on: Aug 15, 2018
 *      Author: karl
 */

#include "stdio.h"
#include "stdlib.h"

// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

int findPosition(int scores_count, int *scores, int alice_score)
{
    int first,last,mid;

    first=0;
    last=scores_count-1;

    while(first<=last)
    {
        mid=(first+last)/2;

        if(alice_score==scores[mid]) {
            return mid;
        }
        else
            if(alice_score<scores[mid])
                first=mid+1;
            else
                last=mid-1;
    }

	return mid;
}

int *aliceResults;

int* climbingLeaderboard(int scores_count, int* scores, int alice_count, int* alice, int* result_count) {
	int ranking[scores_count];
	int rank = 1;
	aliceResults = malloc(sizeof(int) * alice_count);
	ranking[0] = rank;
	for (int i = 1; i<scores_count;i++)
	{
		if (scores[i] != scores[i-1])
			rank++;

		ranking[i] = rank;
	}

	for (int i = 0; i < alice_count; i++)
	{
		int competitor = findPosition(scores_count, scores, alice[i]);
		if (scores[competitor] <= alice[i])
			aliceResults[i] = ranking[competitor];
		else
			aliceResults[i] = ranking[competitor]+1;
	}

	*result_count = alice_count;

	return aliceResults;
}

int main() {
	int scores_count = 7;
	int scores[7] = {100, 100, 50, 40, 40, 20, 10};
	int alice_count = 4;
	int alice[4] = {5, 25, 50, 120};
	int aliceRank;
	climbingLeaderboard(scores_count, scores, alice_count, alice, &aliceRank);

	return 0;
}

