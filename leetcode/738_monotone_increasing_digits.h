int monotoneIncreasingDigits(int N)
{
    int i = 0;
    int ns[10] = {0};
    int pb = 10;
    int e = -1;
    int oN = N;

    while(N)
    {
        int b = N % 10;
        if (b > pb)
            e = i;

        pb = b;
        N /= 10;
        ns[i ++] = b;
    }

    if (e == -1)
        return oN;

    while(ns[e + 1] == ns[e])
        e ++;

    oN = 0;
    ns[e] --;

    for (int j = i - 1; j >= 0; j --)
    {
        oN *= 10;
        oN += j < e ? 9 : ns[j];
    }
    return oN;
}
