/* TODO more careful about i equal 0 or NOT */
int repeatedStringMatch(char* A, char* B)
{
    int la = strlen(A);
    int lb = strlen(B);

    if (!la || !lb)
        return -1;

    int ai = 0;
    int bi = 0;
    int a[256] = {0};
    for (int i = 0; i < la; i ++)
        a[A[i]] = 1;

    for (int i = 0; i < la; i++)
    {
        if (A[i] == B[0])
        {
            int j = 0;
            int s = i;
            for (; j < lb; j ++)
            {
                if (!a[B[j]])
                    return -1;

                if (B[j] != A[s % la])
                    break;
                s ++;
            }

            if (j == lb)
            {
                // la > lb is different case
                if (s <= la)
                    return 1;

                // When i is 0 or not are different cases.
                if (i)
                    return (((lb + i - la) + la - 1) / la) + 1;
                return (lb + la - 1) / la;
            }
        }
    }
    return -1;
}
