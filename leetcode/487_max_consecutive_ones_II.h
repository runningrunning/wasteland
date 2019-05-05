/* int findMaxConsecutiveOnes(int* nums, int numsSize) */
/* { */
/*     if (!nums || !numsSize) */
/*         return 0; */

/*     int last_0 = -1; */
/*     int max_1 = INT_MIN; */
/*     int cur_1 = 0; */

/*     for (int i = 0; i < numsSize; i ++) */
/*     { */
/*         // 1 */
/*         if (nums[i]) */
/*             cur_1 ++; */
/*         else */
/*         { */
/*             if (last_0 < 0) */
/*             { */
/*                 cur_1 ++; */
/*                 last_0 = i; */
/*             } */
/*             else */
/*             { */
/*                 cur_1 = i - last_0; */
/*             } */

/*             last_0 = i; */
/*         } */

/*         if (cur_1 > max_1) */
/*             max_1 = cur_1; */
/*     } */

/*     return max_1; */
/* } */

/*
  int findMaxConsecutiveOnes(int* nums, int numsSize)
  {
  if (!nums || !numsSize)
  return 0;

  int last_0 = -1;
  int cur_1 = 0;
  int max_1 = INT_MIN;

  int i = 0;
  for (i = 0; i < numsSize; i ++)
  {
  cur_1 ++;

  if (!nums[i])
  {
  last_0 = i ++;
  break;
  }
  }

  if (last_0 < 0)
  return cur_1;
  if (cur_1 > max_1)
  max_1 = cur_1;

  for (; i < numsSize; i ++)
  {
  // 1
  if (nums[i])
  cur_1 ++;
  else
  {
  cur_1 = i - last_0;
  last_0 = i;
  }

  if (cur_1 > max_1)
  max_1 = cur_1;
  }

  return max_1;
  }

  int findMaxConsecutiveOnes(int* nums, int numsSize)
  {
  if (!nums || !numsSize)
  return 0;

  int max_1 = INT_MIN;

  int id = 0;
  int in = 0;
  int n1[2] = {0};

  for (int i = 0; i < numsSize; i ++)
  {
  if (nums[i])
  id ++;
  else
  {
  n1[(in ++) % 2] = id;
  id = 0;

  if (max_1 < n1[0] + n1[1] + 1)
  max_1 = n1[0] + n1[1] + 1;
  }
  }
  n1[(in ++) % 2] = id;
  if (max_1 < n1[0] + n1[1] + 1)
  max_1 = n1[0] + n1[1] + 1;
  return max_1 > numsSize ? numsSize : max_1;
  }
*/
int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    if (!nums || !numsSize)
        return 0;

    int last_0 = -1;
    int max_1 = INT_MIN;
    int cur_1 = 0;

    for (int i = 0; i < numsSize; i ++)
    {
        cur_1 ++;

        if (!nums[i])
        {
            if (last_0 >= 0)
            {
                cur_1 --;

                if (cur_1 > max_1)
                    max_1 = cur_1;

                cur_1 = i - last_0;
            }

            last_0 = i;
        }

        /* // 1 */
        /* if (nums[i]) */
        /*     cur_1 ++; */
        /* else */
        /* { */
        /*     if (last_0 < 0) */
        /*         cur_1 ++; */
        /*     else */
        /*     { */
        /*     } */
        /*     last_0 = i; */
        /* } */

    }

    if (cur_1 > max_1)
        max_1 = cur_1;

    return max_1;
}
