/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

long _id(char* w)
{
    int i = 0;
    long id = 0;

    while (w[i])
    {
        char c = w[i ++];
        if (c >= 'a')
            c -= 'a';
        else
            c -= 'A';
        id = id << 5 | c;
    }
    return id;
}

long _no_id(char* w)
{
    int i = 0;
    long id = 0;

    while (w[i])
    {
        char c = w[i ++];
        if (c >= 'a')
            c -= 'a';
        else
            c -= 'A';

        if (c == 'a' - 'a')
            c = 31;
        else if (c == 'e' - 'a')
            c = 31;
        else if (c == 'i' - 'a')
            c = 31;
        else if (c == 'o' - 'a')
            c = 31;
        else if (c == 'u' - 'a')
            c = 31;

        id = id << 5 | c;
    }
    return id;
}

int comp_long(const void* e1, const void* e2)
{
    long x = *((long*)e1) - *((long*)e2);
    if (x == 0)
        return 0;
    return x > 0L ? 1 : -1;
}

int _find(long* all, int s, int e, long need)
{
    if (all[e] < need || (all[s] > need + (1L << 16)))
        return - 1;

    while (s < e)
    {
        int m = (s + e) / 2;

        if (all[m] < need)
            s = m + 1;
        else
            e = m;
    }

    long x = all[s];
    x -= x & 0xFFFF;

    if (x != need)
        return -1;

    return s;
}

char** spellchecker(char** wordlist, int wordlistSize, char** queries, int queriesSize, int* returnSize)
{
    *returnSize = 0;

    if (!wordlist || !wordlistSize || !queries || !queriesSize)
        return NULL;

    *returnSize = queriesSize;

    int ai = 0;
    long* all = malloc(sizeof(long) * wordlistSize);
    long* all_no = malloc(sizeof(long) * wordlistSize);

    for (int i = 0; i < wordlistSize; i ++)
    {
        all[i] = _id(wordlist[i]) << 16 | i;
        all_no[i] = _no_id(wordlist[i]) << 16 | i;
    }

    qsort(all, wordlistSize, sizeof(long), comp_long);
    qsort(all_no, wordlistSize, sizeof(long), comp_long);

    char** ret = calloc(sizeof(char*), queriesSize);
    for (int i = 0; i < queriesSize; i ++)
    {
        long qid = _id(queries[i]) << 16;
        int st = _find(all, 0, wordlistSize - 1, qid);
        if (st == -1)
        {
            qid = _no_id(queries[i]) << 16;
            st = _find(all_no, 0, wordlistSize - 1, qid);
            ret[i] = strdup(st == - 1 ? "" : wordlist[all_no[st] & 0xFFFF]);
        }
        else
        {
            qid += 1L << 16;
            int s = st;
            bool got = false;
            while (s < wordlistSize && all[s] < qid)
            {
                int id = all[s] & 0xFFFF;
                if (!strcmp(wordlist[id], queries[i]))
                {
                    got = true;
                    break;
                }
                s ++;
            }
            ret[i] = strdup(wordlist[all[got ? s : st] & 0xFFFF]);
        }
    }

    return ret;
}
