bool canTransform(char* start, char* end)
{
    if (start == end)
        return true;

    int s = 0;
    int e = 0;
    char c = start[s];

    while (c)
    {
        int x = end[s];

        if (c != x)
        {
            if (c == 'L')
                return false;

            char no = c == 'X' ? 'R' : 'L';

            if (x == no)
                return false;

            e = s + 1;
            x = start[e];

            while (x == c)
                x = start[++ e];

            if (!x || x == no)
                return false;

            start[e] = c;

            /*
            if (c == 'X')
            {
                if (x == 'R')
                    return false;

                e = s;
                x = start[++ e];

                while (x == 'X')
                    x = start[++ e];

                if (!x || x == 'R')
                    return false;
                start[e] = 'X';
            }
            else
            {
                if (x == 'L')
                    return false;

                e = s;
                x = start[++ e];

                while (x == 'R')
                    x = start[++ e];

                if (!x || x == 'L')
                    return false;
                start [e] = 'R';
            }
            */
        }
        c = start[++ s];
    }
    return true;
}
