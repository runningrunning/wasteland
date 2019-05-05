// TODO BETTER SOLUTION !!!!????
// DO we really need to do sorting here?
// Just try the sort solution here.
// TRY TO SORT HERE !!!
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

char* readline();
char** split_string(char*);

// Complete the larrysArray function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//
char* larrysArray(int A_count, int* A) {
    int* test = calloc(sizeof(int), A_count);
    for (int i = 0; i < A_count; i ++)
    {
        if (A[i] > A_count || A[i] < 1 || test[A[i] - 1])
            return "NO";
        test[A[i] - 1] = 1;
    }
    for (int i = 0; i < A_count - 2; i ++)
    {
        int x = i + 1;
        for (int j = i; j < A_count; j ++)
        {
            if (A[j] == x)
            {
                int t = j - ((j - i) & ~1);
                for (int k = j; k > t; k --)
                    A[k] = A[k - 1];
                A[t] = x;
                if (t != i)
                {
                    x = A[i];
                    A[i] = A[i + 1];
                    A[i + 1] = A[i + 2];
                    A[i + 2] = x;
                }
                break;
            }
        }
    }
    return(A[A_count - 1] > A[A_count - 2]) ? "YES" : "NO";
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char* n_endptr;
        char* n_str = readline();
        int n = strtol(n_str, &n_endptr, 10);

        if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

        char** A_temp = split_string(readline());

        int* A = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            char* A_item_endptr;
            char* A_item_str = *(A_temp + i);
            int A_item = strtol(A_item_str, &A_item_endptr, 10);

            if (A_item_endptr == A_item_str || *A_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(A + i) = A_item;
        }

    /* // int A[] = {1, 2, 3, 4, 5, 6, 9, 8, 7, 10, 11, 13, 12}; */
    /* int A[] = {1, 6, 5, 2, 3, 4}; */
    /* int n = sizeof(A) / sizeof(A[0]); */
        printf("=== %d\n",n);
        int A_count = n;

        char* result = larrysArray(A_count, A);
        printf("%s.\n", result);

        fprintf(fptr, "%s\n", result);
    }

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
