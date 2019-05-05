// is there any easy way to solve this ?
int magicalString(int n)
{
    int* fgs = malloc(((n + 32) / 32) * sizeof(int));
    // initialize to "12"
    fgs[0] = 1;

    int bits = 0;
    int tbits = 0;

    int set = 1;
    int all = 0;

    while (bits < n)
    {
        if (set)
        {
            all ++;
            int b = bits % 32;
            if (!b)
                fgs[bits / 32] = 1;
            else
                fgs[bits / 32] |= 1 << b;
        }

        if (++ bits >= n)
            break;

        if (!(fgs[tbits / 32] & (1 << (tbits % 32))))
        {
            if (set)
            {
                all ++;
                int b = bits % 32;
                if (!b)
                    fgs[bits / 32] = 1;
                else
                    fgs[bits / 32] |= 1 << b;
            }
            bits ++;
        }

        tbits ++;
        set = !set;
    }
    return all;
}

/*
// is there any easy way to solve this ?
int magicalString(int n)
{
    if (!n)
        return 0;

    if (n < 3)
        return 1;

    int* fgs = malloc(((n + 32) / 32) * sizeof(int));
    // initialize to "12"
    fgs[0] = 1;

    int bits = 0;
    int tbits = 0;

    int tb = 0;
    int tf = 0;
    int tx = 1;

    int sb = 0;
    int sf = 0;
    int sx = 1;
    int set = 1;

    int all = 0;

    while (true)
    {
        tb = tbits / 32;
        tx = 1 << (tbits % 32);

        sb = bits / 32;
        sx = 1 << (bits % 32);

        bits ++;

        if (set)
        {
            all ++;
            fgs[sb] |= sx;
        }

        if (bits == n)
            break;

        if (sx == 2147483648)
            fgs[sb + 1] = 0;

        if (!(fgs[tb] & tx))
        {
            sb = bits / 32;
            sx = 1 << (bits % 32);

            if (set)
            {
                all ++;
                fgs[sb] |= sx;
            }

            bits ++;

            if (bits == n)
                break;

            if (sx == 2147483648)
                fgs[sb + 1] = 0;
        }
        tbits ++;
        set = !set;
    }

    return all;
}
*/

/*
// is there any easy way to solve this ?
int magicalString(int n)
{
    int* fgs = malloc(((n + 32) / 32) * sizeof(int));
    // initialize to "12"
    fgs[0] = 1;

    int bits = 0;

    int tb = 0;
    int tf = 0;
    int tx = 1;

    int sb = 0;
    int sf = 0;
    int sx = 1;
    int set = 1;

    int all = 0;

    while (bits < n)
    {
        bits ++;

        if (set)
        {
            all ++;
            fgs[sb] |= sx;
        }

        sf ++;

        if (sf % 32)
            sx <<= 1;
        else
        {
            sx = 1;
            sb ++;
            fgs[sb] = 0;
        }

        if (bits == n)
            break;

        if (!(fgs[tb] & tx))
        {
            if (set)
            {
                all ++;
                fgs[sb] |= sx;
            }

            sf ++;

            if (sf % 32)
                sx <<= 1;
            else
            {
                sx = 1;
                sb ++;
                fgs[sb] = 0;
            }

            bits ++;
        }

        tf ++;

        if (tf % 32)
            tx <<= 1;
        else
        {
            tx = 1;
            tb ++;
        }
        set = !set;
    }
    return all;
}

*/
