bool circularArrayLoop(int* nums, int numsSize)
{
    if (numsSize < 2)
        return false;

    for (int i = 0; i < numsSize; i ++)
    {
        if (!nums[i])
            continue;

        bool forward = nums[i] > 0;
        int ss = i;
        int ds = i;

        bool found = false;

        do {
            ss = (ss + nums[ss]) % numsSize;
            ds = (ds + nums[ds]) % numsSize;

            ss = ss + (ss < 0 ? numsSize : 0);
            ds = ds + (ds < 0 ? numsSize : 0);


            if (!nums[ss] || !nums[ds])
                break;

            if (forward != nums[ss] > 0 || forward != nums[ds] > 0)
                break;

            ds = (ds + nums[ds]) % numsSize;
            ds = ds + (ds < 0 ? numsSize : 0);

            if (!nums[ds] || forward != nums[ds] > 0)
                break;

            if (ds == ss)
            {
                found = true;
                break;
            }

        } while (true);


        if (found)
        {
            ds = (ds + nums[ds]) % numsSize;
            ds = ds + (ds < 0 ? numsSize : 0);

            if (ds != ss)
                return true;
        }
        else
        {
            ss = i;
            do
            {
                int ns = (ss + nums[ss]) % numsSize;
                nums[ss] = 0;
                ss = ns;
            } while (nums[ss] && forward == nums[ss] > 0);
        }
    }
    return false;
}
