/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int next(char* text, int* s)
{
    int si = *s;
    while(text[si] && text[si] == ' ')
        si ++;

    *s = si;

    if (!text[si])
        return 0;

    int ei = si;

    while(text[ei] && text[ei] != ' ')
        ei ++;

    return ei;
}

char ** findOcurrences(char * text, char * first, char * second, int* returnSize)
{
    int ri = 0;
    char** r = NULL;

    int fs = 0;
    int fe = 0;
    int ss = 0;
    int se = 0;
    int ts = 0;
    int te = 0;

    int fl = strlen(first);
    int sl = strlen(second);

    do {

        fe = next(text, &fs);

        if (!fe)
            break;

        if (fe - fs != fl || strncmp(first, text + fs, fl))
        {
            fs = fe;
            continue;
        }

        ss = fe;
        se = next(text, &ss);

        if (!se)
            break;

        if (se - ss != sl || strncmp(second, text + ss, sl))
        {
            fs = ss;
            continue;
        }

        ts = se;
        te = next(text, &ts);

        if (!te)
            break;

        fs = ss;
        r = realloc(r, sizeof(char*) * (ri + 1));
        r[ri] = malloc(sizeof(char) * (te - ts + 1));
        strncpy(r[ri], text + ts, te - ts);
        r[ri][te - ts] = 0;
        ri ++;

    } while (text[fs]);

    *returnSize = ri;
    return r;
}

