// TODO, must find the better way to do this !!
//
// 2D binary search ??
// brute-force, find better solution !!!!!!!!!!!!!!!!!!!
// stupid wrong algorithms !!!
// stupid wrong code algorithms ?
// how to handle this issue in array ?
// same with 644. maximum average subarray II ?
// 862. shortest subarray with sum at least K
// read the QS !!! return the maximum sum of rectangle

// k can be minus
int maxSumSubmatrix(int** matrix, int matrixRowSize, int matrixColSize, int k)
{
    int max = INT_MIN;
    bool has_minus = false;

    if (!matrixRowSize || !matrixColSize)
        return max;

    for (int i = 0; i < matrixRowSize; i ++)
    {
        int p = 0;
        for (int j = 0; j < matrixColSize; j ++)
        {
            if (matrix[i][j] < 0)
                has_minus = true;

            if (matrix[i][j] >= max && matrix[i][j] <= k)
                max = matrix[i][j];

            if (j)
                matrix[i][j] += p;

            p = matrix[i][j];

            if (i)
                matrix[i][j] += matrix[i - 1][j];

            if (matrix[i][j] >= max && matrix[i][j] <= k)
                max = matrix[i][j];
        }
    }

    if (max == k)
        return max;

    // start point
    for (int i = 0; i < matrixRowSize; i ++)
        for (int j = 0; j < matrixColSize; j ++)
        {
            if (!i && !j)
                continue;

            // end point
            for (int ii = i; ii < matrixRowSize; ii ++)
            {
                int li = matrix[ii][j];

                if (!has_minus)
                {
                    if (i - 1 < 0)
                        li -= matrix[ii][j - 1];
                    else if (j - 1 < 0)
                        li -= matrix[i - 1][j];
                    else
                    {
                        li -= matrix[ii][j - 1];
                        li -= matrix[i - 1][j];
                        li += matrix[i - 1][j - 1];
                    }

                    if (li > k)
                        break;
                }

                for (int jj = j; jj < matrixColSize; jj ++)
                {
                    if (ii == i && jj == j)
                        continue;

                    int x = matrix[ii][jj];

                    if (i - 1 < 0)
                        x -= matrix[ii][j - 1];
                    else if (j - 1 < 0)
                        x -= matrix[i - 1][jj];
                    else
                    {
                        x -= matrix[ii][j - 1];
                        x -= matrix[i - 1][jj];
                        x += matrix[i - 1][j - 1];
                    }

                    if (x >= max && x <= k)
                        max = x;

                    if (max == k)
                        return max;

                    if (x > k && !has_minus)
                        break;
                }
            }
        }

    return max;
}

/*
// wrong one
int maxSumSubmatrix(int** matrix, int matrixRowSize, int matrixColSize, int k)
{
    int max = 0;

    for (int i = 0; i < matrixRowSize; i ++)
    {
        int p = 0;
        for (int j = 0; j < matrixColSize; j ++)
        {
            if (j)
                matrix[i][j] += p;

            p = matrix[i][j];

            if (i)
                matrix[i][j] += matrix[i - 1][j];

            if (matrix[i][j] <= k)
            {
                int t = i <= j ? i : j;
                if (max < t)
                    max = t;
            }
        }
    }

    int c_max = matrixRowSize < matrixColSize ? matrixRowSize : matrixColSize;

    while (c_max > max)
    {
        for (int i = c_max - 1; i < matrixRowSize; i ++)
            for (int j = c_max - 1; j < matrixRowSize; j ++)
            {
                int x = i - c_max;
                int y = j - c_max;
                int c = matrix[i][j];

                if (x >= 0 || y >= 0)
                {
                    if (x < 0)
                        c -= matrix[i][y];
                    else if (y < 0)
                        c -= matrix[x][j];
                    else
                    {
                        c -= matrix[x][j];
                        c -= matrix[i][y];
                        c += matrix[x][y];
                    }
                }

                if (c <= k)
                    return c_max;
            }
        c_max --;
    }
    return max;
}
*/
