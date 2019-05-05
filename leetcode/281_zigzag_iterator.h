/* TODO learn how to use heap */
// Can be optimized by removing empty stuff with min heap
struct ZigzagIterator
{
    int _x;
    int _y;

    int k;
    int* vs;
    int** vc;
    int left;
};

struct ZigzagIterator *zigzagIteratorCreate(int* v1, int v1Size, int* v2, int v2Size)
{
    struct ZigzagIterator* z = malloc(sizeof(struct ZigzagIterator));
    z->k = 2;
    z->vs = malloc(sizeof(int) * z->k);
    z->vc = malloc(sizeof(int*) * z->k);
    z->vs[0] = v1Size;
    z->vs[1] = v2Size;
    z->vc[0] = v1;
    z->vc[1] = v2;
    z->left = v1Size + v2Size;

    for (int i = 0; i < z->k; i++)
    {
        if (z->vs[i] > 0)
        {
            z->_x = i;
            z->_y = 0;
            break;
        }
    }
    return z;
}

bool zigzagIteratorHasNext(struct ZigzagIterator *iter)
{
    return iter && iter->left;
}

int zigzagIteratorNext(struct ZigzagIterator *iter)
{
    if (!iter || !iter->left)
        return 0;
    int v = iter->vc[iter->_x][iter->_y];

    iter->left --;
    if (iter->left)
    {
        bool found = false;
        for (int i = iter->_x + 1; i < iter->k; i ++)
        {
            if (iter->vs[i] > iter->_y)
            {
                found = true;
                iter->_x = i;
                break;
            }
        }

        if (!found)
        {
            iter->_y += 1;
            for (int i = 0; i < iter->k; i ++)
            {
                if (iter->vs[i] > iter->_y)
                {
                    found = true;
                    iter->_x = i;
                    break;
                }
            }
        }
    }
    return v;
}

/** Deallocates memory previously allocated for the iterator */
void zigzagIteratorFree(struct ZigzagIterator *iter)
{
    if (iter)
    {
        free(iter->vs);
        free(iter->vc);
    }
}

/**
 * Your ZigzagIterator will be called like this:
 * struct ZigzagIterator *i = zigzagIteratorCreate(v1, v1Size, v2, v2Size);
 * while (zigzagIteratorHasNext(i)) printf("%d\n", zigzagIteratorNext(i));
 * zigzagIteratorFree(i);
 */
