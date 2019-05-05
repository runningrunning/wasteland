void rotate(int* nums, int numsSize, int k)
{
    if (!nums || !(k % numsSize))
        return;
    k = k % numsSize;
    int ns = numsSize;

    // common divider
    int t = 0;
    int a = ns;
    int b = k;

    while(a % b)
    {
        t = a % b;
        a = b;
        b = t;
    }

    for(int j = 0; j < b; j ++)
    {
        int need = j;
        int i = need;
        int n = need;
        t = nums[need];
        do {
            n = (ns + i - k) % ns;
            nums[i] = n == need ? t : nums[n];
            i = n;
        } while(need != n);
    }
}
