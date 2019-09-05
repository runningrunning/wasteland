// dp
// RECURSIVE VERSION IS FAR BETTER THAN NONE RECURSIVE VERSION !!!
// same as 1130 ?
int _mhs(int** b, int s, int e, int** dp, int wh)
{
    if (dp[s][e])
        return dp[s][e];
    int cur = 0;
    int cur_h = b[s][1];
    int min = INT_MAX;
    for (int i = s; i <= e; i ++)
    {
        cur += b[i][0];
        if (cur > wh)
            break;
        if (cur_h < b[i][1])
        {
            cur_h = b[i][1];
            dp[s][i] = cur_h;
        }
        int t = cur_h + (i != e ? _mhs(b, i + 1, e, dp, wh) : 0);
        if (t < min)
            min = t;
    }
    dp[s][e] = min;
    return dp[s][e];
}

// recursive version
int minHeightShelves(int** books, int booksSize, int* booksColSize, int shelf_width)
{
    int** dp = malloc(sizeof(int*) * booksSize);
    for (int i = 0; i < booksSize; i ++)
        dp[i] = calloc(sizeof(int), booksSize);
    _mhs(books, 0, booksSize - 1, dp, shelf_width);
    return dp[0][booksSize - 1];
}


// no recursive version ??
int minHeightShelves2(int** books, int booksSize, int* booksColSize, int shelf_width)
{
    int** dp = malloc(sizeof(int*) * booksSize);
    int* ws = malloc(sizeof(int) * booksSize);

    for (int i = 0; i < booksSize; i ++)
    {
        dp[i] = calloc(sizeof(int), booksSize);
        ws[i] = books[i][0] + (i ? ws[i - 1] : 0);
    }

    for (int i = 0; i < booksSize; i ++)
        for (int j = 0; j < booksSize - i; j ++)
        {
            if (i == 0)
                dp[j][j] = books[j][1];
            else
            {
                int w = ws[j + i] - (j ? ws[j - 1] : 0);

                if (w <= shelf_width)
                {
                    int cur_h = books[j][1];
                    for (int k = 0; k <= i; k ++)
                    {
                        if (cur_h < books[j + k][1])
                            cur_h = books[j + k][1];
                    }
                    dp[j][j + i] = cur_h;
                }
                else
                {
                    int cur = 0;
                    int cur_h = books[j][1];
                    int min = INT_MAX;

                    for (int k = 0; k <= i && k <= shelf_width; k ++)
                    {
                        cur += books[j + k][0];
                        if (cur > shelf_width)
                            break;
                        if (cur_h < books[j + k][1])
                            cur_h = books[j + k][1];

                        int t = cur_h + (k != i ? dp[j + k + 1][j + i] : 0);

                        if (t < min)
                            min = t;
                    }
                    dp[j][j + i] = min;
                }
            }
        }
    return dp[0][booksSize - 1];
}
