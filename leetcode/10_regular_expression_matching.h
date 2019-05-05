struct PatternNode
{
    char ch;
    bool any;
    struct PatternNode* next;
};

void parseRegular(char *p, struct PatternNode** in)
{
    int i = 0;
    struct PatternNode* temp = 0;
    while(p[i])
    {
        temp = malloc(sizeof(struct PatternNode));
        temp->next = 0;
        temp->ch = p[i];
        temp->any = p[i + 1] == '*';
        if (temp->any)
            i ++;
        *in = temp;
        in = &temp->next;
        i ++;
    }
}
bool do_match_2(char* n, char* p, int i, int j)
{
    if (!p[i])
    {
        while(n[j])
        {
            if (n[j + 1] != '*')
                return false;
            j += 2;
        }
        return true;
    }
    if (!n[j])
        return false;
    if (n[j + 1] != '*')
    {
        if (n[j] == p[i] || n[j] == '.')
            return do_match_2(n, p, i + 1, j + 1);
        return false;
    }
    bool matched = do_match_2(n, p, i, j + 2);
    if (matched)
        return true;
    while(p[i] && (n[j] == p[i] || n[j] == '.'))
    {
        matched = do_match_2(n, p, i + 1, j + 2);
        if (matched)
            return true;
        i ++;
    }
    return false;
}

bool do_match(struct PatternNode* node,  char *p, int i)
{
    if (!p[i])
    {
        while(node)
        {
            if (!node->any)
                return false;
            node = node->next;
        }
        return true;
    }

    if (!node)
        return false;

    if (!node->any)
    {
        if (node->ch == p[i] || node->ch == '.')
            return do_match(node->next, p, i + 1);
        return false;
    }
    else
    {
        /* skip this */
        bool matched = do_match(node->next, p, i);
        if (matched)
            return true;

        while(p[i] && (node->ch == p[i] || node->ch == '.'))
        {
            matched = do_match(node->next, p, i + 1);
            if (matched)
                return true;
            i ++;
        }
    }
    return false;
}

bool isMatch(char* s, char*p)
{
    if (!strlen(p))
        return !strlen(s);
    if (!strcmp(s,p))
        return true;

    struct PatternNode* pattern;
    parseRegular(p, &pattern);
    //return do_match_2(p, s, 0, 0);
    return do_match(pattern, s, 0);
}
