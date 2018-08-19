/*
 * main.c
 *
 *  Created on: Aug 19, 2018
 *      Author: karl
 *
 * https://www.hackerrank.com/challenges/equal-stacks/problem
 *
 */

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

/*
 * Complete the equalStacks function below.
 */

int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3) {
    int h1_sum[h1_count], h2_sum[h2_count], h3_sum[h3_count];
    int *a1, *a2, *a3, a1_size, a2_size, a3_size;
    int j1 = 0, j2 = 0;
    h1_sum[h1_count-1] = h1[h1_count-1];
    h2_sum[h2_count-1] = h2[h2_count-1];
    h3_sum[h3_count-1] = h3[h3_count-1];
    for (int i = 1; i < h1_count; i++)
        h1_sum[h1_count- 1 - i] = h1_sum[h1_count-i] + h1[h1_count - i - 1];
    for (int i = 1; i < h2_count; i++)
        h2_sum[h2_count- 1 - i] = h2_sum[h2_count-i] + h2[h2_count - i - 1];
    for (int i = 1; i < h3_count; i++)
        h3_sum[h3_count- 1 - i] = h3_sum[h3_count-i] + h3[h3_count - i - 1];

    if (h1_count < h2_count)
    {
        a1 = h1_sum;
        a1_size = h1_count;
        a2 = h2_sum;
        a2_size = h2_count;
    } else {
        a1 = h2_sum;
        a1_size = h2_count;
        a2 = h1_sum;
        a2_size = h1_count;
    }
    if (h3_count < a1_size)
    {
        a3 = a1;
        a3_size = a1_size;
        a1 = h3_sum;
        a1_size = h3_count;
    } else {
        a3 = h3_sum;
        a3_size = h3_count;
    }
    for (int i = 0; i < a1_size; i++)
    {
        j1 = 0;
        while ((a2[j1] != a1[i]) && (j1 < a2_size))
            j1++;
        if (a2[j1] == a1[i])
        {
            j2 = 0;
            while ((a3[j2] != a1[i]) && (j2 < a3_size))
                j2++;
            if (a1[i] == a3[j2])
                return a1[i];
        }
    }
    return 0;
}

int equalStacksOld(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3) {
    int h1_top = 0, h2_top = 0, h3_top = 0;
    int h1_sum = 0, h2_sum = 0, h3_sum = 0;
    for (int i = h1_top; i < h1_count; i++) h1_sum = h1_sum + h1[i];
    for (int i = h2_top; i < h2_count; i++) h2_sum = h2_sum + h2[i];
    for (int i = h3_top; i < h3_count; i++) h3_sum = h3_sum + h3[i];
    while ((h1_sum > 0) && (h2_sum > 0) && (h3_sum > 0))
    {
        if ((h1_sum == h2_sum) && (h2_sum == h3_sum))
            return h1_sum;

        if ((h1_sum >= h2_sum) && (h1_sum >= h3_sum))
        {
            h1_sum = h1_sum - h1[h1_top];
            h1_top++;
        } else
            if ((h2_sum > h1_sum) && (h2_sum > h3_sum))
            {
                h2_sum = h2_sum - h2[h2_top];
                h2_top++;
            } else
                if ((h3_sum > h1_sum) && (h3_sum > h2_sum))
                {
                    h3_sum = h3_sum - h3[h3_top];
                    h3_top++;
                }
    }

    return 0;
}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** n1N2N3 = split_string(readline());

    char* n1_endptr;
    char* n1_str = n1N2N3[0];
    int n1 = strtol(n1_str, &n1_endptr, 10);

    if (n1_endptr == n1_str || *n1_endptr != '\0') { exit(EXIT_FAILURE); }

    char* n2_endptr;
    char* n2_str = n1N2N3[1];
    int n2 = strtol(n2_str, &n2_endptr, 10);

    if (n2_endptr == n2_str || *n2_endptr != '\0') { exit(EXIT_FAILURE); }

    char* n3_endptr;
    char* n3_str = n1N2N3[2];
    int n3 = strtol(n3_str, &n3_endptr, 10);

    if (n3_endptr == n3_str || *n3_endptr != '\0') { exit(EXIT_FAILURE); }

    char** h1_temp = split_string(readline());

    int h1[n1];

    for (int h1_itr = 0; h1_itr < n1; h1_itr++) {
        char* h1_item_endptr;
        char* h1_item_str = h1_temp[h1_itr];
        int h1_item = strtol(h1_item_str, &h1_item_endptr, 10);

        if (h1_item_endptr == h1_item_str || *h1_item_endptr != '\0') { exit(EXIT_FAILURE); }

        h1[h1_itr] = h1_item;
    }

    char** h2_temp = split_string(readline());

    int h2[n2];

    for (int h2_itr = 0; h2_itr < n2; h2_itr++) {
        char* h2_item_endptr;
        char* h2_item_str = h2_temp[h2_itr];
        int h2_item = strtol(h2_item_str, &h2_item_endptr, 10);

//        if (h2_item_endptr == h2_item_str || *h2_item_endptr != '\0') { exit(EXIT_FAILURE); }

        h2[h2_itr] = h2_item;
    }

    char** h3_temp = split_string(readline());

    int h3[n3];

    for (int h3_itr = 0; h3_itr < n3; h3_itr++) {
        char* h3_item_endptr;
        char* h3_item_str = h3_temp[h3_itr];
        int h3_item = strtol(h3_item_str, &h3_item_endptr, 10);

  //      if (h3_item_endptr == h3_item_str || *h3_item_endptr != '\0') { exit(EXIT_FAILURE); }

        h3[h3_itr] = h3_item;
    }

    int result = equalStacks(n1, h1, n2, h2, n3, h3);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

