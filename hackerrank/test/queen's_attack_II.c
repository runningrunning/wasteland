// JUST BE MORE CAREFUL !!!!!!!!!!!!!!!!
// careful about the overflow
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readline();
char **split_string(char *);

// Complete the queensAttack function below.
// be careful !!!!!!!!
int queensAttack(int n, int k, int r_q, int c_q, int obstacles_rows,
                 int obstacles_columns, int **obstacles) {
    long **out = malloc(sizeof(long *) * 3);
    out[0] = calloc(sizeof(long), 3);
    out[1] = calloc(sizeof(long), 3);
    out[2] = calloc(sizeof(long), 3);

    out[1][2] = n + 1;
    out[2][1] = n + 1;

    for (int i = 0; i < k; i++) {
        long ox = obstacles[i][0];
        long oy = obstacles[i][1];

        int dx = abs(ox - r_q);
        int dy = abs(oy - c_q);

        if (dx && dy && dx != dy)
            continue;

        if (!dx) {
            if (oy > c_q) {
                if (oy < out[1][2])
                    out[1][2] = oy;
            } else {
                if (oy > out[1][0])
                    out[1][0] = oy;
            }
        } else if (!dy) {
            if (ox > r_q) {
                if (ox < out[2][1])
                    out[2][1] = ox;
            } else {
                if (ox > out[0][1])
                    out[0][1] = ox;
            }
        } else {
            if (ox > r_q) {
                if (oy > c_q) {
                    if (!out[2][2])
                        out[2][2] = ox << 32 | oy;
                    else {
                        long tx = out[2][2] >> 32;
                        long ty = out[2][2] & 0xFFFFFFFF;

                        if (tx >= ox || ty >= oy)
                            out[2][2] = ox << 32 | oy;
                    }
                } else {
                    if (!out[2][0])
                        out[2][0] = ox << 32 | oy;
                    else {
                        long tx = out[2][0] >> 32;
                        long ty = out[2][0] & 0xFFFFFFFF;
                        if (ty <= oy || tx >= ox)
                            out[2][0] = ox << 32 | oy;
                    }
                }
            } else {
                if (oy > c_q) {
                    if (!out[0][2])
                        out[0][2] = ox << 32 | oy;
                    else {
                        long tx = out[0][2] >> 32;
                        long ty = out[0][2] & 0xFFFFFFFF;
                        if (ty >= oy || tx <= ox)
                            out[0][2] = ox << 32 | oy;
                    }
                } else {
                    if (!out[0][0])
                        out[0][0] = ox << 32 | oy;
                    else {
                        long tx = out[0][0] >> 32;
                        long ty = out[0][0] & 0xFFFFFFFF;

                        if (tx <= ox || ty <= oy)
                            out[0][0] = ox << 32 | oy;
                    }
                }
            }
        }
    }

    int num = 0;
    num += out[1][2] - c_q - 1;
    num += c_q - out[1][0] - 1;
    num += out[2][1] - r_q - 1;
    num += r_q - out[0][1] - 1;


    long tx = out[0][0] >> 32;
    long ty = out[0][0] & 0xFFFFFFFF;
    num += ((c_q - ty) > (r_q - tx) ? (r_q - tx) : (c_q - ty)) - 1;

    if (out[0][2]) {
        tx = out[0][2] >> 32;
        ty = out[0][2] & 0xFFFFFFFF;
        num += ((ty - c_q) > (r_q - tx) ? (r_q - tx) : (ty - c_q)) - 1;
    } else {
        num += ((n + 1 - c_q) > r_q ? r_q : (n + 1 - c_q)) - 1;
    }

    if (out[2][0]) {
        tx = out[2][0] >> 32;
        ty = out[2][0] & 0xFFFFFFFF;
        num += ((tx - r_q) > (c_q - ty) ? (c_q - ty) : (tx - r_q)) - 1;
    } else {
        num += ((n + 1- r_q) > c_q ? c_q : (n + 1 - r_q)) - 1;
    }

    if (out[2][2]) {
        tx = out[2][2] >> 32;
        ty = out[2][2] & 0xFFFFFFFF;
        num += ((tx - r_q) > (ty - c_q) ? (ty - c_q) : (tx - r_q)) - 1;
    } else {
        num += ((n + 1 - r_q) > (n + 1 - c_q) ? (n + 1- c_q) : (n + 1 - r_q)) - 1;
    }

    return num;
}

int main() {
    FILE *fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char **nk = split_string(readline());

    char *n_endptr;
    char *n_str = nk[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    char *k_endptr;
    char *k_str = nk[1];
    int k = strtol(k_str, &k_endptr, 10);

    if (k_endptr == k_str || *k_endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    char **r_qC_q = split_string(readline());

    char *r_q_endptr;
    char *r_q_str = r_qC_q[0];
    int r_q = strtol(r_q_str, &r_q_endptr, 10);

    if (r_q_endptr == r_q_str || *r_q_endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    char *c_q_endptr;
    char *c_q_str = r_qC_q[1];
    int c_q = strtol(c_q_str, &c_q_endptr, 10);

    if (c_q_endptr == c_q_str || *c_q_endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    int **obstacles = malloc(k * sizeof(int *));

    for (int i = 0; i < k; i++) {
        *(obstacles + i) = malloc(2 * (sizeof(int)));

        char **obstacles_item_temp = split_string(readline());

        for (int j = 0; j < 2; j++) {
            char *obstacles_item_endptr;
            char *obstacles_item_str = *(obstacles_item_temp + j);
            int obstacles_item =
                strtol(obstacles_item_str, &obstacles_item_endptr, 10);

            if (obstacles_item_endptr == obstacles_item_str ||
                *obstacles_item_endptr != '\0') {
                exit(EXIT_FAILURE);
            }

            *(*(obstacles + i) + j) = obstacles_item;
        }
    }

    int obstacles_rows = k;
    int obstacles_columns = 2;

    int result = queensAttack(n, k, r_q, c_q, obstacles_rows, obstacles_columns,
                              obstacles);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char *readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char *data = malloc(alloc_length);

    while (true) {
        char *cursor = data + data_length;
        char *line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) {
            break;
        }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char **split_string(char *str) {
    char **splits = NULL;
    char *token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char *) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
