/* just like 3 sums ? */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSumOfThreeSubarrays(int* nums, int numsSize, int K, int* returnSize)
{
    int* s = malloc(sizeof(int) * numsSize);
    s[0] = nums[0];

    for (int i = 1; i < numsSize; i ++)
        s[i] = s[i - 1] + nums[i];

    int max = INT_MIN;
    int* i3 = malloc(sizeof(int) * 3);

    int* is = calloc(sizeof(int), numsSize);
    int* vs = malloc(sizeof(int) * numsSize);
    int* ls = calloc(sizeof(int), numsSize);
    int* lvs = malloc(sizeof(int) * numsSize);

    int pre_2 = -1;
    int pre_2v;

    for (int i = 0; i <= numsSize - 3 * K; i ++)
    {
        int s1 = s[i + K - 1] - (i ? s[i - 1] : 0);

        int m2 = INT_MIN;
        int m2_1;

        if (pre_2 >= i + K)
        {
            is[i] = pre_2;
            vs[i] = pre_2v;
        }

        if (is[i])
        {
            m2_1 = is[i];
            m2 = vs[i];
        }
        else
        {
            int pre_3 = -1;
            int pre_3v;

            for (int j = i + K; j <= numsSize - 2 * K; j ++)
            {
                int s2 = s[j + K  - 1] - s[j - 1];

                int m3 = INT_MIN;
                int m3_1;

                if (pre_3 >= j + K)
                {
                    ls[j] = pre_3;
                    lvs[j] = pre_3v;
                }

                if (ls[j])
                {
                    m3_1 = ls[j];
                    m3 = lvs[j];
                }
                else
                {
                    for (int k = j + K; k <= numsSize - K; k ++)
                    {
                        if (m3 < s[k + K - 1] - s[k - 1])
                        {
                            m3_1 = k;
                            m3 = s[k + K - 1] - s[k - 1];
                        }
                    }

                    ls[j] = m3_1;
                    lvs[j] = m3;
                }

                pre_3 = m3_1;
                pre_3v = m3;

                if (s2 + m3 > m2)
                {
                    m2_1 = j;
                    m2 = s2 + m3;
                }
            }

            is[i] = m2_1;
            vs[i] = m2;
        }

        pre_2 = m2_1;
        pre_2v = m2;

        if (s1 + m2 > max)
        {
            max = s1 + m2;
            i3[0] = i;
            i3[1] = is[i];
            i3[2] = ls[is[i]];
        }
    }
    *returnSize = 3;
    return i3;
}
