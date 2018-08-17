/*
 * main.c
 *
 *  Created on: Aug 16, 2018
 *      Author: karl
 * 
 * first and unperformance version
 * 
 * to run in hacker rank you will need change 
 * int valueOfFriendsship(int n, int friendships_rows, int friendships_columns, int (*friendships)[2] ) {
 * by:
 * int valueOfFriendsship(int n, int friendships_rows, int friendships_columns, int** friendships) { 
 */

#include "stdio.h"
#include "stdlib.h"

// https://www.hackerrank.com/challenges/value-of-friendship/problem


struct Friend {
    int id;
    struct Friend *next;
};

struct Student {
    int id;
    struct Friend *first_friend, *last_friend;
};

/*
 * Complete the valueOfFriendsship function below.
 */

void makeFriends(int s1, int s2, struct Student *student)
{
    if (student[s1].first_friend == NULL)
    {
        student[s1].first_friend = malloc(sizeof(struct Friend));
        student[s1].last_friend = student[s1].first_friend;
    } else {
        student[s1].last_friend->next = malloc(sizeof(struct Friend));
        student[s1].last_friend = student[s1].last_friend->next;
    }
    student[s1].last_friend->id = s2;
    student[s1].last_friend->next = NULL;
}

int getFriends(int id, struct Student *students, struct Friend *friendsCounted, int totalFriendsCounted)
{
    struct Friend *newFriend = students[id].first_friend;
    while (newFriend != NULL)
    {
        struct Friend *cursor = friendsCounted;
        while ((cursor != NULL) && (cursor->next != NULL) && (newFriend->id != cursor->id))
            cursor = cursor->next;

        if  (((friendsCounted == NULL) || (newFriend->id != cursor->id)) && (id != newFriend->id))
        {
            if (friendsCounted == NULL)
            {
                friendsCounted = malloc(sizeof(struct Friend));
                cursor = friendsCounted;
            } else {
                cursor->next = malloc(sizeof(struct Friend));
                cursor = cursor->next;
            }
            cursor->id = newFriend->id;
            cursor->next = NULL;
            totalFriendsCounted = getFriends(newFriend->id, students, friendsCounted, totalFriendsCounted + 1);
        }
        newFriend = newFriend->next;
    }
    return totalFriendsCounted;
}

int valueOfFriendsship(int n, int friendships_rows, int friendships_columns, int (*friendships)[2] ) {

    struct Student students[n];
    int total=0, s1, s2, personalFriends;
    for (int i = 0; i<n; i++)
    {
        students[i].id = n;
        students[i].first_friend = NULL;
        students[i].last_friend = NULL;
    }
    for (int i = 0; i < friendships_rows; i++)
    {
        s1 = friendships[i][0]-1; // -1 to convert into zero array index.
        s2 = friendships[i][1]-1;
        makeFriends(s1, s2, students);
        makeFriends(s2, s1, students);
        for (int student = 0; student < n; student++)
        {
            personalFriends = getFriends(student, students, NULL, 0);
            total = total + personalFriends;
        }

    }
    return total;
}


int main() {
	int n = 5;
	int m = 4;
	int friendships[4][2] = {{1, 2}, {3, 2}, {4, 2}, {4, 3}};

	int total = valueOfFriendsship(n, m, 2, friendships);

	printf("%d\n", total);

	return 0;
}


