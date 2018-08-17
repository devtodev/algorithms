/*
 * main.c
 *
 *  Created on: Aug 16, 2018
 *      Author: karl
 * 
 * second, I have an idea I will make a different aproach
 * 
 * to run in hacker rank you will need change 
 * int valueOfFriendsship(int n, int friendships_rows, int friendships_columns, int (*friendships)[2] ) {
 * by:
 * int valueOfFriendsship(int n, int friendships_rows, int friendships_columns, int** friendships) { 
 */

#include "stdio.h"
#include "stdlib.h"

// https://www.hackerrank.com/challenges/value-of-friendship/problem

/*
 * Group concept
 * Each student can be part of only one group
 * a group is created when two students without group become friend
 * a student join to a group when one student without group become friend to a student with a group
 * two groups are merged when one student of group X became friend of a student of another group
 * 
 */

struct Friend {
	int id;
	struct Friend *next;
};

struct Student {
	int id, cantFriends;
	struct Friend *first_friend, *last_friend;
};

/*
 * Complete the valueOfFriendsship function below.
 */

void makeFriends(int s1, int s2, struct Student *student)
{
	student[s1].cantFriends++;
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

int makeFriendIfNew(int s1, int s2, struct Student *student)
{
	if (s1 != s2) {
		struct Friend *myFriends = student[s1].first_friend;
		if (myFriends == NULL)
		{
			makeFriends(s1, s2, student);
			return 0;
		}
		while (myFriends->next != NULL)
		{
			if (myFriends->id == s2)
				return 1;
			myFriends = myFriends->next;
		}
		// if I am here I can make two new friends
		if (myFriends->id != s2)
			makeFriends(s1, s2, student);
	}
	return 0;
}

void findNewFriends(int id, int currentId, struct Student *students)
{
	struct Friend *friends = students[id].first_friend;
	struct Friend *newFriend = students[currentId].first_friend;

	while (newFriend != NULL)
	{
		struct Friend *myFriends = friends;
		while ((newFriend->id != id) && (myFriends->next != NULL) && (myFriends->id != newFriend->id))
		{
			myFriends = myFriends->next;
		}
		if ((newFriend->id != id) && (myFriends->id != newFriend->id))
		{
			makeFriends(id, newFriend->id, students);
			makeFriends(newFriend->id, id, students);
			findNewFriends(id, newFriend->id, students);
			// call findNewFriends with my new friend
		}
		newFriend = newFriend->next;
	}
}

int valueOfFriendsship(int n, int friendships_rows, int friendships_columns, int (*friendships)[2] ) {
	struct Student students[n];
	int total=0, s1, s2, sw;
	for (int i = 0; i<n; i++)
	{
		students[i].id = i;
		students[i].cantFriends = 0;
		students[i].first_friend = NULL;
		students[i].last_friend = NULL;
	}
	for (int i = 0; i < friendships_rows; i++)
	{
		s1 = friendships[i][0]-1; // -1 to convert into zero array index.
		s2 = friendships[i][1]-1;
		sw = makeFriendIfNew(s1, s2, students);
		if (sw == 0)
		{
			sw = makeFriendIfNew(s2, s1, students);
			findNewFriends(s1, s2, students);
			findNewFriends(s2, s1, students);
		}
		for (int student = 0; student < n; student++)
		{
			total = total + students[student].cantFriends;
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



