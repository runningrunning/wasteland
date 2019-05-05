bool isValidSerialization(char* preorder)
{
    int si = 0;
    int stacks[1024];

    if (!preorder || !preorder[0])
        return false;

    if (preorder[0] == '#')
        return !preorder[1];

    int ci = 0;
    int c = preorder[ci];
    while (c)
    {
        if (c == '#')
        {
            if (stacks[si - 1] > 0)
                stacks[si - 1] = -1;
            else
            {
                while (si && stacks[si - 1] < 0)
                    si --;

                if (si)
                    stacks[si - 1] = -1;
            }

            c = preorder[++ ci];

            if (si == 0)
                return !c;
        }
        else
        {
            do
            {
                c = preorder[++ ci];
                if (!c)
                    break;
            } while (c != ',');
            /* we don't care about what's read as long as it's int */
            stacks[si ++] = 1;
        }

        if (c == ',')
            c = preorder[++ ci];
    }
    return si == 0;
}
