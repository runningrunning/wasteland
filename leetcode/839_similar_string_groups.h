typedef struct _Node
{
    struct _Node* next;
    int start;
    int last;
} Node;

Node* cNode()
{
    Node* n = malloc(sizeof(Node));
    n->next = NULL;
    n->start = 0;
    n->last = 0;
    return n;
}

bool _is_sim(char* a, char* b)
{
    int i = 0;
    int c = 0;
    while (a[i])
    {
        if (a[i] != b[i])
        {
            c ++;
            if (c > 2)
                return false;
        }
        i ++;
    }
    return true;
}

int numSimilarGroups(char** A, int ASize)
{
    if (!A || !ASize)
        return 0;

    if (strlen(A[0]) < 2)
        return ASize;

    int* ns = malloc(sizeof(int) * ASize);
    ns[0] = -1;

    int num = 1;
    Node* r = cNode();

    for (int i = 1; i < ASize; i ++)
    {
        char* c = A[i];
        ns[i] = -1;

        Node** p = &r;
        Node* f = NULL;
        while (*p)
        {
            Node* h = *p;
            int x = h->start;
            bool del = false;
            do {
                if (_is_sim(c, A[x]))
                {
                    if (!f)
                    {
                        f = h;
                        ns[f->last] = i;
                        f->last = i;
                    }
                    else
                    {
                        *p = h->next;
                        ns[f->last] = h->start;
                        f->last = h->last;
                        free(h);
                        h = NULL;
                        num --;
                    }
                    break;
                }
                x = ns[x];
            } while (x != -1);

            if (h)
                p = &(h->next);
        }

        if (!f)
        {
            (*p) = cNode();
            (*p)->start = i;
            (*p)->last = i;
            num ++;
        }
    }
    return num;
}
