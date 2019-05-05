int kthGrammar(int N, int K)
{
    int reverse = 0;
    while (N)
    {
        if (!(K & 1))
            reverse = !reverse;
        K = (K + 1) >> 1;
        if (K == 1)
            break;
        N --;
    }
    // K will be always 1 at the last
    return reverse;
}
