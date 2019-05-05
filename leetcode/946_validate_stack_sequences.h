bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize)
{
    int ui = 0;
    int oi = 0;

    int si = 0;
    char* b = calloc(sizeof(char), pushedSize + 1);
    int* stack = malloc(sizeof(int) * (pushedSize + 1));

    for (oi = 0; oi < poppedSize; oi ++)
    {
        int pop = popped[oi];

        while (pop != pushed[ui] && !b[pop] && ui < pushedSize)
        {
            stack[si ++] = pushed[ui];
            b[pushed[ui]] = 1;
            ui ++;
        }

        if (ui < pushedSize && pop == pushed[ui])
        {
            ui ++;
            continue;
        }

        if (stack[si - 1] != pop)
        {
            // printf("%d %d.\n", stack[si - 1], pop);
            return false;
        }
        si --;
        if (si < 0)
            return false;
    }
    // printf("ui %d oi %d.\n", oi, ui);
    return ui == pushedSize && oi == poppedSize;
}
