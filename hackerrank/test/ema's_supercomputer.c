// BE MORE AND MORE CAREFUL !!!!!!!
// the cross should never be crossed each other !!!!!
// read the description correctly !!!!!
// STUPID ME !!!!!
// Pratices MORE AND MORE
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

int _size(int r, int c, char** g, int i, int j)
{
    int s = 1;
    while (i - s >= 0 && j - s >= 0 && i + s < r && j + s < c)
    {
        if (g[i - s][j] != 'G' || g[i + s][j] != 'G' || g[i][j - s] != 'G' || g[i][j + s] != 'G')
            break;
        s ++;
    }
    return s - 1;
}

int _next(int r, int c, char** g, int s)
{
    int min = INT_MIN;
    for (int i = s; i < r; i ++)
        for (int j = 0; j < c; j ++)
        {
            if (g[i][j] == 'G')
            {
                int x = _size(r, c, g, i, j);
                if (x > min)
                    min = x;
            }
        }
    return min == INT_MIN ? -1 : min;
}

// Complete the twoPluses function below.
int twoPluses(int grid_count, char** grid) {
    int r = grid_count;
    int c = strlen(grid[0]);
    char** g = grid;

    int min = INT_MIN;
    for (int i = 0; i < r ; i ++)
        for (int j = 0; j < c; j ++)
        {
            if (g[i][j] == 'G')
            {
                int x = _size(r, c, g, i, j);

                for (int _t = 0; _t <= x; _t ++)
                {
                    // no need to take care of the up
                    g[i + _t][j] = 'B';
                    g[i][j + _t] = 'B';
                    g[i][j - _t] = 'B';

                    int y = _next(r, c, g, i);
                    if (y != -1)
                    {
                        if ((4 * _t  + 1 ) * (4 * y + 1) > min)
                            min = (4 * _t + 1) * (4 * y + 1);
                    }

                }

                for (int _t = 0; _t <= x; _t ++)
                {
                    // no need to take care of the up
                    g[i + _t][j] = 'G';
                    g[i][j + _t] = 'G';
                    g[i][j - _t] = 'G';
                }
            }
        }
    return min;
}


int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nm = split_string(readline());

    char* n_endptr;
    char* n_str = nm[0];
    int n = strtol(n_str, &n_endptr, 10);

    //if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* m_endptr;
    char* m_str = nm[1];
    int m = strtol(m_str, &m_endptr, 10);

    //if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    char** grid = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        char* grid_item = readline();

        *(grid + i) = grid_item;
    }

    int grid_count = n;

    int result = twoPluses(grid_count, grid);

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
