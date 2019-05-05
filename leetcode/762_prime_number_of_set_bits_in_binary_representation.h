/* better solution ? */
int nbits(int x)
{
    int i = 0;
    while (x)
    {
        x &= x - 1;
        i ++;
    }
    return i;
}
int countPrimeSetBits(int L, int R) {
    int prime[32] = {
        0, 0, 1, 1, 0, 1, 0, 1,
        0, 0, 0, 1, 0, 1, 0, 0,
        0, 1, 0, 1, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 1, 0, 1
    };

    if (L == R)
        return prime[nbits(L)];

    int count = 0;
    for (int i = L; i <= R; i ++)
        count += prime[nbits(i)];
    return count;
}
