// failed too much
// failed qsort !!!
void nms_sort(char** w, int s, int e)
{
    if (s >= e)
        return;

    char* t;

    if (strcmp(w[s], w[e]) > 0)
    {
        t = w[s];
        w[s] = w[e];
        w[e] = t;
    }

    if (s + 1 >= e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (strcmp(w[i], w[s]) < 0) i ++;  // can not add <=, or it will go over the latest index of S, it's pivot !!!
        while (strcmp(w[e], w[s]) > 0) e --;

        if (i >= e)
        {
            t = w[s];
            w[s] = w[e];
            w[e] = t;
        }
        else
        {
            t = w[i];
            w[i] = w[e];
            w[e] = t;
        }
    }

    nms_sort(w, cs, e - 1);
    nms_sort(w, e + 1, ce);
}

// hash stuff ?
// brute force ?
int numMatchingSubseq(char* S, char** words, int wordsSize)
{
    if (!wordsSize)
        return 0;

    int l = strlen(S);
    for (int i = 1; i < wordsSize; i ++)
        if (strcmp(words[i], words[i - 1]) < 0)
        {
            nms_sort(words, 0, wordsSize - 1);
            break;
        }

    int num = 0;
    int st_i = 0;
    int stack[51];

    char* t = words[0];
    int ls = strlen(t);

    int si = 0;

    for (int i = 0; i < ls; i ++)
    {
        while (S[si] && S[si] != t[i])
            si ++;

        if (!S[si])
            break;

        stack[st_i ++] = si;
    }

    num = st_i == ls ? 1 : 0;

    int pre = num;
    char* p = t;

    for (int i = 1; i < wordsSize; i ++)
    {
        int x = 0;
        t = words[i];
        ls = strlen(t);

        while (p[x] && p[x] == t[x])
            x ++;

        if (!t[x])  // if it's same, don't do it again.
        {
            num += pre;
            continue;
        }

        st_i = st_i >= x ? x : st_i;
        si = x ? stack[x - 1] : -1;
        si ++;

        for (int j = st_i; j < ls; j ++)
        {
            while (S[si] && S[si] != t[j])
                si ++;

            if (!S[si])
                break;
            stack[st_i ++] = si ++;
        }

        pre = st_i == ls ? 1 : 0;
        num += pre;
        p = t;
    }
    return num;
}
