// upper case ?
// number ?
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool match(char* w, char* p, int l)
{
    int f = 0;
    int t[26] = {0};

    for (int i = 0; i < l; i ++)
    {
        char _w = w[i] - 'a';
        char _p = p[i] - 'a';

        if (t[_p])
        {
            if (_w + 1 != t[_p])
                return false;
        }
        else if (f & (1 << _w))
            return false;

        t[_p] = _w + 1;
        f |= 1 << _w;
    }
    return true;

}

char** findAndReplacePattern(char** words, int wordsSize, char* pattern, int* returnSize)
{
    int rs = 0;
    char** r = NULL;

    int l = strlen(pattern);
    for (int i = 0; i < wordsSize; i ++)
    {
        char* w = words[i];
        if (strlen(w) == l && match(w, pattern, l))
        {
            r = realloc(r, sizeof(char*) * (rs + 1));
            r[rs ++] = w;
        }
    }
    *returnSize = rs;
    return r;
}
