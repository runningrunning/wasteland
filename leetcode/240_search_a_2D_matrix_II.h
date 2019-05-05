// 2D binary search tree method !! BST
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{

    for (int i = 0; i < matrixRowSize; i ++)
    {
        for (int j = 0; j < matrixColSize; j ++)
        {
            if (matrix[i][j] == target)
                return true;
            if (matrix[i][j] > target)
                break;
        }
    }

    /*
    if (!matrix || !matrixRowSize || !matrixColSize)
        return false;

    int i = matrixRowSize - 1;
    int j = 0;

    while (i >= 0 && j < matrixColSize)
    {
        int t = matrix[i][j];
        if (t == target)
            return true;
        if (t < target)
            j ++;
        else
            i --;
    }
    */
    return false;
}

/*
// STUPID WRONG ALGORITHM
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{
    if (!matrix || !matrixRowSize || !matrixColSize)
        return false;

    int* t;

    // find row
    int s = 0;
    int e = matrixRowSize - 1;
    int r = matrixColSize - 1;

    while (s < e)
    {
        int m = (s + e) / 2;
        t = matrix[m];
        if (t[r] < target)
            s = m + 1;
        else
            e = m;
    }
    e = matrixRowSize - 1;

    // find col
    int l = 0;
    t = matrix[e];

    while (l < r)
    {
        int m = (l + r) / 2;
        if (t[m] < target)
            l = m + 1;
        else
            r = m;
    }
    r = matrixColSize - 1;

    if (matrix[s][l] == target)
        return true;

    int ol = l;

    while (s <= e && matrix[s][0] <= target)
    {
        int* t = matrix[s];

        while (l < r)
        {
            int m = (l + r) / 2;
            if (t[m] < target)
                l = m + 1;
            else
                r = m;
        }

        if (t[l] == target)
            return true;

        r = l;
        l = ol;
        s ++;
    }

    return false;
}
*/
