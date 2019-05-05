// be careful about the qsort, the comp is base one the pointer of the element
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct{
    int s;
    char* l;
} _Log;

int comp(const void* e1, const void* e2)
{
    // printf("111\n");
    _Log* l1 = *((_Log**) e1);
    _Log* l2 = *((_Log**) e2);
    // printf("%p %p %p %p.\n", l1, l2, e1, e2);
    return strcmp(l1->l + l1->s, l2->l + l2->s);
}

char** reorderLogFiles(char** logs, int logsSize, int* returnSize)
{
    char** ns = malloc(sizeof(char*) * logsSize);
    _Log**  ls = malloc(sizeof(_Log*) * logsSize);

    int s = 0;
    int e = logsSize - 1;

    for (int i = e; i >= 0; i --)
    {
        char* l = logs[i];
        int li = 0;
        bool has = false;
        while (!has || l[li] == ' ')
        {
            if (l[li] == ' ')
                has = true;
            li ++;
        }

        if (l[li] >= '0' && l[li] <= '9')
            ns[e --] = l;
        else
        {
            _Log* t = malloc(sizeof(_Log));
            t->l = l;
            t->s = li;
            ls[s ++] = t;
            // printf("%s %d %p.\n", l, li, ls[s - 1]);
        }
    }
    /* for (int i = 0; i < s; i ++) */
    /*     printf("%p.\n", ls[i]); */

    /* printf("s is %d.\n", s); */
    if (s)
        qsort(ls, s, sizeof(_Log*), comp);

    for (int i = 0; i < s; i ++)
        ns[i] = ls[i]->l;

    *returnSize = logsSize;
    return ns;
}
