#define F_MASK 1 << 31
#define V_MASK 0x7FFFFFFF

// STUPID WRONG ALGORITHM
// HASH for checking exist, two point to calculate the shortest distance
typedef struct {
    int primer;
    int* hash;
    int* pre;
    char** ws;
} WordDistance;

WordDistance* wordDistanceCreate(char** words, int wordsSize) {
    WordDistance* w = malloc(sizeof(WordDistance));
    if (wordsSize > 1)
    {
        // 1 << i
        // 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536
        // 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, Ok.
        int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147};
        int pl = sizeof(pri)/sizeof(pri[0]);
        int dp;
        for (int i = 0; i < pl; i ++)
        {
            dp = pri[i];
            if (dp / 4 > wordsSize)
                break;
        }

        int* hash = calloc(sizeof(int), dp);
        int* pre = malloc(sizeof(int) * wordsSize);
        w->ws = words;
        w->hash = hash;
        w->pre = pre;
        w->primer = dp;

        for (int i = 0; i < wordsSize; i ++)
        {
            char* s = words[i];
            int t = 0;
            int j = 0;
            int c = s[j ++];

            while (c)
            {
                t = (256 * t + c) % dp;
                c = s[j ++];
            }

            while ((hash[t] & F_MASK) && strcmp(words[hash[t] & V_MASK], s))
                t = (t + 1) % dp;

            if (hash[t] & F_MASK)
                pre[i] = hash[t] & V_MASK;
            else
                pre[i] = -1;
            hash[t] = F_MASK | i;
        }
    }
    return w;
}

int wordDistanceShortest(WordDistance* obj, char* word1, char* word2) {
    if (obj)
    {
        int i = 0;
        int c = word1[i ++];

        int dp = obj->primer;
        char** words = obj->ws;
        int* hash = obj->hash;

        int t1 = 0;
        while (c)
        {
            t1 = (256 * t1 + c) % dp;
            c = word1[i ++];
        }

        while ((hash[t1] & F_MASK) && strcmp(words[hash[t1] & V_MASK], word1))
            t1 = (t1 + 1) % dp;

        i = 0;
        c = word2[i ++];
        int t2 = 0;

        while (c)
        {
            t2 = (256 * t2 + c) % dp;
            c = word2[i ++];
        }

        while ((hash[t2] & F_MASK) && strcmp(words[hash[t2] & V_MASK], word2))
            t2 = (t2 + 1) % dp;

        int i1 = hash[t1] & V_MASK;
        int i2 = hash[t2] & V_MASK;

        int* pre = obj->pre;
        if (pre[i1] == -1 && pre[i2] == -1)
            return abs(i1 - i2);

        if (pre[i1] == -1)
        {
            int min = INT_MAX;
            while (i2 != -1)
            {
                int diff = abs(i2 - i1);
                if (diff < min)
                    min = diff;
                else
                    break;
                i2 = pre[i2];
            }
            return min;
        }
        else if (pre[i2] == -1)
        {
            int min = INT_MAX;
            while (i1 != -1)
            {
                int diff = abs(i2 - i1);
                if (diff < min)
                    min = diff;
                else
                    break;
                i1 = pre[i1];
            }
            return min;
        }

        if (i1 < i2)
        {
            i = i2;
            i2 = i1;
            i1 = i;
        }

        int min = INT_MAX;
        while (i1 != -1 && i2 != -1)
        {
            while (i1 > i2 && i1 != -1)
            {
                if (min >  i1 - i2)
                    min = i1 - i2;
                i1 = pre[i1];
            }

            i = i2;
            i2 = i1;
            i1 = i;
        }
        return min;
    }

    return 0;
}

void wordDistanceFree(WordDistance* obj) {
    if (obj)
    {
        free(obj->hash);
        free(obj->pre);
        free(obj);
    }
}


/*
typedef struct {
    int primer;
    int* hash;
    int* length;
    char** words1;
    char** words2;
    char** words;
    int ws;
    int ls;
} WordDistance;

WordDistance* wordDistanceCreate(char** words, int wordsSize) {
    WordDistance* w = malloc(sizeof(WordDistance));

    if (wordsSize > 1)
    {
        // 1 << i
        // 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536
        // 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, Ok.
        int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147};
        int pl = sizeof(pri)/sizeof(pri[0]);
        int dp;
        for (int i = 0; i < pl; i ++)
        {
            dp = pri[i];
            if (dp / 4 > wordsSize)
                break;
        }

        int* hash = calloc(sizeof(int), dp);
        int* length = malloc(sizeof(int) * wordsSize * (wordsSize - 1) / 2);
        char** words1 = malloc(sizeof(char*) * wordsSize * (wordsSize - 1) / 2);
        char** words2 = malloc(sizeof(char*) * wordsSize * (wordsSize - 1) / 2);

        w->primer = dp;
        w->hash = hash;
        w->length = length;
        w->words1 = words1;
        w->words2 = words2;
        w->ls = 0;
    }

    w->words = words;
    w->ws = wordsSize;
    return w;
}

int wordDistanceShortest(WordDistance* obj, char* word1, char* word2) {
    if (!obj || !word1 || !word2 || obj->ws < 2)
        return 0;

    char* w1 = word1;
    char* w2 = word2;

    int x = strcmp(word1, word2);
    if (x < 0)
    {
        w1 = word2;
        w2 = word1;
    }

    int t = 0;
    int i = 0;
    int c = w1[i ++];
    int dp = obj->primer;

    while (c)
    {
        t = (256 * t + c) % dp;
        c = w1[i ++];
    }

    t = (256 * t) % dp;

    i = 0;
    c = w2[i ++];

    while (c)
    {
        t = (256 * t + c) % dp;
        c = w2[i ++];
    }

    int* hash = obj->hash;
    while (hash[t] & F_MASK)
    {
        int index = hash[t] & V_MASK;
        if (!strcmp(w1, obj->words1[index]) && !strcmp(w2, obj->words2[index]))
            return obj->length[index];
        t = (t + 1) % dp;
    }

    int index = obj->ls ++;
    hash[t] = index | F_MASK;
    obj->words1[index] = strdup(w1);
    obj->words2[index] = strdup(w2);

    int min = obj->ws;
    int i1 = -1;
    int i2 = -1;

    for (int i = 0; i < obj->ws; i ++)
    {
        if (!strcmp(obj->words[i], w1))
            i1 = i;
        else if (!strcmp(obj->words[i], w2))
            i2 = i;
        if (i1 != -1 && i2 != -1)
        {
            int d = abs(i1 - i2);
            if (d < min)
                min = d;
        }
    }
    obj->length[index] = min;
    return min;
}

void wordDistanceFree(WordDistance* obj) {
    if (obj)
    {
        free(obj->hash);
        free(obj->length);
        for (int i = 0; i < obj->ls; i ++)
        {
            free(obj->words1[i]);
            free(obj->words2[i]);
        }
        free(obj->words1);
        free(obj->words2);
        free(obj);
    }
}
*/
/**
 * Your WordDistance struct will be instantiated and called as such:
 * struct WordDistance* obj = wordDistanceCreate(words, wordsSize);
 * int param_1 = wordDistanceShortest(obj, word1, word2);
 * wordDistanceFree(obj);
 */
