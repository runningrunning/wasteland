// HINT 1, CAN NOT USE strdup
// HINT 2, care about the output format
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'passwordCracker' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY passwords
 *  2. STRING loginAttempt
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
// do optimize here ??? cache the internal result ????
// or do calculate every times ???
struct _TNode
{
    bool end;
    struct _TNode* n[26];
};
typedef struct _TNode TNode;

TNode* _cNode()
{
    TNode* n = malloc(sizeof(TNode));
    memset(n, 0, sizeof(TNode));
    return n;
}


bool _divide(char* str, int s, int e, TNode* r, int* si, int* ei, int lv, int* sn, int* b)
{
    *sn = lv;
    if (s == e)
        return true;

    if (b[s])
        return false;

    si[lv] = s;
    TNode* t = r;

    for (int i = s; i < e; i ++)
    {
        int c = str[i] - 'a';
        if (!t->n[c])
        {
            b[s] = 1;
            return false;
        }
        t = t->n[c];

        if (t->end)
        {
            ei[lv] = i;
            if (_divide(str, i + 1, e, r, si, ei, lv + 1, sn, b))
                return true;
        }
    }
    return false;
}

char* passwordCracker(int passwords_count, char** passwords, char* loginAttempt)
{
    TNode* r = _cNode();
    for (int i = 0; i < passwords_count; i ++)
    {
        char* p = passwords[i];
        int l = strlen(p);
        TNode* t = r;
        for (int j = 0; j < l; j ++)
        {
            int c = p[j] - 'a';
            if (!t->n[c])
                t->n[c] = _cNode();
            t = t->n[c];
        }
        t->end = true;
    }


    int s[2048];
    int e[2048];
    int si = 0;
    char* ret = 0;
    int l = strlen(loginAttempt);
    int* t = calloc(sizeof(int), l + 1);
    if (_divide(loginAttempt, 0, l, r, s, e, 0, &si, t))
    {
        ret = malloc(sizeof(char) * (l + si));
        int ri = 0;
        for (int i = 0; i < si; i ++)
        {
            for (int j = s[i]; j <= e[i]; j ++)
                ret[ri ++] = loginAttempt[j];
            ret[ri ++] = ' ';
        }
        ret[ri] = 0;
        return ret;
    }

    return strdup("WRONG PASSWORD");
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int t = parse_int(ltrim(rtrim(readline())));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n = parse_int(ltrim(rtrim(readline())));

        char** passwords_temp = split_string(rtrim(readline()));

        char** passwords = malloc(n * sizeof(char*));

        for (int i = 0; i < n; i++) {
            char* passwords_item = *(passwords_temp + i);

            *(passwords + i) = passwords_item;
        }

        char* loginAttempt = readline();

        char* result = passwordCracker(n, passwords, loginAttempt);

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

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
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

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
