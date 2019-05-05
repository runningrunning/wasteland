/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* can have invalid itineraries (not used ) ??? */
/* destination could be invalid !!!! */
/* That's not TRUE */
/* You may assume all tickets form at least one valid itinerary. */
/* the corner case is that JFK:AAA is same with JFK:000 as we - 'A', use '@' instead */

void fi_sort(int* n, int s, int e, int* id)
{
    if (s >= e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[e];
        n[e] = n[s];
        n[s] = t;

        t = id[e];
        id[e] = id[s];
        id[s] = t;
    }

    if (s + 1 == e)
        return;

    int os = s;
    int oe = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[e];
            n[e] = n[s];
            n[s] = t;

            t = id[e];
            id[e] = id[s];
            id[s] = t;
        }
        else
        {
            t = n[e];
            n[e] = n[i];
            n[i] = t;

            t = id[e];
            id[e] = id[i];
            id[i] = t;
        }
    }

    fi_sort(n, os, e - 1, id);
    fi_sort(n, e + 1, oe, id);
}

char** findItinerary(char*** tickets, int ticketsRowSize, int ticketsColSize, int* returnSize)
{
    if (!tickets || !ticketsRowSize)
        return NULL;

    int size = ticketsRowSize + 1;
    *returnSize = size;
    char** ret = malloc(sizeof(char*) * size);

    if (ticketsRowSize == 1)
    {
        ret[0] = tickets[0][0];
        ret[1] = tickets[0][1];
        return ret;
    }

    int* t = malloc(sizeof(int) * ticketsRowSize);
    int* ti = malloc(sizeof(int) * ticketsRowSize);

    for (int i = 0; i < ticketsRowSize; i ++)
    {
        char* start = tickets[i][0];
        char* end = tickets[i][1];

        int tf = ((start[0] - '@') << 10) | ((start[1] - '@') << 5) | ((start[2] - '@'));
        tf <<= 15;
        tf |= ((end[0] - '@') << 10) | ((end[1] - '@') << 5) | ((end[2] - '@'));
        tf <<= 1;
        t[i]= tf & (~ 1);
        ti[i] = i;
    }

    fi_sort(t, 0, ticketsRowSize - 1, ti);

    int si = 0;
    int st = ((('J' - '@') << 10) | (('F' -  '@') << 5) | ('K' - '@')) << 16;
    int* stacks = malloc(sizeof(int) * size);
    stacks[size - 1] = 0;
    int mask = 0xFFFF << 16;

    while (true)
    {
        int s = 0;
        int e = ticketsRowSize - 1;

        while (s < e)
        {
            int m = s + (e - s) / 2;
            if (t[m] > st)
                e = m;
            else
                s = m + 1;
        }

        while (s < ticketsRowSize && (t[s] & 1))
            s ++;

        if ((t[s] & mask) == (st & mask))
        {
            stacks[si ++] = s;
            st = (t[s] & 0xFFFF) << 15;
            t[s] |= 1;
        }
        else
        {
            while (si)
            {
                int cs = stacks[si - 1];
                int need = t[cs] & mask;
                bool found = false;
                int ns = cs;
                while ((t[ns + 1] & mask) == need)
                {
                    ns ++;

                    if (!(t[ns] & 1))
                    {
                        found = true;
                        break;
                    }
                }

                t[cs] &= ~1;

                if (!found)
                    si --;
                else
                {
                    stacks[si - 1] = ns;
                    t[ns] |= 1;
                    break;
                }
            }
            st = (t[stacks[si - 1]] & 0xFFFE) << 15;
        }

        if (si == ticketsRowSize)
            break;
    }

    ret[0] = tickets[ti[stacks[0]]][0];
    for (int i = 0; i < ticketsRowSize; i ++)
        ret[i + 1] = tickets[ti[stacks[i]]][1];
    return ret;
}
