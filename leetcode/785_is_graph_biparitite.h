// divide into different part ?
// better solutions?
bool isBipartite(int** graph, int graphRowSize, int *graphColSizes)
{
    char* a = calloc(sizeof(char), graphRowSize);
    char* b = calloc(sizeof(char), graphRowSize);

    int si = 0;
    int* stack = malloc(sizeof(int) * 2048);
    stack[si ++] = 1;

    while (true)
    {
        if (!si)
        {
            for (int i = 0; i < graphRowSize; i ++)
                if (!a[i] && !b[i])
                {
                    stack[si ++] = i + 1;
                    break;
                }
        }

        if (!si)
            break;

        int x = stack[-- si] - 1;

        if (a[x] && b[x])
            return false;
        else if (!a[x] && !b[x])
            a[x] = 1;

        if (a[x])
        {
            for (int i = 0; i < graphColSizes[x]; i ++)
            {
                int y = graph[x][i];
                if (a[y]) return false;
                if (!b[y])
                {
                    b[y] = 1;
                    if (!((si + 1) % 2048))
                        stack = realloc(stack, sizeof(int) * (si + 2049));
                    stack[si ++] = y + 1;
                }
            }
        }
        else
        {
            for (int i = 0; i < graphColSizes[x]; i ++)
            {
                int y = graph[x][i];
                if (b[y]) return false;
                if (!a[y])
                {
                    a[y] = 1;
                    if (!((si + 1) % 2048))
                        stack = realloc(stack, sizeof(int) * (si + 2049));
                    stack[si ++] = y + 1;
                }
            }
        }
    }

    return true;
}
