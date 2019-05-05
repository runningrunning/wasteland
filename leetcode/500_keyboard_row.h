/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize)
{
    int fs[] = {265961, 44052486, 44052486, 265961, 22790416, 265961, 265961, 265961, 22790416, 265961, 265961, 265961, 44052486, 44052486, 22790416, 22790416, 22790416, 22790416, 265961, 22790416, 22790416, 44052486, 22790416, 44052486, 22790416, 44052486, 0, 0, 0, 0, 0, 0, 265961, 44052486, 44052486, 265961, 22790416, 265961, 265961, 265961, 22790416, 265961, 265961, 265961, 44052486, 44052486, 22790416, 22790416, 22790416, 22790416, 265961, 22790416, 22790416, 44052486, 22790416, 44052486, 22790416, 44052486};

    int size = 0;
    char** ret = malloc(sizeof(char*) * wordsSize);

    for (int i = 0; i < wordsSize; i ++)
    {
        char* w = words[i];
        int fc = fs[w[0] - 'A'];
        bool n = true;

        int j = 1;
        while(w[j])
        {
            if (fs[w[j] - 'A'] != fc)
            {
                n = false;
                break;
            }
            j ++;
        }

        if (n)
            ret[size ++] = w;
    }

    *returnSize = size;
    return ret;
}
