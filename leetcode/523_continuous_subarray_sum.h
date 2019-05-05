// TODO: do more time ~, read the questions
// non-negative can be 0, k is int, k and n can be 0 or negative
bool checkSubarraySum(int* nums, int numsSize, int _k)
{
    if (!nums || numsSize < 2)
        return false;

    _k = _k < 0 ? - _k : _k;

    if (_k == 0)
    {
        for (int i = 0; i < numsSize - 1; i++)
            if (!nums[i] && !nums[i + 1])
                return true;
        return false;
    }

    if (_k == 1)
        return true;

    long k = _k;
    long ok = _k;

    long last_i = 0;
    long last_a = 0;

    while(true)
    {
        int s = 0;
        int i = last_i;
        long a = last_a;
        for (; i < numsSize; i ++)
        {
            if (a >= k)
                break;
            a += nums[i];
        }

        // size must > 2
        if (a == k && i > 1)
            return true;

        if (a < k && i == numsSize)
            return false;

        last_i = i;
        last_a = a;

        while (true)
        {
            while (a > k)
                a -= nums[s ++];

            while (a < k && i < numsSize)
                a += nums[i ++];

            if (a == k)
            {
                if (i - s > 1)
                    return true;
                else
                    a -= nums[s ++];
            }

            if (i == numsSize)
                break;
        }
        k += ok;
    }

    return false;
}

/*
  bool checkSubarraySum(int* nums, int numsSize, int k)
  {
  if (k == 1)
  return true;

  for (int i = 2; i < numsSize; i ++)
  {
  int a = 0;
  int j = 0;
  for (j = 0; j < i; j ++)
  a += nums[j];

  if (!(a % k))
  return true;

  for (; j < numsSize; j ++)
  {
  a += nums[j] - nums[j - i];
  if (!(a % k))
  return true;
  }
  }
  return false;
  }
*/
