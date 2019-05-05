// TODO ~!!!!!
// need to practice a lot !!!!!!!!!!!!!
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

// Complete the biggerIsGreater function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//
// stupid me !!!!
// wrong algorithm
char* biggerIsGreater(char* w) {
    int l = strlen(w);
    if (l == 1)
        return "no answer";

    char* r = malloc(sizeof(char) * (l + 1));
    r[l] = 0;

    for (int i = 0; i < l; i ++)
        r[i] = w[i];

    for (int n = l - 2; n >= 0; n --)
    {
        int c = w[n];
        int mc = 'z' + 1;
        int m;
        bool found = false;
        for (int j = n + 1; j < l; j ++)
        {
            if (w[j] > c)
            {
                found = true;

                if (w[j] < mc)
                {
                    mc = w[j];
                    m = j;
                }

            }
        }

        if (found)
        {
            r[n ++] = r[m];
            r[m] = c;
            int a[26] = {0};
            for (int i = n + 1; i < l; i ++)
                a[r[i] - 'a'] ++;

            for (int i = 0; i < 26; i ++)
                while (a[i])
                {
                    r[n ++] = 'a' + i;
                    a[i] --;
                }
            return r;
        }
    }
    return "no answer";
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* T_endptr;
    char* T_str = readline();
    int T = strtol(T_str, &T_endptr, 10);

    if (T_endptr == T_str || *T_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int T_itr = 0; T_itr < T; T_itr++) {
        char* w = readline();
        char* result = biggerIsGreater(w);
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
