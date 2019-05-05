// TODO: code optimize !!!!!!!!!
// DP or BFS ?
// simple DP
// how to optimize this ?
// just cross over the index
int md(char* w1, int s1, int l1, char* w2, int s2, int l2, int* ns)
{
    if (ns[s1 * l2 + s2])  // s1 or s2 could equal l1 and l2, then overflow
        return ns[s1 * l2 + s2] - 1;

    if (s1 == l1 || s2 == l2)
    {
        if (s1 == l1 && s2 == l2)
            return 0;
        if (s1 == l1)
            return l2 - s2;
        return l1 - s1;
    }

    int m = md(w1, s1 + 1, l1, w2, s2 + 1, l2, ns) + ((w1[s1] == w2[s2]) ? 0 : 1);
    int n = m;

    // only do this when m >= n
    if (m >= abs(l1 - s1 - 1 - l2 + s2))
    {
        n = md(w1, s1 + 1, l1, w2, s2, l2, ns) + 1;

        if (m > n)
            m = n;
    }

    // only do this when m >= n
    if (m >= abs(l1 - s1 - l2 + s2 + 1))
    {
        n = md(w1, s1, l1, w2, s2 + 1, l2, ns) + 1;

        if (m > n)
            m = n;
    }

    ns[s1 * l2 + s2] = m + 1;

    return m;
}

int minDistance(char* word1, char* word2)
{
    int l1 = strlen(word1);
    int l2 = strlen(word2);

    int* ns = calloc(sizeof(int), (l1 + 1) * (l2 + 1)); // use l1 + 1 and l2 + 1 incase the checking overflow.
    return md(word1, 0, l1, word2, 0, l2, ns);
}
