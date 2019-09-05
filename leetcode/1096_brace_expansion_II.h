/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// nested curly brackets
// be careful memory usage
void _expand(char* a, int s, int e, char*** r, int* ti)
{
    if (s > e)
        return;

    int ti = 0;
    char t[64];

    while (a[s] >= 'a' && a[s] <= 'z')
        t[ti ++] = a[s ++];

    

}

char** braceExpansionII(char * expression, int* returnSize)
{
    int ri = 0;
    char** r = NULL;
    int l = strlen(expression);
    _expand(expression, 0, l - 1, &r, &ri);
    // sort
    return NULL;
}
