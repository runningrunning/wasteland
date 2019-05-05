// do 2 time/sfa/ easy way to fix this ?
// from left -> right, remove )
// from right -> left, remove (
// BFS and DFS
// MORE complicated about memory
// just write code 
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool rip(char*** r, int* ri, char* s, int* h, bool left)
{
    int l = strlen(s);
    int n = 0;
    int hi = 0;
    int i = 0;
    int c = 0;

    if (left)
    {
        for (i = 0; i < l; i ++)
        {
            c = s[i];
            if (c == ')')
            {
                n --;

                if (!i || s[i - 1] != ')')
                    h[hi ++] = i;

            }
            else if (c == '(')
                n ++;

            if (n == -1)
                break;
        }
    }
    else
    {
        for (i = l - 1; i >= 0; i --)
        {
            c = s[i];

            if (c == '(')
            {
                n --;

                if ((i == (l - 1)) || s[i + 1] != '(')
                    h[hi ++] = i;
            }
            else if (c == ')')
                n ++;

            if (n == -1)
                break;
        }
    }

    if ((n == -1) && hi)
    {
        (*r) = realloc(*r, sizeof(char*) * ((*ri) + hi));
        char** t = *r;
        int ti = *ri;

        for (int x = 0; x < hi; x ++)
        {
            int zi = 0;
            char* z = malloc(l + 1);

            for (int y = 0; y <= l; y ++)
                if (y != h[x])
                    z[zi ++] = s[y];
            z[zi] = 0;

            t[ti ++] = z;
        }

        (*ri) += hi;
        return false;
    }

    return true;
}

char** removeInvalidParentheses(char* s, int* returnSize)
{
    if (!s)
    {
        *returnSize = 0;
        return NULL;
    }

    int l = strlen(s);
    int ri = 0;
    char** r = NULL;
    int* h = malloc(sizeof(int) * (l + 1));

    char** r2 = NULL;
    int ri2 = 0;

    ri = 1;
    r = realloc(r, sizeof(char*) * 1);
    r[0] = strdup(s);

    bool left = true;

    while (true)
    {
        for (int i = 0; i < ri2; i ++)
            free(r2[i]);
        free(r2);

        r2 = NULL;
        ri2 = 0;

        bool ret = true;

        for (int i = 0; i < ri; i ++)
        {
            bool has = false;

            for (int j = 0; j < i; j ++)
                if (!strcmp(r[i], r[j]))
                {
                    has = true;
                    break;
                }

            if (has)
                continue;
            ret = rip(&r2, &ri2, r[i], h, left) && ret;
        }

        if (r2 && ri2)
        {
            char** t = r;
            int ti = ri;
            r = r2;
            ri = ri2;
            r2 = t;
            ri2 = ti;
        }

        if (ret)
        {
            if (left)
                left = false;
            else
            {
                if (!r2)
                {
                    r2 = r;
                    ri2 = ri;
                    r = NULL;
                    ri = 0;
                }
                break;
            }
        }
    }

    for (int i = 0; i < ri; i ++)
        free(r[i]);;
    free(r);

    ri = 0;

    for (int i = 0; i < ri2; i ++)
    {
        bool has = false;
        for (int j = 0; j < ri; j ++)
        {
            if (!strcmp(r2[i], r2[j]))
            {
                has = true;
                break;
            }
        }

        if (!has)
            r2[ri ++] = r2[i];
        else
        {
            free(r2[i]);
            r2[i] = NULL;
        }
    }

    *returnSize = ri;
    return r2;
}

