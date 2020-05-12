/*
 * postTrasaction.c
 *
 *  Created on: Apr 22, 2020
 *      Author: Carlos Miguens
 */


#include <stdio.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;


void print_all_packages(town t) {
	printf("%s:\n", t.name);
	for (int i = 0; i < t.offices_count; i++)
	{
		printf("\t%d:\n", i);
		for(int p = 0; p < t.offices[i].packages_count; p++)
		{
			printf("\t\t%s\n", t.offices[i].packages[p].id);
		}
	}
}

void removePackage(package *packs, int toRemove, int length)
{
	for (int i = toRemove; i < length -1; i++)
	{
		packs[i] = packs[i+1];
	}
}

void addPackage(package *packs, int currectPacks, package pack)
{
	packs[currectPacks].id = pack.id;
	packs[currectPacks].weight = pack.weight;
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
	post_office *ofSource = &source->offices[source_office_index];
	post_office *ofTarget = &target->offices[target_office_index];
	int count = 0;
	for (int i = 0; i < ofSource->packages_count; i++)
	{
		package pack = ofSource->packages[i];
		if ((pack.weight >= ofTarget->min_weight) &&
			(pack.weight <= ofTarget->max_weight))
		{
			count++;
		}
	}
	ofTarget->packages = (package*) realloc (ofTarget->packages, (ofTarget->packages_count + count) * sizeof(package));

	for (int i = 0; i < ofSource->packages_count; i++)
	{
		package pack = ofSource->packages[i];
		if ((pack.weight >= ofTarget->min_weight) &&
			(pack.weight <= ofTarget->max_weight))
		{
			addPackage(ofTarget->packages, ofTarget->packages_count, pack);
			ofTarget->packages_count++;
			removePackage(ofSource->packages, i, ofSource->packages_count);
			ofSource->packages_count--;
			i--;
		}
	}

}

int countPackagesInTown(town t)
{
	int packs = 0;
	for (int i = 0; i < t.offices_count; i++)
	{
		packs += t.offices[i].packages_count;
	}
	return packs;
}

town town_with_most_packages(town* towns, int towns_count) {
	town townMaxPackages = towns[0];
	int maxPackages = countPackagesInTown(townMaxPackages);
	for (int i = 1; i < towns_count; i++)
	{
		int counter = countPackagesInTown(towns[i]);
		if (counter > maxPackages)
		{
			maxPackages = counter;
			townMaxPackages = towns[i];
		}
	}
	return townMaxPackages;
}

town* find_town(town* towns, int towns_count, char* name) {
	for (int i = 0; i < towns_count; i++)
	{
		if (strcmp(towns[i].name, name) == 0)
			return &towns[i];
	}
	return NULL;
}

int main2()
{
	int towns_count;
	FILE* file = fopen("src/postTransaction.in","r");
	if (file==NULL)
	{
		printf("no such file.");
		return 0;
	}
	fscanf(file, "%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		fscanf(file, "%s", towns[i].name);
		fscanf(file, "%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			fscanf(file, "%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				fscanf(file, "%s", towns[i].offices[j].packages[k].id);
				fscanf(file, "%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	fscanf(file, "%d", &queries);
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		fscanf(file, "%d", &type);
		switch (type) {
		case 1:
			fscanf(file, "%s", town_name);
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			fscanf(file, "%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			fscanf(file, "%d", &source_index);
			fscanf(file, "%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			fscanf(file, "%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}
