// stupid overflow !!!!!!
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

// Complete the beautifulTriplets function below.
int beautifulTriplets(int d, int arr_count, int* arr) {
    int min = INT_MAX;
    int max = INT_MIN;

    int* vs = calloc(sizeof(int), 20001);
    for (int i = 0; i < arr_count; i ++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
        vs[arr[i]] ++;
    }

    int num = 0;
    for (int i = min; i < max; i ++)
    {
        if (vs[i] && vs[i + d] && vs[i + d + d])
        {
            printf("%d %d %d %d = num %d.\n", vs[i], vs[i + d], vs[i + d + d], i + d + d, num);
            num += vs[i] * vs[i + d] * vs[i + d + d];
        }
    }
    return num;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nd = split_string(readline());

    char* n_endptr;
    char* n_str = nd[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* d_endptr;
    char* d_str = nd[1];
    int d = strtol(d_str, &d_endptr, 10);

    if (d_endptr == d_str || *d_endptr != '\0') { exit(EXIT_FAILURE); }

    char** arr_temp = split_string(readline());

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* arr_item_endptr;
        char* arr_item_str = *(arr_temp + i);
        int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);
        bool fail = false;
        if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { 
            fail = true;
            // exit(EXIT_FAILURE); 
            }

        *(arr + i) = arr_item;

        if (fail)
            break;
    }

    int arr_count = n;

    int result = beautifulTriplets(d, arr_count, arr);
    printf("%d.\n", result);

    // fprintf(fptr, "%d\n", result);

    // fclose(fptr);

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
