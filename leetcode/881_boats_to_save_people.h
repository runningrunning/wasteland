// how to optimize the code ?
// how about size of people is unlimited ?
/* void nrb_sort(int* n, int s, int e)
{
    if (s >= e)
        return;

    int t;

    if (n[s] > n[e])
    {
        t = n[s];
        n[s] = n[e];
        n[e] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while (n[i] < n[s]) i ++;
        while (n[e] > n[s]) e --;

        if (i >= e)
        {
            t = n[s];
            n[s] = n[e];
            n[e] = t;
        }
        else
        {
            t = n[i];
            n[i] = n[e];
            n[e] = t;
        }
    }

    nrb_sort(n, cs, e - 1);
    nrb_sort(n, e + 1, ce);
}
*/
int comp(const void* e1, const void* e2)
{
    return *((int*)e1) - *((int*)e2);
}

int numRescueBoats(int* people, int peopleSize, int limit)
{
    if (peopleSize < 2)
        return peopleSize;

    int s = 0;
    int e = peopleSize - 1;

    // nrb_sort(people, s, e);
    qsort(people, peopleSize, sizeof(int), comp);

    int n = 0;
    while (people[e] == limit)
    {
        e --;
        n ++;
    }
    while (s <= e)
    {
        if (people[e] + people[s] <= limit)
            s ++;
        e --;
        n ++;
    }
    return n;
}
