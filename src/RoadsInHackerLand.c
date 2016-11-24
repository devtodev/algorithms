/*
 * RoadsInHackerLand.c
 *
 *  Created on: 23 de nov. de 2016
 *      Author: karl
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>

typedef struct sRoad tRoad;
typedef struct sCity tCity;
typedef struct sCalculated tCalculated;

struct sCity{
	unsigned long id;
	int wasVisited;
	tRoad *roads;
	tCity *next;
};

struct sRoad{
	 long length;
	 tCity *destiny;
	 tRoad *next, *previous;
};

struct sCalculated{
	 long from, to;
	 tCalculated *next;
};

// 	N cities   M roads
long N, M, minPath = LONG_MAX;
// read inputs
tCity *initialCity, *cursor;
tCalculated *needCalculated;
tCity *getCity(unsigned long id)
{
	tCity *temp = initialCity;
	while (temp->id != id)
		temp = temp->next;
	return (temp != NULL)?temp:NULL;
}

void addCity(int id)
{
	tCity *temp = malloc(sizeof(struct sCity));
	temp->id = id;
	temp->next = NULL;
	temp->roads = NULL;
	temp->wasVisited = 0;
	if (initialCity == NULL) {
		initialCity = temp;
		cursor = initialCity;
	} else {
		cursor->next = temp;
		cursor = cursor->next;
	}
}


void insertRoad(tCity * cityFrom, tCity *cityDestiny, int length)
{
	tRoad *cursorRoad = cityFrom->roads;
	tRoad *newRoad = malloc(sizeof(struct sRoad));
	newRoad->length = length;
	newRoad->destiny = cityDestiny;
	newRoad->next = NULL;
	newRoad->previous = NULL;

	if (cursorRoad == NULL)
	{
		cityFrom->roads = newRoad;
		return;
	}

	while ((cursorRoad->next != NULL) && (cursorRoad->length < length))
		cursorRoad = cursorRoad->next;

	if (cursorRoad->length > length)
	{
		if (cursorRoad->previous != NULL) {
			// insert in middle
			newRoad->previous = cursorRoad->previous;
			cursorRoad->previous->next = newRoad;
		} else {
			// first
			cityFrom->roads = newRoad;
		}
		newRoad->next = cursorRoad;
		cursorRoad->previous = newRoad;

	} else {
		// lastone
		cursorRoad->next = newRoad;
		newRoad->previous = cursorRoad;
	}
}

void addRoad(tCity * cityFrom, tCity *cityDestiny, int length)
{
	long size = 1;
	for(int i = 1; i <= length; i++)
		size = size * 2;
	cursor = initialCity;
	insertRoad(cityFrom, cityDestiny, size); // bidirectional
	insertRoad(cityDestiny, cityFrom, size);
}

long tempLength;

long visitCity(tCity * cityFrom, tCity *cityDestiny, long pathsize)
{
	// iterate roads of the cityFrom
	tRoad *road = cityFrom->roads;
	while (road != NULL)
	{
		if (road->destiny == cityDestiny)
		{
			// put in a list
			pathsize = pathsize + road->length;
			if (minPath > pathsize)
				minPath = pathsize;
			return road->length;
		}
		if ((pathsize + road->length < minPath) && (road->destiny->wasVisited == 0))
		{
			pathsize = pathsize + road->length;
			road->destiny->wasVisited = 1;
			tempLength = visitCity(road->destiny, cityDestiny, pathsize);
			road->destiny->wasVisited = 0;
			pathsize = pathsize - road->length;
		}
		road = road->next;
	}

	return 0;
}

int needVisit(int x, int y)
{
	tCalculated *cursor = needCalculated;
	if (x == y) return 0;
	while ((cursor != NULL) && (cursor->next != NULL))
	{
		if (((cursor->from == x) && (cursor->to == y)) ||
			((cursor->from == y) && (cursor->to == x)) )
		{
			return 0;
		}
		cursor = cursor->next;
	}
	if (cursor == NULL)
	{
		needCalculated = malloc(sizeof(struct sCalculated));
		cursor = needCalculated;
	} else {
		if (((cursor->from == x) && (cursor->to == y)) ||
			((cursor->from == y) && (cursor->to == x)) )
		{
			return 0;
		}
		cursor->next = malloc(sizeof(struct sCalculated));
		cursor = cursor->next;
	}
	cursor->from = x;
	cursor->to = y;
	cursor->next = NULL;

	return 1;
}

int main() {
	int N = 5; // N cities  M roads
	needCalculated = NULL;
	long sum = 0;

	for (int id = 1; id <= N; id++)
		addCity(id);

	addRoad(getCity(1), getCity(3), 5);
	addRoad(getCity(4), getCity(5), 0);
	addRoad(getCity(2), getCity(1), 3);
	addRoad(getCity(3), getCity(2), 1);
	addRoad(getCity(4), getCity(3), 4);
	addRoad(getCity(4), getCity(2), 2);

	for (int y = 1; y <= N; y++ )
		for (int x = 1; x <= N; x++ )
		{
			if (needVisit(x, y) == 1)
			{
				minPath = LONG_MAX;
				visitCity(getCity(y), getCity(x), 0);
				sum = sum + minPath;
			}
		}
	printf("%ld ", sum);
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
