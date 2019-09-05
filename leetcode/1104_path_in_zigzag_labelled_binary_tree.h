/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* pathInZigZagTree(int label, int* returnSize){
    int l = 1;
    int n = 2;
    while (n - 1 < label)
    {
        l ++;
        n *= 2;
    }
    int* r = malloc(sizeof(int) * l);
    *returnSize = l;

    int ns = n / 2;
    int ne = n - 1;
    int off  = (l % 2) ? (label - ns) : (ne - label);

    while (l)
    {
        ns = n / 2;
        ne = n - 1;

        r[l - 1] = (l % 2) ? (ns + off) : (ne - off);

        l --;
        n = ns;
        off /= 2;
    }
    return r;
}

