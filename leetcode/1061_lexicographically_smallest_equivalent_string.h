// how does union find works here !
char * smallestEquivalentString(char * A, char * B, char * S)
{
    int i = 0;
    int all[128] = {0};
    for (int i = 'a'; i <= 'z'; i ++)
        all[i] = i;

    i = 0;
    while (A[i])
    {
        char a = A[i];
        char b = B[i];

        int xa = all[a];
        while (xa != all[xa])
            xa = all[xa];

        int xb = all[b];
        while (xb != all[xb])
            xb = all[xb];


        if (xb < xa)
            all[xa] = xb;
        else
            all[xb] = xa;

        i ++;
    }

    for (int i = 'a'; i <= 'z'; i ++)
    {
        int x = all[i];
        while (x != all[x])
            x = all[x];
        all[i] = x;
    }
    i = 0;
    while (S[i])
    {
        S[i] = all[S[i]];
        i ++;
    }
    return S;
}

/*
char * smallestEquivalentString(char * A, char * B, char * S)
{
    int i = 0;
    char all[26] = {0};
    while(A[i])
    {
        int a = A[i] - 'a';
        int b = B[i] - 'a';

        char x = A[i] < B[i] ? A[i] : B[i];

        if (all[a])
            x = x < all[a] ? x : all[a];
        if (all[b])
            x = x < all[b] ? x : all[b];

        for (int j = 0; j < 26; j ++)
        {
            // do not handle a & b here
            if (j == a || j == b)
                continue;
            if (all[j] && (all[j] == all[a] || all[j] == all[b] || all[j] == A[i] || all[j] == B[i]))
                all[j] = x;
        }
        all[a] = all[b] = x;
        i ++;
    }

    i = 0;
    while (S[i])
    {
        S[i] = all[S[i] - 'a'] ? all[S[i] - 'a'] : S[i];
        i ++;
    }
    return S;
}
*/
