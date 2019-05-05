// speed again !
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> r;
        r.resize(queries.size());
        int now = 0;
        int size = A.size();

        for (int i = 0; i < size; i ++)
        {
            if (!(A[i] & 1))
                now += A[i];
        }

        size = queries.size();
        for (int j = 0; j < size; j ++)
        {
            int i = queries[j][1];
            int v = queries[j][0];

            if (A[i] & 1)
            {
                if (v & 1)
                    now += A[i] + v;
            }
            else
            {
                if (v & 1)
                    now -= A[i];
                else
                    now += v;
            }
            A[i] += v;
            r[j] = now;
        }
        return r;
    }
};

/*
int* sumEvenAfterQueries(int* A, int ASize, int** queries, int queriesRowSize, int queriesColSize, int* returnSize) {
    *returnSize = 0;
    int* ret = malloc(sizeof(int) * queriesRowSize);

    int now = 0;
    for (int i = 0; i < ASize; i ++)
        if (!(A[i] & 1))
            now += A[i];
    for (int j = 0; j < queriesRowSize; j ++)
    {
        int i = queries[j][1];
        int v = queries[j][0];

        if (A[i] & 1)
        {
            if (v & 1)
                now += A[i] + v;
        }
        else
        {
            if (v & 1)
                now -= A[i];
            else
                now += v;
        }
        A[i] += v;
        ret[j] = now;
    }

    *returnSize = queriesRowSize;
    return ret;
}
*/
