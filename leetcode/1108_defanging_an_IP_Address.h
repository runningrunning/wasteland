char * defangIPaddr(char * address)
{
    char* r = malloc(sizeof(char) * 64);
    int ri = 0;
    int ai = 0;
    while (address[ai])
        if (address[ai] != '.')
            r[ri ++] = address[ai ++];
        else
        {
            r[ri ++] = '[';
            r[ri ++] = '.';
            r[ri ++] = ']';
            ai ++;
        }
    r[ri] = 0;
    return r;
}

