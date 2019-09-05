int shortestWay(char * source, char * target)
{
    int sf = 0;
    int tf = 0;
    int si = 0;
    int ti = 0;

    while (source[si])
        sf |= 1 << (source[si ++] - 'a');

    while (target[ti])
        tf |= 1 << (target[ti ++] - 'a');

    if ((sf | tf) != sf)
        return -1;

    int n = 1;

    ti = 0;
    si = 0;

    while(target[ti])
    {
        int c = target[ti ++];
        while (source[si] != c)
            if (!source[si ++])
            {
                si = 0;
                n ++;
            }
        si ++;
    }
    return n;
}

