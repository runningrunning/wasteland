bool isValid(char *s)
{
    if (!strlen(s))
        return true;

    char* valid = malloc(strlen(s) + 2);
    valid[0] = 0;

    int j = 0;
    for (int i = 0; s[i]; i++)
    {
        switch(s[i])
        {
        case '(':
            valid[++j] = ')';
            break;
        case '{':
            valid[++j] = '}';
            break;
        case '[':
            valid[++j] = ']';
            break;
        case ')':
        case '}':
        case ']':
            if (!j || valid[j] != s[i])
                return false;
            j --;
            break;
        }
    }
    return !j;
}
