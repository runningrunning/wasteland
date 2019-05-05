// be careful !
// be more careful !!!
// take care 20.(0000) ?
// take care 20.80000 vs 20.7(99999)

struct Rational
{
    int i;
    int rs;
    char repeat[6];
    int ns;
    char not_repeat[6];
    int has_repeat;
};

// return false if it get two 0
bool _parse(char* s, struct Rational* r)
{
    int i = 0;
    int x = 0;

    while (s[i] && s[i] != '.')
        x = x * 10 + s[i ++] - '0';

    r->i = x;

    if (i >= 2)
        if (s[0] == '0' && s[1] == '0')
            return false;

    if (!s[i])
        return true;

    if (s[i] != '.')
        return false;

    i ++;

    if (!s[i])
        return true;

    x = 0;
    int t = 0;

    while(s[i] && s[i] != '(')
        r->not_repeat[t ++] = s[i ++];

    r->ns = t;

    if (!s[i])
    {

        bool all_zero = true;

        for (int j = 0; j < t; j ++)
            if (r->not_repeat[j] != '0')
            {
                all_zero = false;
                break;
            }

        if (all_zero)
        {
            r->ns = 0;
            memset(r->not_repeat, 0, 6);
        }
        else
        {
            for (int j = t - 1; j >= 0; j --)
                if (r->not_repeat[j] == '0')
                    r->ns = j;
                else
                    break;
        }

        return true;
    }

    if (s[i] != '(')
        return false;

    i ++;

    t = 0;
    while (s[i] && s[i] != ')')
        r->repeat[t ++] = s[i ++];

    r->rs = t;

    if (!s[i] || s[i] != ')')
        return false;

    bool all_zero = true;

    for (int j = 0; j < t; j ++)
        if (r->repeat[j] != '0')
        {
            all_zero = false;
            break;
        }

    if (all_zero)
    {
        r->rs = 0;
        all_zero = true;
        memset(r->repeat, 0, 6);

        for (int j = 0; j < t; j ++)
            if (r->not_repeat[j] != '0')
            {
                all_zero = false;
                break;
            }

        if (all_zero)
        {
            r->ns = 0;
            memset(r->not_repeat, 0, 6);
        }
    }
    else
        r->has_repeat = true;

    return true;
}

bool compare_repeat(struct Rational* s, struct Rational* t)
{
    if (s->i != t->i)
        return false;

    int si = 0;
    int ti = 0;
    int xi = 0;

    while (xi < s->ns || xi < t->ns)
    {
        char cs = xi < s->ns ? s->not_repeat[xi] : s->repeat[(xi - s->ns) % s->rs];
        char ts = xi < t->ns ? t->not_repeat[xi] : t->repeat[(xi - t->ns) % t->rs];
        if (cs != ts)
            return false;
        xi ++;
    }

    si = (xi - s->ns) % s->rs;
    ti = (xi - t->ns) % t->rs;

    char* all = calloc(sizeof(char), s->rs * 10 + t->rs + 1);

    while (true)
    {
        if (all[si * 10 + ti])
            break;

        if (s->repeat[si] != t->repeat[ti])
            return false;

        all[si * 10 + ti] = 1;

        si = (si + 1) % s->rs;
        ti = (ti + 1) % t->rs;
    }

    return true;
}

bool compare_half_repeat(struct Rational* s, struct Rational* t)
{
    struct Rational* n = s->has_repeat ? t : s;
    struct Rational* r = s->has_repeat ? s : t;

    for (int i = 0; i < r->rs; i ++)
        if (r->repeat[i] != '9')
            return false;

    if (n->i != r->i)
    {
        if (n->i - r->i != 1)
            return false;

        if (n->ns)
            return false;

        for (int i = 0; i < r->ns; i ++)
            if (r->not_repeat[i] != '9')
                return false;

        return true;
    }

    if (!n->ns)
        return false;

    int xi = 0;
    while (xi < n->ns)
    {
        char ns = n->not_repeat[xi];
        char rs = xi < r->ns ? r->not_repeat[xi] : r->repeat[(xi - r->ns) % r->rs];

        if (ns != rs)
        {
            if (ns - rs != 1)
                return false;

            if (xi != n->ns - 1)
                return false;

            xi ++;
            break;
        }

        xi ++;
    }

    for (xi; xi < r->ns; xi ++)
        if (r->repeat[xi] != '9')
            return false;
    return true;
}

bool isRationalEqual(char* S, char* T)
{
    struct Rational s;
    struct Rational t;

    memset(&s, 0, sizeof(struct Rational));
    memset(&t, 0, sizeof(struct Rational));

    if (!_parse(S, &s) || !_parse(T, &t))
        return false;

    if (s.has_repeat && t.has_repeat)
        return compare_repeat(&s, &t);

    if (s.has_repeat || t.has_repeat)
        return compare_half_repeat(&s, &t);
    return !memcmp(&s, &t, sizeof(struct Rational));
}
