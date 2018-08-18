/*
 * main.c
 *
 *  Created on: Aug 18, 2018
 *      Author: karl
 *
 * https://www.hackerrank.com/challenges/how-many-substrings/problem
 * 
 * Runs well 3 of 11, in the others test cases got time out * 
 * 
 */

#include "stdio.h"
#include "stdlib.h"
#include <string.h>

struct SubString {
	char data[5000];
	struct SubString *next;
};

int addSubString(char *substring, struct SubString *list)
{
	while (list->next!=NULL)
	{
		list = list->next;
		if (strcmp(substring, list->data) == 0)
			return 0;
	}
	list->next = malloc(sizeof(struct SubString));
	strcpy(list->next->data, substring);
	list->next->next = NULL;
	return 1;
}

void freeList(struct SubString *list)
{
	struct SubString *next;
	next = list->next;
	list->next = NULL;
	list = next;
	while (list != NULL)
	{
		next = list->next;
		free(list);
		list = next;
	}
}

int *reply;
int* countSubstrings(char* s, int queries_rows, int queries_columns, int** queries, int* result_count) {
//int* countSubstrings(char* s, int queries_rows, int queries_columns, int (* queries)[2], int* result_count) {
	reply = malloc(sizeof(int)* queries_rows);
	struct SubString list;
	*result_count = queries_rows;
	strcpy(list.data, "");
	list.next = NULL;

	for (int i = 0; i < queries_rows; i++)
	{
		int ssStartAt = queries[i][0];
		int ssEndAt = queries[i][1];
		int len = ssEndAt-ssStartAt + 1;
		char *substring = malloc(sizeof(char)* len);
		int partialResult = 1;
		memcpy( substring, s+ssStartAt, len);

		for (int size = 1; size < len; size++)
		{
			char *partial = malloc(sizeof(char)*size+1);
			for (int cursor = 0; cursor <= len - size; cursor++)
			{
				memcpy( partial, substring + cursor, size);
				partial[size] = '\0';
				//printf("%s %s", substring, partial);
				if (addSubString(partial, &list) == 1)
					partialResult++;
				// iterate the list of added substrings and strcmp()
			}
			free(partial);
			freeList(&list);
		}
		reply[i] = partialResult;
		partialResult = 0;
		free(substring);
	}
	return reply;
}


int main(){
	char *s = "qqqqqqqqqqzrzrrzrzrrzrrzrzrrzrzrrzttttttttttttttttttttttttttttttttttttttttttttttttttttttqncpqzcxpbwa\0";
	int queries[100][2] = {{61, 97}, {15, 50}, {68, 89}, {74, 87}, {70, 80}, {53, 97},
						 {49, 73},{86, 92},{85, 88},{10, 76},{70, 89},{41, 78},{7, 36},{31, 38},{19, 99},{91, 91},{86, 98},{21, 66},{91, 91},{49, 90},{44, 51},{12, 66},{86, 91},{42, 56},{6, 46},{52, 71},{10, 72},{86, 91},{74, 78},{17, 39},{38, 92},{6, 99},{90, 91},{88, 91},{57, 66},{19, 49},{3, 83},{42, 75},{69, 70},{95, 96},{77, 98},{76, 87},{59, 80},{47, 90},{68, 90},{4, 51},{89, 92},{69, 79},{0, 44},{49, 94},{27, 43},{40, 47},{42, 75},{68, 69},{59, 89},{62, 79},{34, 37},{52, 93},{31, 60},{19, 35},{14, 46},{93, 96},{62, 82},{74, 84},{44, 56},{96, 96},{80, 92},{41, 72},{80, 99},{17, 39},{0, 85},{68, 99},{35, 75},{89, 99},{57, 78},{99, 99},{64, 93},{29, 55},{93, 93},{32, 44},{55, 58},{98, 98},{81, 90},{19, 87},{14, 37},{67, 96},{2, 32},{25, 47},{51, 95},{46, 54},{69, 79},{64, 95},{61, 75},{0, 22},{78, 94},{6, 44},{0, 17},{0, 56},{46, 58},{35, 63}};

	int reply_count, *result;
	result = countSubstrings(s, 100, 2, queries, &reply_count);
	for (int i = 0; i < reply_count; i++)
		printf("%d\n", result[i]);
}

