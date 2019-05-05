bool cmw(int x, int y, int z)
{
    if (z > x)
        return cmw(x, y, z - x);

    if (z > y)
        return cmw(x, y, z - y);

    if (z == x || z == y)
        return true;

    int b = x % y;

    if (!b)
        return false;

    if (z == b)
        return true;

    if (y - b == b)
        return false;

    int pb = b;
    while (true)
    {
        // printf("=== try %d %d.\n", b, y -b);
        if (z == b || z == y - b)
            return true;
        b = (x - (y - b)) % y;

        if (b == pb)
            return false;
    }
    return false;
}

bool canMeasureWater(int x, int y, int z)
{
    if (!z)
        return true;

    if (z > x + y)
        return false;

    if (z == x + y)
        return true;

    if (x == y)
        return z == x;

    if (z == x || z == y)
        return true;

    if (!(x & 1) && !(y & 1) && (z & 1))
        return false;

    if (!x || !y)
        return false;

    if (y > x)
    {
        y ^= x;
        x ^= y;
        y ^= x;
    }

    return cmw(x, y, z);
}
