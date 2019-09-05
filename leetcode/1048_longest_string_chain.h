// better solution ??? DP ??
// union find with multiple previous ?
// bucket sorted ?
bool _is_pre(char* p, char* s, int l)
{
    int pi = 0;
    for (int i = 0; i < l; i ++)
        if (s[i] == p[pi])
            pi ++;
    return pi == l - 1;
}

int comp(const void* a, const void* b)
{
    return strlen(*((char**)a)) - strlen(*((char**) b));
}

int longestStrChain(char ** words, int wordsSize)
{
    qsort(words, wordsSize, sizeof(char*), comp);
    int* ls = malloc(sizeof(int) * wordsSize);
    int* ms = calloc(sizeof(int), wordsSize);
    ls[0] = strlen(words[0]);

    for (int i = 1; i < wordsSize; i ++)
    {
        int l = strlen(words[i]);

        ls[i] = l;

        for (int j = i - 1; j >= 0; j --)
        {
            if (l - ls[j] > 1)
                break;

            if (l == ls[j])
                continue;

            if (_is_pre(words[j], words[i], l))
                ms[i] = ms[i] > (ms[j] + 1) ? ms[i] : (ms[j] + 1);
        }
    }

    int max = 0;
    for (int i = 0; i < wordsSize; i ++)
        max = max < ms[i] ? ms[i] : max;
    return max + 1;
}

/*
int _chain(int** ps, int* ms, int i)
{
    if (!ps[i])
        return 0;

    if (ms[i])
        return ms[i];

    int max = 0;
    for (int j = 0; j < ps[i][0]; j ++)
    {
        int l = 1 + _chain(ps, ms, ps[i][j + 1]);

        if (l > max)
            max = l;
    }
    ms[i] = max;
    return ms[i];
}

bool _is_pre(char* p, char* s, int l)
{
    int pi = 0;
    for (int i = 0; i < l; i ++)
        if (s[i] == p[pi])
            pi ++;
    return pi == l - 1;
}

int longestStrChain(char ** words, int wordsSize)
{
    int** ps = calloc(sizeof(int*), wordsSize);
    int* ls = malloc(sizeof(int) * wordsSize);

    for (int i = 0; i < wordsSize; i ++)
        ls[i] = strlen(words[i]);

    for (int i = 0; i < wordsSize; i ++)
        for (int j = i + 1; j < wordsSize; j ++)
        {
            int d = abs(ls[i] - ls[j]);
            if (d != 1)
                continue;

            int p = i;
            int s = j;
            int l = ls[j];

            if (ls[i] > ls[j])
            {
                p = j;
                s = i;
                l = ls[i];
            }

            if (_is_pre(words[p], words[s], l))
            {
                if (!ps[s])
                {
                    ps[s] = malloc(sizeof(int) * 2);
                    ps[s][0] = 1;
                }
                else
                {
                    ps[s][0] += 1;
                    ps[s] = realloc(ps[s], sizeof(int) * (ps[s][0] + 1));
                }
                ps[s][ps[s][0]] = p;
            }
        }

    int max = 0;
    int* ms = calloc(sizeof(int), wordsSize);

    for (int i = 0; i < wordsSize; i ++)
    {
        int l = 1 + _chain(ps, ms, i);
        if (l > max)
            max = l;
    }
    return max;
}
*/
