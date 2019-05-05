// TODO do it again !!!!
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* need clear mind to do so :( */
char** removeComments(char** source, int sourceSize, int* returnSize)
{
    int rn = 0;
    bool in_comment = false;
    char** r = malloc(sizeof(char *) * sourceSize);

    int co_index = 0;
    int co_size = 80;
    char* co_line = NULL;
    bool copy_mode = false;

    for (int i = 0; i < sourceSize; i ++)
    {
        int t = 0;
        char* s = source[i];
        char c = s[t ++];
        bool none = true;

        while (c)
        {
            if (copy_mode)
                co_line[co_index ++] = c;

            if (c == '/')
            {
                none = false;

                if (in_comment)
                {
                    if (t != 1)
                    {
                        if (s[t - 2] == '*')
                        {
                            in_comment = false;

                            if (s[t])
                            {
                                if (!co_line)
                                {
                                    co_index = 0;
                                    co_line = malloc(80);
                                }
                                copy_mode = true;
                            }
                        }
                        else
                            none = true;
                    }
                }
                else
                {
                    // int // comment, skip others
                    if (s[t] == '/')
                    {
                        if (copy_mode)
                            co_line[-- co_index] = 0;
                        else if (t != 1)
                        {
                            none = true;
                            s[t - 1] = 0;
                        }
                        break;
                    }

                    // in /* comment
                    if (s[t] == '*')
                    {
                        in_comment = true;

                        // remove last '/'
                        if (copy_mode)
                            co_line[-- co_index] = 0;
                        else
                        {
                            if (!co_line)
                            {
                                co_index = 0;
                                co_line = malloc(80);
                            }

                            if (t > 1)
                            {
                                memcpy(co_line, s, t - 1);
                                co_index = t - 1;
                                co_line[co_index] = 0;
                            }
                        }

                        copy_mode = false;

                        // skip /*/
                        if (s[t + 1] == '/')
                            t += 2;
                    }
                    else
                        none = true;
                }
            }
            c = s[t ++];
        }

        if (!in_comment)
        {
            copy_mode = false;
            if (co_line && co_index)
            {
                co_line[co_index] = 0;
                r[rn ++] = co_line;
                co_line = 0;
            }
            else if (none)
                r[rn ++] = s;
        }
    }

    *returnSize = rn;
    return r;
}
