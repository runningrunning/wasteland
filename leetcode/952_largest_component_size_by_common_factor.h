// TODO try to solve this with graphs ?
// better solution or simple solution ?
// code optimize !!!
// stupid corner error !!!!
// clear mind !!!!
// same as 947 most stones removed with same row or column ???
// find a better structure for this task ?
// only check primer number ???
// how to optimize the code
// simple union find here ??
// how to optimize this code to orig index?
bool lc_is_prime(int x, int* p, int ps)
{
    for (int i = 0; i < ps; i ++)
    {
        if (p[i] * p[i] > x)
            return true;

        if (!(x % p[i]))
            return false;
    }
    return true;
}

int largestComponentSize(int* A, int ASize)
{
    int max = A[0];
    for (int i = 0; i < ASize; i ++)
        if (A[i] > max)
            max = A[i];

    int pi = 0;
    int* p = NULL;

    short* rev = malloc(sizeof(short) * (max + 1));
    rev[0] = rev[1] = 0;
    for (int i = 2; i <= max; i ++)
    {
        rev[i] = 0;
        if (lc_is_prime(i, p, pi))
        {
            p = realloc(p, sizeof(int) * (pi + 1));
            p[pi ++] = i;
            rev[i] = pi;
        }
    }

    max = 0;
    int p_id = 1;

    short* id = calloc(sizeof(short), (pi + 1));
    // ids should add 2 as 1 is also an prime here !!!!!!
    short** id_nums = calloc(sizeof(short*), (pi + 2)); // 0 is num, others are ids
    short* id_sizes = malloc(sizeof(short) * (pi + 2));

    // temp
    char* bits = calloc(sizeof(char), (pi + 1));
    short* p_st = malloc(sizeof(short) * (pi + 1));
    short* id_st = malloc(sizeof(short) * (pi + 1));
    for (int i = 0; i < ASize; i ++)
    {
        int x = A[i];
        int p_i = 0;
        int id_i = 0;

        // math part
        for (int j = 0; j < pi; j ++)
        {
            if (!(x % p[j]))
            {
                p_st[p_i ++] = j;
                if (id[j] && !bits[id[j]])
                {
                    bits[id[j]] = 1;
                    id_st[id_i ++] = id[j];
                }

                while (!(x % p[j]))
                    x /= p[j];
            }

            if (rev[x])
            {
                int y = rev[x] - 1;
                p_st[p_i ++] = y;
                if (id[y] && !bits[id[y]])
                {
                    bits[id[y]] = 1;
                    id_st[id_i ++] = id[y];
                }
                break;
            }

            if (p[j] * p[j] > x)
                break;
        }
        // outsh(p_st, p_i);

        int x_id;

        if (id_i)
        {
            x_id = id_st[0];
            for (int j = 1; j < id_i; j ++)
            {
                int in = id_nums[x_id][0] + 1;
                int y_id = id_st[j];
                id_nums[x_id] = realloc(id_nums[x_id], sizeof(short) * (id_nums[x_id][0] + id_nums[y_id][0] + 1));

                for (int k = 0; k < id_nums[y_id][0]; k ++)
                {
                    int z = id_nums[y_id][1 + k];
                    id[z] = x_id;
                    id_nums[x_id][in ++] = z;
                }
                id_nums[x_id][0] += id_nums[y_id][0];
                id_sizes[x_id] += id_sizes[y_id];
            }

            for (int j = 0; j < p_i; j ++)
            {
                if (!id[p_st[j]])
                {
                    id_nums[x_id] = realloc(id_nums[x_id], sizeof(short) * (id_nums[x_id][0] + 2));
                    id_nums[x_id][id_nums[x_id][0] + 1] = p_st[j];
                    id_nums[x_id][0] += 1;
                }
                id[p_st[j]] = x_id;
            }
            id_sizes[x_id] ++;
        }
        else
        {
            x_id = p_id ++;
            id_nums[x_id] = malloc(sizeof(short) * (p_i + 1));
            id_nums[x_id][0] = p_i;
            for (int j = 0; j < p_i; j ++)
            {
                id[p_st[j]] = x_id;
                id_nums[x_id][j + 1] = p_st[j];
            }
            id_sizes[x_id] = 1;
        }

        if (id_sizes[x_id]> max)
            max = id_sizes[x_id];

        // clear
        for (int j = 0; j < id_i; j ++)
            bits[id_st[j]] = 0;

        /* outsh(id, pi); */
        /* outsh(id_nums[x_id], id_nums[x_id][0] + 1); */
    }
    free(rev);
    return max;
}
