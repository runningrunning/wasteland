// diff with 10 regular expression match as * ? have no side effect for other matches.
// never write ++ -- in while(condition) !!!
bool isMatch(char* s, char* p)
{
    int sl = strlen(s);
    int pl = strlen(p);

    if (pl == 0)
        return sl == 0;

    int tl = 0;
    char* t = strdup(p);
    int pre = 0;
    int sc = 0;

    int c = 0;
    int i = 0;

    while(i < pl)
    {
        pre = 0;
        while(p[i] == '*')
        {
            i++;
            pre = '*';
        }

        if (!p[i])
            return true;

        tl = 0;

        while(p[i] && p[i] != '*')
            t[tl ++] = p[i ++];

        if (sl - sc < tl)
            return false;

        if (pre != '*')
        {
            c = 0;
            while(c < tl && (s[sc] == t[c] || t[c] == '?'))
            {
                c ++;
                sc ++;
            }

            if (c != tl)
                return false;

            if (p[i] == 0)
                return sc == sl;
        }
        else
        {
            if (p[i] == 0)
            {
                c = 0;
                while(c < tl && (s[sl - 1 - c] == t[tl - 1 - c]) || t[tl - 1 - c] == '?')
                    c ++;

                return  c == tl;
            }

            for (sc; sc <= sl - tl; sc++)
            {
                c = 0;
                int st = sc;
                while(c < tl && (s[st] == t[c] || t[c] == '?'))
                {
                    c ++;
                    st ++;
                }

                if (c == tl)
                {
                    sc = st;
                    break;
                }
            }

            if (c != tl)
                return false;
        }
    }
    return true;
}

/*
int comp(const void* e1, const void* e2)
{
    return *((int*)e1) - *((int*)e2);
}

struct MatchNode
{
    char* s;
    int l;
    struct MatchNode* pre;
    struct MatchNode* post;

};

void insert(struct MatchNode* h, struct MatchNode* i)
{
    while(h)
    {
        if (h->s >= i->s)
        {
            if (!h->pre)
            {
                h->pre = i;
                return;
            }
            h = h->pre;
        }
        else
        {
            if (!h->post)
            {
                h->post = i;
                return;
            }
            h = h->post;
        }
    }
}

struct MatchNode* parse(char*s, char* p)
{
    int pn = 0;
    int mn = 256;
    int* ps = malloc(sizeof(int) * mn);
    memset(ps, 0, sizeof(int) * mn);

    int n = strlen(p);
    int ss = 0;
    int se = strlen(s);

    int si = 0;
    int l = 0;

    for (int i= 0; i < n; i++)
    {
        if (p[i] != '*')
        {
            if (!l)
                si = i;
            l ++;
        }
        else if (l)
        {
            if (pn >= mn)
            {
                mn += 256;
                ps = realloc(ps, sizeof(int) * mn);
            }

            int c = 0;
            //printf("add %d for %d.\n", l, s);
            // 32 bits should be enough
            ps[pn ++] = (l << 24) | si;
            l = 0;
        }
    }

    if (l)
    {
        if (pn >= mn)
        {
            mn += 256;
            ps = realloc(ps, sizeof(int) * mn);
        }

        // 32 bits should be enough
        ps[pn ++] = (l << 24) | si;
    }

    if (pn == 0)
    {
        // free(ps);
        return NULL;
    }

    // prepare size nodes
    qsort(ps, pn, sizeof(int), comp);

    out(ps, pn);
    for (int i = 0; i < pn; i ++)
    {
        struct MatchNode* t = malloc(sizeof(struct MatchNode));
        f = ps[pn - 1 - i];
        t->s = p + (f & 0xFFF);
        t->l = f >> 24;
        //printf("l %d s %d\n", t->l, f&0xFFF);
        t->pre = NULL;
        t->post = NULL;

        //printf("l %d %s\n", t->l, t->s);
        if (h == NULL)
        {
            //printf("set h is %d %s.\n", t->l, t->s);
            h = t;
        }
        else
            insert(h, t);
    }

    // TODO handle * in the begin and last
    if (p[0] != '*')
    {
        struct MatchNode* t = malloc(sizeof(struct MatchNode));
        t->s = p;
        t->l = 0;
        t->pre = NULL;
        t->post = NULL;
        insert(h, t);
    }

    if (p[n - 1] != '*')
    {
        struct MatchNode* t = malloc(sizeof(struct MatchNode));
        t->s = p + n;
        t->l = 0;
        t->pre = NULL;
        t->post = NULL;
        insert(h, t);
    }

    return h;
}

bool match(char* s, int a, int b, struct MatchNode* p)
{
    //printf("try a %d b %d.\n", a, b);
    if (!p)
    {
        return true;
    }

    int n = b - a + 1;

    if (!p->l)
    {
        //printf("n ==0 %d\n", n);
        return n == 0;
    }

    if (n < p->l)
    {
        //printf("n < p->l false\n");
        return false;
    }

    //printf("match %s. a  %d b %d p->l %d p->s %s.\n", s, a, b, p->l, p->s);
    for(int i = 0; i <= n - p->l; i ++)
    {
        int c = 0;
        while(c < p->l && (p->s[c] == s[a + i + c] || p->s[c] == '?')) c ++;
        if (c == p->l)
        {
            bool ret;

            if (p->pre && p->post)
            {
                if (p->pre->l >= p->post->l)
                    ret = match(s, a, a + i - 1, p->pre)
                        && match(s, a + i + c, b, p->post);
                else
                    ret = match(s, a + i + c, b, p->post)
                        && match(s, a, a + i - 1, p->pre);
            }
            else
                ret = match(s, a, a + i - 1, p->pre)
                    && match(s, a + i + c, b, p->post);

            if (ret)
            {
                //printf("ret true\n");
                return true;
            }
        }
    }
    //printf("ret false\n");
    return false;
}

bool isMatch(char* s, char* p)
{
    if (!strlen(p))
        return !strlen(s);
    return match(s, 0, sl - 1, parse(p));
}
*/
