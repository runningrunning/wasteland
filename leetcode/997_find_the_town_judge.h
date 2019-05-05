class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        // int findJudge(int N, int** trust, int trustRowSize, int trustColSize)
        // {
        int* ts = calloc(sizeof(int), (N + 1));
        for (int i = 0; i < trust.size(); i ++)
        {
            int t1 = trust[i][0];
            int t2 = trust[i][1];
            ts[t2] ++;
            ts[t1] |= 0x10000;
        }

        int k = -1;
        for (int i = 1; i <= N; i ++)
            if (ts[i] == N - 1)
            {
                if (k == -1)
                    k = i;
                else
                    return -1;
            }
        return k;
        //}
    }
};

