void ump_sort(long* n, int s, int e)
{
    if (s >= e)
        return;

    long t;

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

    ump_sort(n, cs, e - 1);
    ump_sort(n, e + 1, ce);
}

int uniqueMorseRepresentations(char** words, int wordsSize)
{
    // char* u[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
    int n[] = {2, 4, 4, 3, 1,  4, 3,  4, 2, 4, 3,  4, 2, 2, 3, 4, 4, 3, 3, 1, 3,  4, 3, 4, 4, 4};
    int f[] = {2, 7, 5, 3, 1, 13, 1, 15, 3, 8, 2, 11, 0, 1, 0, 9, 2, 5, 7, 0, 6, 14, 4, 6, 4, 3};

    long ws[101];

    for (int i = 0; i < wordsSize; i ++)
    {
        char* t = words[i];

        long w = 0;
        int k = 0;
        long l = 0;
        char c = t[k ++];

        while (c)
        {
            c -= 'a';
            w = (w << n[c]) | f[c];
            l += n[c];
            c = t[k ++];
        }
        ws[i] = (l << 48) | w;
    }

    ump_sort(ws, 0, wordsSize - 1);

    int x = 0;
    long p = ws[0] - 1;
    for (int i = 0; i < wordsSize; i ++)
    {
        if (p != ws[i])
            x ++;
        p = ws[i];
    }
    return x;
}
