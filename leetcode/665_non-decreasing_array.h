// int m[] = {3, 4, 2, 3}
bool checkPossibility(int* nums, int numsSize)
{
    if (!nums)
        return false;

    bool found = false;
    for (int i = 0; i < numsSize - 1; i ++)
    {
        if (nums[i] > nums[i + 1])
        {
            if (found)
                return false;
            found = true;

            if (!i || i == numsSize - 2)
                continue;

            // Can only modify once, so compare pre and after.
            if (nums[i - 1] > nums[i + 1] && nums[i + 2] < nums[i])
                return false;
        }
    }
    return true;
}
