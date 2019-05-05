// C CODE ERROR AGAIN !!!
// HOW TO WRITE RELIABLE C CODE here !!!
// HOW TO PROVE only 2 rounds it will be stable ?????
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

// Complete the bomberMan function below.

// Please store the size of the string array to be returned in result_count pointer. For example,
// char a[2][6] = {"hello", "world"};
//
// *result_count = 2;
//
// return a;
//
char** bomberMan(int n, int grid_count, char** grid, int* result_count) {
    *result_count = grid_count;
    if (n == 1)
        return grid;
    n = (n - 1) % 4;
    int r = grid_count;
    int c = strlen(grid[0]);

    if (n == 1 || n == 3)
    {
        for (int i = 0; i < r; i ++)
            for (int j = 0; j < c; j ++)
                grid[i][j] = 79;

        return grid;
    }

    int t = n == 0 ? 2 : 1;

    for (int k = 0; k < t; k ++)
    {
        for (int i = 0; i < r; i ++)
            for (int j = 0; j < c; j ++)
            {
                if (grid[i][j] == '.')
                    grid[i][j] = 79;
                else
                    grid[i][j] = 'X';
            }

        for (int i = 0; i < r; i ++)
            for (int j = 0; j < c; j ++)
            {
                if (grid[i][j] == 'X')
                {
                    grid[i][j] = '.';
                    if (i && grid[i - 1][j] == 79)
                        grid[i - 1][j] = '.';
                    if (i != r - 1 && grid[i + 1][j] == 79)
                        grid[i + 1][j] = '.';
                    if (j && grid[i][j - 1] == 79)
                        grid[i][j - 1] = '.';
                    if (j != c - 1 && grid[i][j + 1] == 79)
                        grid[i][j + 1] = '.';
                }
            }
    }

    return grid;
}

int main()
{

    // FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");
    FILE* fptr = fopen("output.txt", "w");
    char** rcn = split_string(readline());

    char* r_endptr;
    char* r_str = rcn[0];
    int r = strtol(r_str, &r_endptr, 10);

    //if (r_endptr == r_str || *r_endptr != '\0') { exit(EXIT_FAILURE); }

    char* c_endptr;
    char* c_str = rcn[1];
    int c = strtol(c_str, &c_endptr, 10);

    //if (c_endptr == c_str || *c_endptr != '\0') { exit(EXIT_FAILURE); }

    char* n_endptr;
    char* n_str = rcn[2];
    int n = strtol(n_str, &n_endptr, 10);

    // (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** grid = malloc(r * sizeof(char*));

    for (int i = 0; i < r; i++) {
        char* grid_item = readline();

        *(grid + i) = grid_item;
    }

    int grid_count = r;

    int result_count;
    char** result = bomberMan(n, grid_count, grid, &result_count);

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%s", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    //fprintf(fptr, "\n");

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
