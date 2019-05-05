void try(char*** r, char* s, int l, int u, int o, int n)
{
    if (n > l - u || !n)
        return;

    if (n == l - u)
    {
        **r = malloc(sizeof(char) * (l + 4));
        (**r)[l + 3] = 0;

        int x = 0;
        int xs = 0;
        int on = 4 - n;
        for(int i = 0; i < on; i ++)
        {
            for(int j = 0; j < ((o >> ((on - i - 1) * 8)) & 0xFF); j ++)
                (**r)[x ++] = s[xs ++];
            (**r)[x++] = '.';
        }

        for(int i = 0; i < n; i++)
        {
            if (i != 0)
                (**r)[x++] = '.';
            (**r)[x++] = s[xs++];
        }
        (**r)[x++] = 0;

        (*r) ++;

        return;
    }

    if (n == 1)
    {
        if (s[u] == '0')
            return;

        if (l - u > 3)
            return;

        if (l - u == 3)
        {
            int x = (s[u] - '0') * 100 + (s[u + 1] - '0') * 10 + s[u + 2] - '0';
            if (x > 255)
                return;
        }

        **r = malloc(sizeof(char) * (l + 4));
        (**r)[l + 3] = 0;

        int x = 0;
        int xs = 0;
        int on = 3;
        for(int i = 0; i < on; i ++)
        {
            for(int j = 0; j < ((o >> ((on - i - 1) * 8)) & 0xFF); j ++)
                (**r)[x ++] = s[xs ++];
            (**r)[x++] = '.';
        }

        if (l != u)
        {
            xs = u;
            for (int i = 0; i < l - u; i++)
                (**r)[x++] = s[xs++];
        }
        else
            (**r)[x++] = '0';

        (**r)[x++] = 0;
        (*r) ++;

        return;
    }

    int x = (s[u] - '0') * 100 + (s[u + 1] - '0') * 10 + s[u + 2] - '0';

    if (x > 255)
    {
        try(r, s, l, u + 1, (o << 8) | 1, n - 1);
        try(r, s, l, u + 2, (o << 8) | 2, n - 1);
    }
    else
    {
        try(r, s, l, u + 1, (o << 8) | 1, n - 1);
        if (s[u] != '0')
        {
            try(r, s, l, u + 2, (o << 8) | 2, n - 1);
            try(r, s, l, u + 3, (o << 8) | 3, n - 1);
        }
    }
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** restoreIpAddresses(char* s, int* returnSize) {
    // 3 * 3 * 3 * 3 = 81;
    int n = 4;
    int l = strlen(s);
    char** ret = malloc(sizeof(char*) * 81);
    memset(ret, 0, sizeof(char*) * 81);
    char** cur_ret = ret;
    int used = 0;
    int offset = 0;
    try(&cur_ret, s, l, used, offset, n);

    n = 0;
    for(int i = 0; i < 81; i ++)
    {
        if (ret[i])
            n ++;
        else
            break;
    }

    *returnSize = n;
    return ret;
}

