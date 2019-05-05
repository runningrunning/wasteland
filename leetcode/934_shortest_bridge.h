// simple ?

void _mark(int** n, int x, int y, int r, int c, int v)
{
    if (x >= 0 && x < r && y >= 0 && y < c && n[x][y] == 1)
    {
        n[x][y] = v;
        _mark(n, x, y - 1, r, c, v);
        _mark(n, x, y + 1, r, c, v);
        _mark(n, x + 1, y, r, c, v);
        _mark(n, x - 1, y, r, c, v);
    }
}

bool _outer(int ** n, int x, int y, int r, int c, int v, int nv)
{
    if (x >= 0 && x < r && y >= 0 && y < c && n[x][y] == v)
    {
        n[x][y] = nv;

        if (x)
        {
            if (n[x - 1][y] == 1)
                return true;
            else if (!n[x - 1][y])
                n[x - 1][y] = nv;
        }

        if (y)
        {
            if (n[x][y - 1] == 1)
                return true;
            else if (!n[x][y - 1])
                n[x][y - 1] = nv;
        }

        if (x < r - 1)
        {
            if (n[x + 1][y] == 1)
                return true;
            else if (!n[x + 1][y])
                n[x + 1][y] = nv;
        }

        if (y < c - 1)
        {
            if (n[x][y + 1] == 1)
                return true;
            else if (!n[x][y + 1])
                n[x][y + 1] = nv;
        }

        if (_outer(n, x - 1, y, r, c ,v, nv) || _outer(n, x + 1, y, r, c ,v, nv)
            || _outer(n, x, y - 1, r, c ,v, nv) || _outer(n, x, y + 1, r, c ,v, nv))
            return true;
    }

    return false;
}

int shortestBridge(int** A, int ARowSize, int *AColSizes)
{
    int r = ARowSize;
    int c = *AColSizes;

    bool found = false;
    int x, y;

    for (int i = 0; i < r; i ++)
    {
        for (int j = 0; j < c; j ++)
            if (A[i][j])
            {
                x = i;
                y = j;
                _mark(A, x, y, r, c, -1);
                found = true;
                break;
            }

        if (found)
            break;
    }


    int v = -1;
    int n = 2;

    while (!_outer(A, x, y, r, c, v, n))
    {
        v = n;
        n ++;
    }

    return n - 2;
}
