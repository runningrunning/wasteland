int cov(int* n, int s, int e, char* r, int ri)
{
    char* l1[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    char* l2[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    char* l3[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    int ori = ri;

    int x = s;
    if (x == e + 2)
    {
        if (n[x])
        {
            if (ri) r[ri ++] = ' ';
            ri += sprintf(r + ri, "%s Hundred", l1[n[x] - 1]);
        }
        x --;
    }

    if (x == e + 1)
    {
        if (n[x] >= 2)
        {
            if (ri) r[ri ++] = ' ';
            ri += sprintf(r + ri, "%s", l2[n[x] - 2]);
        }
        else if (n[x])
        {
            if (ri) r[ri ++] = ' ';
            int y = n[x] * 10 + n[e];
            ri += sprintf(r + ri, "%s", l3[y - 10]);
            x -= 1;
        }
        x -= 1;
    }

    if (x == e && n[x])
    {
        if (ri) r[ri ++] = ' ';
        ri += sprintf(r + ri, "%s", l1[n[x] - 1]);
    }

    char* l[] = {"Thousand", "Million", "Billion"};
    if (ori != ri && e)
        ri += sprintf(r + ri, " %s", l[((e / 3) - 1)]);
    return ri;
}

char* numberToWords(int num)
{
    if (!num)
        return strdup("Zero");

    int i = 0;
    int x[11] = {0};
    while (num)
    {
        x[i ++] = num % 10;
        num /= 10;
    }

    i --;
    int ri = 0;
    char* r = malloc(512);

    for (i; i >= 0; i --)
    {
        int n = (i / 3) * 3;
        ri = cov(x, i, n, r, ri);
        i = n;
    }
    r[ri] = 0;
    return r;
}
