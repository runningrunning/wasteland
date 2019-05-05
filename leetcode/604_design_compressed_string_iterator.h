typedef struct {
    int si;
    char* s;
    int cn;
    char c;
} StringIterator;

StringIterator* stringIteratorCreate(char* compressedString) {
    if (!compressedString)
        return NULL;

    StringIterator* s = malloc(sizeof(StringIterator));
    s->si = 0;
    s->s = compressedString;
    s->c = 0;
    s->cn = 0;
    s->si = 0;
    return s;
}

char stringIteratorNext(StringIterator* obj) {
    if (!obj)
        return ' ';

    if (obj->cn)
    {
        obj->cn --;
        return obj->c;
    }

    char t;
    int num = 0;
    int si = obj->si;

    if (!obj->s[si])
        return ' ';

    obj->c = obj->s[si ++];
    while(t = obj->s[si])
    {
        if (t < '0' || t > '9')
            break;
        num = num * 10 + t - '0';
        si ++;
    }
    obj->cn = num - 1;
    obj->si = si;

    return obj->c;
}

bool stringIteratorHasNext(StringIterator* obj) {
    if (!obj)
        return false;

    return obj->cn || obj->s[obj->si];
}

void stringIteratorFree(StringIterator* obj) {
    if (obj)
    {
        free(obj->s);
        free(obj);
    }
}

/**
 * Your StringIterator struct will be instantiated and called as such:
 * struct StringIterator* obj = stringIteratorCreate(compressedString);
 * char param_1 = stringIteratorNext(obj);
 * bool param_2 = stringIteratorHasNext(obj);
 * stringIteratorFree(obj);
 */
