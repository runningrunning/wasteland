#define STEP 128
char* decodeString(char* s)
{
    int l = strlen(s);
    if (l < 4)
        return strdup(s);

    int si = 0;
    int* stack = malloc(sizeof(int) * STEP);
    int* rsi = malloc(sizeof(int) * STEP);

    int ri = 0;
    int rc = 1024;
    char* r = malloc(rc);

    int i = 0;
    char c = s[i ++];

    while(c)
    {
        if (c >= '0' && c <= '9')
        {
            int ni = i;
            char nc = s[ni ++];
            int n = c - '0';

            while (nc != '[')
            {
                n = n * 10 + nc - '0';
                nc = s[ni ++];
            }

            if (!((si + 1) % STEP))
            {
                stack = realloc(stack, sizeof(int) * (si + STEP + 1));
                rsi = realloc(rsi, sizeof(int) * (si + STEP + 1));
            }

            stack[si] = n;
            rsi[si] = ri;

            si ++;
            i = ni;

            c = s[i ++];
            continue;
        }
        else if (c == ']')
        {
            si --;
            int k = stack[si];
            int oi = rsi[si];
            int d = ri - oi;

            if (k > 1)
            {
                if (ri + d * (k - 1) >= rc)
                {
                    rc = ri + d * (k - 1) + 1024;
                    r = realloc(r, rc);
                }

                while (-- k)
                {
                    memcpy(&r[ri], &r[oi], d);
                    ri += d;
                    oi += d;
                }
            }
        }
        else
        {
            if (ri + 1 == rc)
            {
                rc += 1024;
                r = realloc(r, rc);
            }
            r[ri ++] = c;
        }

        c = s [i ++];
    }
    r[ri] = 0;
    return r;
}
