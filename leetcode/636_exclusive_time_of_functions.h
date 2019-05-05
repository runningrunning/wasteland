/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exclusiveTime(int n, char** logs, int logsSize, int* returnSize)
{
    *returnSize = 0;
    if (!n || !logs || !logsSize)
        return NULL;

    int* r = malloc(sizeof(int) * n);
    memset(r, 0, sizeof(int) * n);

    int last_id = -1;
    int* st = malloc(sizeof(int) * (logsSize / 2 + 1));
    int last_t = -1;

    for (int i = 0; i < logsSize; i ++)
    {
        char* l = logs[i];

        int j = 0;
        char c = l[j ++];
        int ti = 0;
        int t[2] = {0};

        bool start = false;

        while (c)
        {
            if (c != ':')
                t[ti] = t[ti] * 10 + c - '0';
            else
            {
                if (l[j] == 's')
                {
                    start = true;
                    j += 6;
                }
                else
                    j += 4;

                ti ++;
            }
            c = l[j ++];
        }

        if (start)
        {
            if (last_id != -1)
            {
                r[st[last_id]] += t[1] - 1 - last_t + 1;
                st[++ last_id] = t[0];
            }
            else
            {
                last_id = 0;
                st[last_id] = t[0];
            }
            last_t = t[1];
        }
        else
        {
            r[t[0]] += t[1] - last_t + 1;
            last_id --;
            last_t = t[1] + 1;
        }
    }

    *returnSize = n;
    return r;
}
