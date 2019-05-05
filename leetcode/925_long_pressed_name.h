// be careful
bool isLongPressedName(char* name, char* typed)
{
    if (!name || !name[0])
        return !typed || !typed[0];

    int ni = 0;
    int ti = 0;

    char p = -1;

    while (name[ni] && typed[ti])
    {
        if (name[ni] == typed[ti])
        {
            p = name[ni];
            ni ++;
            ti ++;
        }
        else if (typed[ti] == p)
            ti ++;
        else
            break;
    }

    if (name[ni])
        return false;

    if (typed[ti])
    {
        while (typed[ti])
            if (typed[ti] == p)
                ti ++;
            else
                break;
    }
    return !typed[ti];
}
