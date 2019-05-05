bool containsDuplicate(int* nums, int numsSize) {
    if (!nums || !numsSize)
        return false;

    if (numsSize > 1024)
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
        if (numsSize > max - min + 1)
            return true;
        if (!check)
            return false;
    }

    for(int i = 0; i < numsSize; i ++)
        for(int j = i + 1; j < numsSize; j ++)
            if (nums[i] == nums[j])
                return true;
    return false;
}
