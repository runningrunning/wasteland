/* Binary Search's corner case and ++ -- t and start and end compare. */
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{
    int** m = matrix;
    int r = matrixRowSize;
    int c = matrixColSize;

    if (r == 0 || c == 0)
        return false;

    int sr = 0;
    int er = r - 1;

    int sc = 0;
    int ec = c - 1;

    while(1)
    {
        if (sr != er)
        {
            int t = (sr + er) >> 1;

            if (m[t][ec] == target)
                return true;

            if (m[t][ec] > target)
                er = t;
            else
                sr = t + 1;
        }
        else
        {
            int t = (sc + ec) >> 1;
            if (m[sr][t] == target)
            {
                return true;
            }

            if (m[sr][t] > target)
                ec = t - 1;
            else
                sc = t + 1;

            if (sc > ec)
                return false;
        }
    }
}
