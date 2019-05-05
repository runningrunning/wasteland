// READ THE DESCRIPTION !!!!!!!!!
// be careful, read the description carefully ~!!!!!!!!
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

// Complete the almostSorted function below.
void almostSorted(int arr_count, int* arr) {
    int a[4] = {0};
    int count = 0;

    for (int i = 1; i < arr_count; i ++)
    {
        if (arr[i] < arr[i - 1])
        {
            count ++;

            if (count > 2)
            {
                printf("no\n");
                return;
            }

            int s = i - 1;
            int x = i;
            while (x < arr_count && arr[x] < arr[x - 1])
                x ++;
            int e = x - 1;

            a[(count - 1) * 2] = s;
            a[(count - 1) * 2 + 1] = e;

            if (e != s + 1)
            {
                if (count == 2)
                {
                    printf("no\n");
                    return;
                }

                if (i > 1)
                {
                    if (arr[e] < arr[i - 2])
                    {
                        printf("no\n");
                        return;
                    }
                }

                if (e == arr_count - 1)
                    break;

                if (arr[i - 1] > arr[e + 1])
                {
                    printf("no\n");
                    return;
                }
            }
            i = e;
        }
    }

    if (count == 0)
    {
        printf("yes\n");
        return;
    }

    if (count == 1)
    {
        int s = a[0];
        int e = a[1];

        if (e == s + 1)
        {
            if (s > 0)
            {
                if (arr[e] < arr[s - 1])
                {
                    printf("no\n");
                    return;
                }
            }

            if (e != arr_count - 1 && arr[s] > arr[e + 1])
            {
                printf("no\n");
                return;
            }

            printf("yes\nswap %d %d\n", s + 1, e + 1);
        }
        else if (e == s + 2)
            printf("yes\nswap %d %d\n", s + 1, e + 1);
        else
            printf("yes\nreverse %d %d\n", s + 1, e + 1);
    }
    else
    {
        int s = a[0];
        int e = a[3];

        if (s > 0)
        {
            if (arr[e] < arr[s - 1])
            {
                printf("no\n");
                return;
            }
        }

        if (arr[e] > arr[s + 1])
        {
            printf("no\n");
            return;
        }

        if (e != arr_count - 1 && arr[s] > arr[e + 1])
        {
            printf("no\n");
            return;
        }

        if (arr[s] < arr[e - 1])
        {
            printf("no\n");
            return;
        }

        printf("yes\nswap %d %d\n", s + 1, e + 1);
    }
}

int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    //if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char** arr_temp = split_string(readline());

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* arr_item_endptr;
        char* arr_item_str = *(arr_temp + i);
        int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

        //if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(arr + i) = arr_item;
    }

    int arr_count = n;

    almostSorted(arr_count, arr);

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
