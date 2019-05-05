bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (!nums || numsSize < 2 || !k)
        return false;

    if (numsSize > 128)
    {
        int min = nums[0] > nums[1] ? nums[1] : nums[0];
        int max = nums[0] > nums[1] ? nums[0] : nums[1];

        if (nums[0] == nums[1])
            return true;
        bool check = false;
        bool seq = nums[1] > nums[0];

        for(int i = 2; i < numsSize; i ++)
        {
            if (nums[i] == nums[i - 1])
                return true;
            if (seq != (nums[i] > nums[i - 1]))
               check = true;
           if (nums[i] > max)
               max = nums[i];
           else if (nums[i] < min)
              min = nums[i];
        }

        if ((numsSize > max - min + 1)&& (k >= numsSize - 1))
            return true;
        if (!check)
            return false;
    }

    if (k >= numsSize - 1)
        k = numsSize - 1;

    // Here, i still need to go through numsSize - 1
    for(int i = 0; i < numsSize - 1; i ++)
        for(int j = i + 1; j <= i + k && j < numsSize; j ++)
            if (nums[i] == nums[j])
                return true;
    return false;
}
