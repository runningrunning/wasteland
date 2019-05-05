/* stupid, not need to be succeed  !!!! */
/* 1, 0, 1, 0 is 4, not 2 ! */

/*
// C++ map version !
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> sums({{0, 1}});
        int max = 0;

        int sum = 50000;
        for (auto i = 0; i < nums.size(); i++)
        {
            sum += nums[i] ? 1 : -1;

            if (sum == 50000)
            {
                if (max < i + 1)
                    max = i + 1;
            }

            if (!sums[sum])
                sums[sum] = i + 1;
            else
            {
                if (max < i - sums[sum ] + 1)
                    max = i - sums[sum ] + 1;
            }
        }
        return max;
    }
};
*/

int findMaxLength(int* nums, int numsSize)
{
    int max = 0;
    int sum = 0;
    const int MINUS = 0xFFFF;
    const int PLUS = 0xFFFF << 16;
    for (int i = 0; i < numsSize; i ++)
    {
        sum += nums[i] ? 1 : -1;

        nums[i] = 0;

        if (!sum)
        {
            if (max < i + 1)
                max = i + 1;
        }
        else
        {
            int in = abs(sum) - 1;
            int mask = sum < 0 ? MINUS : PLUS;

            mask &= nums[in];

            if (!mask)
                nums[in] |= sum < 0 ? (i + 1): ((i + 1) << 16);
            else
            {
                mask = (unsigned short)(sum < 0 ? (mask & 0xFFFF) : (mask >> 16));
                if (max < i - mask + 1)
                    max = i - mask + 1;
            }
        }
    }
    return max;
}
