#define PRIME 1031
void _noa_sort(char** a, int s, int e, int* id)
{
    if (s > e)
        return;

    char* t;
    int ti;

    if (strcmp(a[s], a[e]) > 0)
    {
        t = a[s];
        a[s] = a[e];
        a[e] = t;

        ti = id[s];
        id[s] = id[e];
        id[e] = ti;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (strcmp(a[i], a[s]) < 0) i ++;
        while (strcmp(a[e], a[s]) > 0) e --;

        if (i >= e)
        {
            t = a[s];
            a[s] = a[e];
            a[e] = t;

            ti = id[s];
            id[s] = id[e];
            id[e] =ti;
        }
        else
        {
            t = a[i];
            a[i] = a[e];
            a[e] = t;

            ti = id[i];
            id[i] = id[e];
            id[e] = ti;
        }
    }
    _noa_sort(a, cs, e - 1, id);
    _noa_sort(a, e + 1, ce, id);
}

char* countOfAtoms(char* f)
{
    int* hash = calloc(sizeof(int), PRIME);
    int ai = 1; // start from 1
    char** as = malloc(sizeof(char*) * 1024);

    int si = 0;
    long* stack = malloc(sizeof(long) * 1024);

    int cs = 0;
    char* s = malloc(1024);

    int i = 0;
    int c = f[i ++];

    while (c)
    {
        if (c == '(')
        {
            c = f[i ++];
            stack[si ++] = INT_MAX;
        }
        else if (c == ')')
        {
            c = f[i ++];

            long num = 1;
            if (c && c >= '0' && c <= '9')
            {
                num = 0;
                while (c && c >= '0' && c <= '9')
                {
                    num = num * 10 + c - '0';
                    c = f[i ++];
                }
            }

            int ti = si - 1;
            while (stack[ti] != INT_MAX)
            {
                if (stack[ti] != INT_MIN && num)
                    stack[ti] = (stack[ti] & (0xFFFFFFFFL << 32)) | ((stack[ti] & 0xFFFFFFFF) * num);
                ti --;
            }
            stack[ti] = INT_MIN;
        }
        else // if (c >= 'A' && c <= 'Z')
        {
            cs = 0;
            s[cs ++] = c;

            c = f[i ++];
            while (c && c >= 'a' && c <= 'z')
            {
                s[cs ++] = c;
                c = f[i ++];
            }

            s[cs] = 0;

            long num = 1;
            if (c && c >= '0' && c <= '9')
            {
                num = 0;
                while (c && c >= '0' && c <= '9')
                {
                    num = num * 10 + c - '0';
                    c = f[i ++];
                }
            }

            long id = 0;
            for (int j = 1; j < ai; j ++)
                if (!strcmp(as[j], s))
                    id = j;

            if (!id)
            {
                as[ai] = strdup(s);
                id = ai ++;
            }
            // printf("id %d %s num %d.\n", id, s, num);
            stack[si ++] = (id << 32) | num;
        }
    }

    int* nums = calloc(sizeof(int), ai);
    for (int i = 0; i < si; i ++)
    {
        if (stack[i] != INT_MIN && stack[i] != INT_MAX)
        {
            long id = stack[i] >> 32;
            long n = stack[i] & 0xFFFFFFFF;
            nums[id] += n;
        }
    }

    _noa_sort(as, 1, ai - 1, nums);

    int r = 0;
    for (int i = 1; i < ai; i ++)
    {
        if (nums[i] == 1)
            r += sprintf(s + r, "%s", as[i]);
        else
            r += sprintf(s + r, "%s%d", as[i], nums[i]);
    }

    return s;
}
