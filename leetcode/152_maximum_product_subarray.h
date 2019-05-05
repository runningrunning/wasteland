int maxProduct(int* nums, int numsSize)
{
    if (!nums || !numsSize)
        return 0;

    int pp = INT_MIN; // + product
    int mp = INT_MIN; // - product

    int f_mp = 1; // first with minus
    int l_m = 1; // last minus

    bool use_cmp = false;
    bool use_cpp = false;
    int c_pp = 1;
    int c_mp = 1;

    bool has_zero = false;
    bool has_minus = false;

    for(int i = 0; i <= numsSize; i ++)
    {
        if (i == numsSize || nums[i] == 0)
        {
            if (i < numsSize)
                has_zero = true;

            if (use_cpp && pp < c_pp)
                pp = c_pp;

            if (use_cmp && mp < c_mp)
                mp = c_mp;


            if (has_minus)
            {
                int t_f = c_mp / f_mp;
                int t_l = c_mp / l_m / c_pp;
                int t_m = t_f > t_l ? t_f : t_l;
                if (mp < t_m)
                    mp = t_m;
            }

            if (mp < 0 && has_zero)
                mp = 0;

            use_cmp = false;
            use_cpp = false;
            has_minus = false;
            f_mp = l_m = c_pp = c_mp = 1;
        }
        else
        {
            use_cmp = true;

            if (nums[i] > 0)
            {
                use_cpp = true;
                c_pp *= nums[i];
            }
            else
            {
                if (c_mp > 0)
                {
                    if (has_minus)
                        l_m = nums[i];
                    else
                        f_mp = c_pp * nums[i];
                }
                else
                    has_minus = true;

                if (use_cpp && pp < c_pp)
                    pp = c_pp;

                use_cpp = false;
                c_pp = 1;
            }
            c_mp *= nums[i];
        }
    }
    return pp > mp ? pp : mp;
}
