// corner case, forget to remove end bit or add end bit not needed.
#define N 26
#define E_MASK (1 << 30)
#define RE_MASK ~(1 << 30)
typedef struct _Node
{
    int f;
    struct _Node* n[N];
} Node;

Node* cNode()
{
    Node* c = malloc(sizeof(Node));
    c->f = 0;
    return c;
}

void aNode(Node* r, char* w, int* m)
{
    int l = strlen(w);
    bool add = false;
    for (int i = l - 1; i >= 0; i --)
    {
        int c = w[i] - 'a';

        if (r->f & E_MASK)
        {
            (*m) -= (l - i);
            r->f &= RE_MASK;
        }

        if (!(r->f & (1 << c)))
        {
            r->f |= 1 << c;
            r->n[c] = cNode();
            add = true;
        }
        r = r->n[c];
    }

    if (add)
    {
        r->f |= E_MASK;
        *m += l + 1;
    }
}

// suffix trie ?
int minimumLengthEncoding(char** words, int wordsSize)
{
    int min = 0;
    Node* r = cNode();
    for (int i = 0; i < wordsSize; i ++)
        aNode(r, words[i], &min);
    return min;
}
