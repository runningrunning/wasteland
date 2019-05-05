// How to solve this with DP ?
int maximalSquare(char** x, int r, int c)
{
    int m = 0;

    for (int i = 0; i < r - m; i ++)
        for (int j = 0; j < c - m; j ++)
        {
            if (x[i][j] == '0')
                continue;

            //if ((j + m < c && x[i][j + m] == '0') || (i + m < r && x[i + m][j] == '0'))
            //    continue;

            int l = (r - i) < (c - j) ? (r - i) : (c - j);

            int y = 0;
            for (y = 0; y < l; y ++)
            {
                bool is = true;

                for (int o = 0; o <= y; o ++)
                    if (x[i + o][j + y] != '1' || x[i + y][j + o] != '1')
                    {
                        is = false;
                        break;
                    }

                if (!is)
                    break;
            }

            if (m < y)
                m = y;
        }

    return m * m;
}
