// it's pretty simple, just need to take it carefully !!!
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the absolutePermutation function below.

// Please store the size of the integer array to be returned in result_count pointer. For example,
// int a[3] = {1, 2, 3};
//
// *result_count = 3;
//
// return a;
//

int* absolutePermutation(int n, int k, int* result_count) {
    int* r = NULL;

    if (k == 0)
    {
        *result_count = n;
        r = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i ++)
            r[i] = i + 1;
        return r;
    }

    if (n % (2 * k))
    {
        *result_count = 1;
        r = malloc(sizeof(int));
        r[0] = -1;
        return r;
    }

    *result_count = n;
    r = malloc(sizeof(int) * n);

    int t = -1;
    for (int i = 0; i < n; i ++)
    {
        if (!(i % k))
            t = - t;
        r[i] = i + 1 + t * k;
    }
    return r;
}


int main()
{
    FILE* fptr = fopen("output.txt", "w");

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    //if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char** nk = split_string(readline());

        char* n_endptr;
        char* n_str = nk[0];
        int n = strtol(n_str, &n_endptr, 10);

        //if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

        char* k_endptr;
        char* k_str = nk[1];
        int k = strtol(k_str, &k_endptr, 10);

        //if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

        printf("got %d %d.\n", n, k);
        int result_count;
        int* result = absolutePermutation(n, k, &result_count);

        for (int i = 0; i < result_count; i++) {
            fprintf(fptr, "%d", *(result + i));

            if (i != result_count - 1) {
                fprintf(fptr, " ");
            }
        }

        fprintf(fptr, "\n");
        printf("=== got %d %d. end\n", n, k);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);
    char* odata = data;

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            printf("break here %d \"%c\".\n", data_length, data[data_length - 1]);
            break;
        }

        size_t new_length = alloc_length << 1;
        printf("here new length\n", new_length);

        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    printf("data length is %d.\n", data_length);
    if (odata != data)
        printf("%p %p.\n", odata, data);
    data = realloc(data, data_length);
    printf("data length is %d.\n", data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    printf("split here.\n");
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
