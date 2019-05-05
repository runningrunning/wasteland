typedef int bool;
#include "common.h"

#if 0
// KISS
char* superReducedString(char* s) {
    int si = 0;
    int se = 0;
    int sl = strlen(s);

    while (se < sl)
    {
        int i = se;
        while (i + 1 < sl && s[i] == s[i + 1])
            i ++;

        if (i == se)
            s[si ++] = s[se ++];
        else
        {
            int d = i - se + 1;
            if (d % 2)
            {
                s[si ++] = s[se ++];
                se = i + 1;
            }
            else
            {
                while (si > 0 && i + 1 < sl)
                    if (s[si - 1] == s[i + 1])
                    {
                        si --;
                        i ++;
                    }
                    else
                        break;
                se = i + 1;
            }
        }
    }
    if (si == 0)
        return "Empty String";
    s[si] = 0;
    return s;
}
#endif

// Complete the alternate function below.
// find better solution ?
int alternate(char* s) {
    int** a = malloc(sizeof(int*) * 26);
    for (int i = 0; i < 26; i ++)
        a[i] = calloc(sizeof(int), 26);

    int i = 0;
    while (s[i])
    {
        int c = s[i] - 'a';
        for (int j = 0; j < 26; j ++)
        {
            if (a[c][j] != -1)
            {
                a[j][c] = a[c][j] + 1;
                a[c][j] = -1;
            }
            else if (a[j][c] != -1)
                a[j][c] = -1;
        }
        i ++;
    }

    int max = INT_MIN;
    for (int i = 0; i < 26; i ++)
        for (int j = 0; j < 26; j ++)
            if (max < a[i][j])
                max = a[i][j];
    return max < 2 ? 0 : max;
}

int main()
{
    // char* s = "abc";
    // char* s = "baab";
    // char* s = "aa";
    // char* s = "aaabccddd";
    // char* s = "efffeeeffeeffefe";
    // printf("%s %s.\n", s, superReducedString(strdup(s)));

    char* s = "beabeefeab";
    // char* s = "abaacdabd";
    // char* s = "ababababababba";
    // char* s = "bababababaab";

    printf("%d.\n", alternate(s));
}
