bool br_search(int* nums, int s, int e, int target)
{
    if (s > e)
        return false;

    if (s == e)
        return nums[s] == target;

    int m = (s + e) / 2;

    if (target == nums[s] || target == nums[e] || target == nums[m])
        return true;

    if (target > nums[s])
    {
        if (nums[s] == nums[m])
        {
            if (nums[m] == nums[e])
            {
                return br_search(nums, s + 1, m - 1, target)
                    || br_search(nums, m + 1, e - 1, target);
            }
            else
            {
                return br_search(nums, m + 1, e - 1, target);
            }
        }

        if (target < nums[m] || nums[s] > nums[m])
            return br_search(nums, s + 1, m - 1, target);
        else
            return br_search(nums, m + 1, e - 1, target);
    }

    if (target < nums[e])
    {
        if (nums[m] == nums[e])
        {
            if (nums[m] = nums[s])
            {
                return br_search(nums, s + 1, m - 1, target)
                    || br_search(nums, m + 1, e - 1, target);
            }
            else
            {
                return br_search(nums, s + 1, m - 1, target);
            }
        }

        if (target > nums[m] || nums[e] < nums[m])
            return br_search(nums, m + 1, e - 1, target);
        else
            return br_search(nums, s + 1, m - 1, target);
    }

    return false;
}

bool search(int* nums, int numsSize, int target)
{
    return br_search(nums, 0, numsSize - 1, target);
}
