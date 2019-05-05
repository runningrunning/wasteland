void nr_sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }
    nr_sort(n, cs, e - 1);
    nr_sort(n, e + 1, ce);
}

int numRabbits(int* answers, int answersSize)
{
    if (!answers || !answersSize)
        return 0;
    nr_sort(answers, 0, answersSize - 1);

    int all = 0;
    for (int i = 0; i < answersSize; i ++)
    {
        int c = answers[i];
        all += c + 1;
        if (i + c < answersSize && c == answers[i + c])
            i += c;
        else
            while (i < answersSize && answers[i + 1] == c)
                i ++;
    }

    return all;
}
