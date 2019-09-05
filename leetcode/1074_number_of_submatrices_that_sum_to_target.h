// 2D version for subarray sum 
// TODO better solution (Similar with 363)
// brute force version find start point and end point
// simply code optimization ?
// O(n^4) to O(n^3) ???
// hash for optimization
// use hash to optimize here !
int numSubmatrixSumTarget(int** m, int r, int* cs, int t)
{
    int c = cs[0];

    for (int i = 0; i < r; i ++)
        for (int j = 1; j < c; j ++)
            m[i][j] += m[i][j - 1];

    int num = 0;
    int cur[512];

    for (int i = 0; i < c; i ++)
        for (int j = i; j < c; j ++)
        {
            cur[0] = m[0][j] - (i ? m[0][i - 1] : 0);
            for (int k = 0; k < r; k ++)
            {
                cur[k] = m[k][j] - (i ? m[k][i - 1] : 0) + (k ? cur[k - 1] : 0);
                num += cur[k] == t ? 1 : 0;
                // hash optimize here ???
                for (int l = 0; l < k; l ++)
                    if (cur[k] - cur[l] == t)
                        num ++;
            }
        }
    return num;
}

/*
int numSubmatrixSumTarget(int** m, int r, int* cs, int t)
{
    int c = cs[0];
    for (int i = 0; i < r; i ++)
        for (int j = 0; j < c; j ++)
        {
            if (i == 0)
                m[i][j] += j ? m[i][j - 1] : 0;
            else if (j == 0)
                m[i][j] += i ? m[i - 1][j] : 0;
            else
                m[i][j] += m[i - 1][j] + m[i][j - 1] - m[i - 1][j -1];
        }

    int num = 0;
    for (int i = 0; i < r; i ++)
        for (int j = 0; j < c; j ++)
            for (int ii = i; ii < r; ii ++)
                for (int jj = j; jj < c; jj ++)
                {
                    if (i == 0)
                        num += t == (m[ii][jj] - (j ? m[ii][j - 1] : 0)) ? 1: 0;
                    else if (j == 0)
                        num += t == (m[ii][jj] - (i ? m[i - 1][jj] : 0)) ? 1 : 0;
                    else
                        num += t == (m[ii][jj] + m[i - 1][j - 1] - m[ii][j - 1] - m[i - 1][jj]) ? 1 : 0;
                }
    return num;
}
*/
