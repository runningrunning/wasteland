/*
int trap(int* height, int heightSize) {

    int cl = 0;
    int l_max = 0;
    for(int i = 0; i < heightSize; i ++)
        if (l_max < height[i])
            l_max = height[i];

    int all = 0;
    int* w = malloc(sizeof(int) * (l_max + 1));
    memset(w, 0, sizeof(int) * (l_max + 1));

    for(int i = 0; i < heightSize; i ++)
    {
        for(int j = 1; j <= height[i]; j ++)
        {
            if (w[j])
                all += i - w[j];
            w[j] = i + 1;
        }
        out(w, l_max + 1);
        if (cl < height[i])
            cl = height[i];
    }
    return all;
}
*/

int trap(int* height, int heightSize)
{
    int i = 0;
    int j = heightSize - 1;


    int all = 0;
    int all_block = 0;

    if (!height[i])
        i ++;
    if (!height[j])
        j --;

    int cl = 0;

    int all_b = 0;
    for(int i = 0; i < heightSize; i ++)
        all_b += height[i];
    for (;i <= j;)
    {
        if (height[i] > height[j])
        {
            while(height[i] > height[j])
            {
                if (height[j] > cl)
                {
                    all += (j - i + 1) * (height[j] - cl);
                    cl = height[j];
                }
                all_block += height[j];
                j --;
            }
        }

        if (height[j] > height[i])
        {
            while (height[j] > height[i])
            {
                if (height[i] > cl)
                {
                    all += (j - i + 1) * (height[i] - cl);
                    cl = height[i];
                }
                all_block += height[i];
                i ++;
            }
        }

        if (height[i] == height[j])
        {
            if (height[i] > cl)
            {
                all += (j - i + 1) * (height[i] - cl);
                cl = height[i];
            }
            all_block += height[i];
            if (i!= j)
                all_block += height[j];
            i ++;
            j --;
        }
    }

    printf("all is %d block %d..\n", all, all_block);
    return all - all_b;
}
