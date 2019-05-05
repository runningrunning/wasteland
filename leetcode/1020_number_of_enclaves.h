class Solution {
    void _vm(vector<vector<int>>& A, int i, int j, int x, int y)
    {
        A[i][j] = 2;
        if (i && A[i - 1][j] == 1)
            _vm(A, i - 1, j, x, y);
        if (j && A[i][j - 1] == 1)
            _vm(A, i, j - 1, x, y);
        if (i + 1 != x && A[i + 1][j] == 1)
            _vm(A, i + 1, j, x, y);
        if (j + 1 != y && A[i][j + 1] == 1)
            _vm(A, i, j + 1, x, y);
    }

 public:
    int numEnclaves(vector<vector<int>>& A) {
        int x = A.size();
        if (!x)
            return 0;
        int y = A[0].size();
        if (!y)
            return 0;

        for (int i = 0; i < x; i ++)
        {
            if (A[i][0] == 1)
                _vm(A, i, 0, x, y);

            if (A[i][y - 1] == 1)
                _vm(A, i, y - 1, x, y);
        }

        for (int i = 0; i < y; i ++)
        {
            if (A[0][i] == 1)
                _vm(A, 0, i, x, y);

            if (A[x - 1][i] == 1)
                _vm(A, x - 1, i, x, y);
        }

        int num = 0;
        for (int i = 0; i < x; i ++)
            for (int j = 0; j < y; j ++)
                if (A[i][j] == 1)
                    num ++;
        return num;
    }

};
