/*
 * main.c
 *
 *  Created on: Aug 16, 2018
 *      Author: karl
 *
 * to run in hacker rank you will need change
 * int valueOfFriendsship(int n, int friendships_rows, int friendships_columns, int (*friendships)[2] ) {
 * by:
 * int valueOfFriendsship(int n, int friendships_rows, int friendships_columns, int** friendships) {
 *
 *
 * -= Group concept =-
 * Each student can be part of only one group
 * a group is created when two students without group become friend
 * a student join to a group when one student without group become friend to a student with a group
 * two groups are merged when one student of group X became friend of a student of another group
 *
 */

#include "stdio.h"
#include "stdlib.h"

// https://www.hackerrank.com/challenges/value-of-friendship/problem
struct Student;

struct StudentList {
    struct Student *student;
    struct StudentList *next;
};

struct Group {
    int size;
    struct Group *next;
    struct StudentList *students;
    struct StudentList *lastIntudentsLists;
};

struct Student {
    int id;
    struct Group *group;
};


void joinToGroup(struct Student *s1, struct Group *group)
{
    group->size++;
    s1->group = group;
    if (group->students == NULL)
    {
        group->students = malloc(sizeof(struct StudentList));
        group->lastIntudentsLists = group->students;
    } else {
        group->lastIntudentsLists->next = malloc(sizeof(struct StudentList));
        group->lastIntudentsLists = group->lastIntudentsLists->next;
    }
    group->lastIntudentsLists->student = s1;
    group->lastIntudentsLists->next = NULL;

}

struct Group *createGroup(struct Student *s1, struct Student *s2, struct Group *group)
{
    group->next = malloc(sizeof(struct Group));
    group->next->next = NULL;
    group->next->size = 0;
    joinToGroup(s1, group->next);
    joinToGroup(s2, group->next);
    return group->next;
}

struct Group* freeGroup(struct Group *groups, struct Group *deprecateGroup)
{
	struct Group* init = groups;
	struct Group* temp;
	if (groups == deprecateGroup)
	{
		temp = groups->next;
		free(groups);
		return temp;
	}

	while (groups->next != NULL)
	{
		temp = groups;
		if (groups->next == deprecateGroup)
		{
			temp = groups->next;
			groups->next = groups->next->next;
			free(temp->next);
			return init;
		}
		groups = groups->next;
	}
	return init;
}

//int valueOfFriendsship(int n, int friendships_rows, int friendships_columns, int** friendships) {
int valueOfFriendsship(int n, int friendships_rows, int friendships_columns, int (*friendships)[2] ) {
    struct Student students[n];
    struct Group groups, *last = &groups;
    int total=0, parcial = 0, oldparcial = 0, s1, s2;
    // init vars
    groups.size = 0;
    groups.next = NULL;
    for (int i = 0; i<n; i++)
    {
        students[i].id = i;
        students[i].group = NULL;
    }
    // iterate friendships
    for (int i = 0; i < friendships_rows; i++)
    {
        s1 = friendships[i][0]-1; // -1 to convert into zero array index.
        s2 = friendships[i][1]-1;
        parcial = 0;

        if ((students[s1].group == NULL) && (students[s2].group == NULL)) // create a group
        {
            last = createGroup(&students[s1], &students[s2], last);
            parcial = 2;
        } else
            if ((students[s1].group == NULL) && (students[s2].group != NULL)) // join s1 to a group
            {
                joinToGroup(&students[s1], students[s2].group);
                parcial = students[s2].group->size * (students[s2].group->size - 1);
            } else
                if ((students[s1].group != NULL) && (students[s2].group == NULL)) // join s2 to a group
                {
                    joinToGroup(&students[s2], students[s1].group);
                    parcial = students[s2].group->size * (students[s2].group->size - 1);
                } else
                    if (students[s1].group != students[s2].group)
                    {
                        struct Group * deprecateGroup;
                        struct Group * theGroup;
                        if (students[s1].group->size > students[s2].group->size)
                        {
                            deprecateGroup = students[s2].group;
                            theGroup = students[s1].group;
                        } else {
                            deprecateGroup = students[s1].group;
                            theGroup = students[s2].group;
                        }
                        struct StudentList *listStudents = deprecateGroup->students;
                        deprecateGroup->size = 0;
                        while (listStudents != NULL)
                        {
                            joinToGroup(listStudents->student, theGroup);
                            listStudents = listStudents->next;
                        }
                        freeGroup(&groups, deprecateGroup);
                        parcial = students[s1].group->size * (students[s1].group->size - 1);
                    }

        if (parcial != 0)
        {
            struct Group * temp = &groups;
            parcial = 0;
            while (temp != NULL)
            {
                parcial = parcial + temp->size * (temp->size-1);
                temp = temp->next;
            }
            total = total + parcial;
            oldparcial = parcial;
        } else {
            total = total + oldparcial;
        }
    }
    return total;
}

int main() {
/*	int n = 10;
	int m = 6;
	int friendships[6][2] = {{1, 2}, {2, 3}, {4, 5}, {5, 6}, {1, 6}};
*/
	int n = 5;
	int m = 4;
	int friendships[4][2] = {{1, 2}, {3, 2}, {4, 2}, {4, 3}};


	int total = valueOfFriendsship(n, m, 2, friendships);

	printf("%d\n", total);

	return 0;
}



