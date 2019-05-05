bool checkRecord(char* s)
{
    bool absent = false;
    int late = -2;
    int i = 0;

    while(c = s[i])
    {
        i ++;

        if (c == 'L')
        {
            if (!late)
                return false;
            late ++;
        }
        else
        {
            late = -2;

            if (c == 'A')
            {
                if (absent)
                    return false;
                absent = true;
            }
        }
    }

    return true;
}
