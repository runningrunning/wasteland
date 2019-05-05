/* handle /. */
char* simplifyPath(char* path)
{
    int l = strlen(path);
    if (l <= 1)
        return path;

    int* stack = malloc(sizeof(int) * (l + 1));
    int i = 0;
    int n = 0;

    if (path[0] == '/')
        stack[n ++] = 0;
    else
    {
        printf("error here.\n");
    }
    /* else */
    /* { */
    /*     while(path[i] && path[i] != '/') */
    /*         i ++; */
    /*     stack[n++] = i - 1; */
    /* } */

    for(; i < l;)
    {
        /* skip / */
        i += 1;
        int c = i;
        while(path[i] && path[i] != '/')
            i ++;
        if (i > c)
            stack[n++] = c << 16 | i - c - 1;
    }

    int c = 0;

    for(int i = 0; i < n; i ++)
    {
        int cs = stack[i] >> 16;
        int cn = stack[i] & 0xFFFF;
        if (cn == 0 && path[cs] == '.')
            continue;

        if (cn == 1 && path[cs] == '.' && path[cs + 1] == '.')
        {
            c --;
            if (c == 0)
                c = 1;
            continue;
        }
        stack[c ++] = stack[i];
    }

    n = 0;
    char* r = strdup(path);

    if (c == 1)
    {
        r[0] = '/';
        r[1] = 0;
    }
    else
    {
        for(int i = 1; i < c; i ++)
        {
            int cs = stack[i] >> 16;
            int cn = stack[i] & 0xFFFF;

            r[n++] = '/';

            for(int j = cs; j <= cs + cn; j++)
                r[n++] = path[j];
        }

        r[n] = 0;
    }

    return r;
}
