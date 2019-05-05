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

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
    char r[256] = {0};
    r[0] = 1;
    int tr = 0;

    for (int i = 1; i <= n; i ++)
    {
        int x = i;
        int o = 0;

        char e[256] = {0};

        while (x)
        {
            int c = 0;
            int m = x % 10;
            x /= 10;

            if (m)
            {
                char t[256] = {0};
                for (int j = o; j < 256 && j <= o + tr + 1; j ++)
                {
                    int z = m * r[j - o] + c;
                    t[j] = z % 10;
                    c = z / 10;
                }
                c = 0;
                for (int j = 0; j < 256; j ++)
                {
                    int z = e[j] + t[j] + c;
                    e[j] = z % 10;
                    c = z / 10;

                    if (e[j])
                        tr = j;
                }
            }
            o ++;
        }
        memcpy(r, e, sizeof(char) * 256);
    }

    for (int i = tr; i >= 0; i --)
        printf("%c", r[i] + '0');
    printf("\n");
}

int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    extraLongFactorials(n);

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
