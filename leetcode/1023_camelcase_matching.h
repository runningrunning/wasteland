/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* camelMatch(char** queries, int queriesSize, char* pattern, int* returnSize)
{
    *returnSize = 0;
    if (!queries || !queriesSize || !pattern)
        return NULL;
    *returnSize = queriesSize;
    bool* r = malloc(sizeof(bool) * queriesSize);
    char* p = pattern;

    for (int i = 0; i < queriesSize; i ++)
    {
        int pi = 0;
        int qi = 0;
        char* q = queries[i];
        bool match = true;
        while (p[pi] && q[qi])
        {
            if (q[qi] == p[pi])
                pi ++;
            else if (q[qi] <= 'Z')
            {
                match = false;
                break;
            }
            qi ++;
        }

        if (p[pi])
            match = false;
        else
            while (q[qi])
            {
                if (q[qi] <= 'Z')
                {
                    match = false;
                    break;
                }
                qi ++;
            }
        r[i] = match;
    }

    return r;
}
