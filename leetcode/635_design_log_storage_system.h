// Month and Day are start from 1
typedef struct {
    int* lnum;
    int* ids;
    int ln;
} LogSystem;

LogSystem* logSystemCreate() {
    LogSystem* l = malloc(sizeof(LogSystem));
    l->ln = 0;
    l->lnum = malloc(sizeof(int) * 301);
    l->ids = malloc(sizeof(int) * 301);
    return l;
}

// "2017:01:01:23:59:59"
int t2i(char* t, char* g, bool s)
{
    int x[] = {32140800, 2678400, 86400, 3600, 60, 1};
    int n[6];

    n[0] = (t[2] - '0') * 10 + (t[3] - '0');
    n[1] = (t[5] - '0') * 10 + (t[6] - '1');
    n[2] = (t[8] - '0') * 10 + (t[9] - '1');
    n[3] = (t[11] - '0') * 10 + (t[12] - '0');
    n[4] = (t[14] - '0') * 10 + (t[15] - '0');
    n[5] = (t[17] - '0') * 10 + (t[18] - '0');

    int e = 6;
    int d = 0;

    if (g)
    {
        int c = g[0];
        if (c == 'M')
        {
            if (g[1] == 'o')
                e = 2;
            else
                e = 5;
        }
        else if (c == 'Y')
            e = 1;
        else if (c == 'D')
        {
            e = 3;
        }
        else if (c == 'H')
            e = 4;

        d = s ? 0 : (x[e - 1] - 1);
    }

    int r = 0;
    for (int i = 0; i < e; i ++)
        r += x[i] * n[i];

    return r + d;
}

void logSystemPut(LogSystem* obj, int id, char* timestamp) {
    if (obj)
    {
        int in = obj->ln;
        obj->ids[in] = id;
        obj->lnum[in] = t2i(timestamp, NULL, false);
        obj->ln ++;
    }
}

int* logSystemRetrieve(LogSystem* obj, char* s, char* e, char* gra, int *returnSize) {
    if (obj)
    {
        int st = t2i(s, gra, true);
        int ed = t2i(e, gra, false);
        int* nums = obj->lnum;
        int* ids = obj->ids;

        int rs = 0;
        int* r = malloc(sizeof(int) * 301);

        for (int i = 0; i < obj->ln; i ++)
        {
            if (nums[i] >= st && nums[i] <= ed)
                r[rs ++] = ids[i];
        }
        *returnSize = rs;
        return r;
    }

    return NULL;
}

void logSystemFree(LogSystem* obj) {
    if (obj)
    {
        free(obj->lnum);
        free(obj->ids);
        free(obj);
    }
}

/**
 * Your LogSystem struct will be instantiated and called as such:
 * struct LogSystem* obj = logSystemCreate();
 * logSystemPut(obj, id, timestamp);
 * int* param_2 = logSystemRetrieve(obj, s, e, gra);
 * logSystemFree(obj);
 */
