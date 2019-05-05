char* toIP(long int i, int bs)
{
    char* r = malloc(20);
    sprintf(r, "%d.%d.%d.%d/%d", (i >> 24) & 0xFF, (i >> 16) & 0xFF, (i >> 8) & 0xFF, i & 0xFF, bs);
    return r;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** ipToCIDR(char* ip, int num, int* returnSize)
{
    long int n_ip = 0;
    int n = 0;
    int i = 0;

    while(ip[i])
    {
        if (ip[i] == '.')
        {
            n_ip |= n;
            n_ip <<= 8;
            n = 0;
        }
        else
            n = n * 10 + ip[i] - '0';
        i ++;
    }
    n_ip |= n;

    long l = 0;

    int rs = 0;
    char** ret = malloc(sizeof(char*));

    long end_ip = n_ip + num;
    for (long i = n_ip; i < end_ip; )
    {
        l = i - (i & (i - 1));
        while (i + l > end_ip)
            l >>= 1;

        int bs = 32;
        int tl = l;
        while (tl != 1)
        {
            bs --;
            tl >>= 1;
        }
        rs ++;

        if (!ret)
            ret = malloc(sizeof(char*));
        else
            ret = realloc(ret, sizeof(char*) * rs);

        ret[rs - 1] = toIP(i, bs);
        i += l;
    }

    *returnSize = rs;
    return ret;
}
