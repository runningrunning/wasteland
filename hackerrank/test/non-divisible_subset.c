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

// Complete the nonDivisibleSubset function below.
int nonDivisibleSubset(int k, int S_count, int* S) {
    int* ks = calloc(sizeof(int), k);
    for (int i = 0; i < S_count; i ++)
        ks[S[i] % k] ++;
    int max = ks[0] ? 1 : 0;
    for (int i = 1; i < k; i ++)
    {
        if (i < k - i)
            max += ks[i] < ks[k - i] ? ks[k - i] : ks[i];
        else if (i == k - i)
            max += 1;
        else
            break;
    }
    return max;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nk = split_string(readline());

    char* n_endptr;
    char* n_str = nk[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* k_endptr;
    char* k_str = nk[1];
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') { exit(EXIT_FAILURE); }

    char** S_temp = split_string(readline());

    int* S = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* S_item_endptr;
        char* S_item_str = *(S_temp + i);
        int S_item = strtol(S_item_str, &S_item_endptr, 10);

        bool fail = false;
        if (S_item_endptr == S_item_str || *S_item_endptr != '\0') {
            fail = true;
            exit(EXIT_FAILURE); }

        *(S + i) = S_item;

        if (fail)
            break;
    }

    int S_count = n;

    int result = nonDivisibleSubset(k, S_count, S);

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
