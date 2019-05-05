// just hash
int numUniqueEmails(char** emails, int emailsSize)
{
    // 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536
    // 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, Ok.
    int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617};
    int pl = sizeof(pri)/sizeof(pri[0]);
    int dp = 1031;

    for (int i = 0; i < pl; i ++)
    {
        dp = pri[i];
        if (dp / 4 > emailsSize)
            break;
    }

    int r = 0;
    int ei = 0;
    char** es = malloc(sizeof(char*) * emailsSize);
    int* hash = calloc(sizeof(int), dp);

    char temp[265];
    for (int i = 0; i < emailsSize; i ++)
    {
        int ti = 0;
        long eh = 0;
        char* e = emails[i];
        int ci = 0;
        char c = e[ci ++];

        while (c != '@' && c != '+')
        {
            if (c != '.')
            {
                temp[ti ++] = c;
                eh = ((eh << 8) + c) %dp;
            }
            c = e[ci ++];
        }

        while (c != '@')
            c = e[ci ++];

        while (c)
        {
            temp[ti ++] = c;
            eh = ((eh << 8) + c) %dp;
            c = e[ci ++];
        }

        temp[ti] = 0;

        while (hash[eh] && strcmp(temp, es[hash[eh] - 1]))
            eh = (eh + 1) % dp;

        if (!hash[eh])
        {
            r ++;
            es[ei ++] = strdup(temp);
            hash[eh] = ei;
        }
    }
    return r;
}
