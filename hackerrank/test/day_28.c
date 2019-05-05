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

int comp_str(const void* e1, const void* e2)
{
    return strcmp(*((const char**)e1), *((const char**)e2));
}

bool is_gmail(char* e)
{
    const char* gmail  = "@gmail.com";
    int c = strlen(gmail);
    int l = strlen(e);

    if (l <= c) return false;

    for (int i = l - c; i < l; i ++)
        if (e[i] != gmail[i + c - l])
            return false;

    for (int i = 0; i < l - c; i ++)
        if (e[i] == '@' || e[i] == '.')
            return false;
    return true;
}

int main()
{
    char* N_endptr;
    char* N_str = readline();
    int N = strtol(N_str, &N_endptr, 10);

    if (N_endptr == N_str || *N_endptr != '\0') { exit(EXIT_FAILURE); }

    int ni = 0;
    char** names = malloc(sizeof(char*) * N);

    for (int N_itr = 0; N_itr < N; N_itr++) {
        char** firstNameEmailID = split_string(readline());

        char* firstName = firstNameEmailID[0];

        char* emailID = firstNameEmailID[1];

        if (is_gmail(emailID))
            names[ni ++] = firstName;
    }

    qsort(names, ni, sizeof(char*), comp_str);
    for (int i = 0; i < ni; i ++)
        printf("%s\n", names[i]);
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
