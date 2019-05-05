// stupid questions ?
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** wordSubsets(char** A, int ASize, char** B, int BSize, int* returnSize)
{
    int bs[26] = {0};

    for (int j = 0; j < BSize; j ++)
    {
        int ns[26] = {0};
        char* b = B[j];

        int i = 0;
        int c = b[i ++];

        while (c)
        {
            ns[c - 'a'] ++;
            c = b[i ++];
        }

        for (i = 0; i < 26; i ++)
            if (ns[i] > bs[i])
                bs[i] = ns[i];
    }

    int n = 0;

    for (int j = 0; j < 26; j ++)
        if (bs[j])
            n ++;

    int ri = 0;
    char** r = malloc(sizeof(char*) * ASize);

    for (int j = 0; j < ASize; j ++)
    {
        int nm = 0;
        int ns[26] = {0};
        char* a = A[j];

        int i = 0;
        int c = a[i ++];
        bool found = false;

        while (c)
        {
            c -= 'a';
            ns[c] ++;

            if (ns[c] == bs[c])
            {
                nm ++;

                if (nm == n)
                {
                    found = true;
                    break;
                }
            }
            c = a[i ++];
        }

        if (found)
            r[ri ++] = strdup(a);
    }

    *returnSize = ri;
    return r;
}
