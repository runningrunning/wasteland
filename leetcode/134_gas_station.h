int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
    if (gasSize != costSize || !gasSize)
        return -1;

    /*
    int pi = 0;
    gas[pi] -= cost[pi];
    cost[pi] = 0;

    int all = gas[0];
    for (int i = 1; i < gasSize; i ++)
    {
        int cs = gas[i] - cost[i];
        all += cs;
        if (cs <= 0 || gas[pi] >= 0)
            gas[pi] += cs;
        else
        {
            pi ++;
            gas[pi] = cs;
            cost[pi] = i;
        }
    }
    return all >= 0? cost[pi] : -1;
    */

    int gi = 0;
    int gs = gas[0] - cost[0];
    int all = gs;

    for (int i = 1; i < gasSize; i ++)
    {
        int cs = gas[i] - cost[i];
        all += cs;

        if (cs > 0 && gs < 0)
        {
            gs = 0;
            gi = i;
        }
        gs += cs;

        /* if (cs <= 0 || gs >= 0) */
        /*     gs += cs; */
        /* else */
        /* { */
        /*     gs = cs; */
        /*     gi = i; */
        /* } */
    }
    return all >= 0 ? gi : -1;
}

/*
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
    if (gasSize != costSize || !gasSize)
        return -1;

    int _quote = 0;
    int max_quote = 0;
    int all_quote = 0;

    int _extra = 0;
    int max_extra = 0;
    int all_extra = 0;
    int max_st = 0;

    int st = 0;

    bool update_st = true;
    int s = gasSize;
    int pre = 0;

    int first = 0;
    int all_d = 0;

    for (int i = 0; i < s; i ++)
    {
        int d = gas[i] - cost[i];
        int x = d >= 0 ? 1 : -1;

        if (!pre || pre != x)
        {
            pre = x;

            if (d >= 0)
            {
                if (max_quote > _quote)
                    max_quote = _quote;

                if (d + _quote >= 0)
                {
                    if (!first)
                        first = max_quote;
                    printf("quote is %d.\n", _quote);
                    _quote = 0;
                }

                if (update_st)
                {
                    update_st = false;
                    printf("st is %d.\n", st);
                    st = i;
                }
            }
            else
            {
                if (max_extra < _extra)
                {
                    max_extra = _extra;
                    max_st = st;
                }

                if (d + _extra < 0)
                {
                    if (!first)
                        first = max_extra;
                    update_st = true;
                    printf("extra is %d.\n", _extra);
                    _extra = 0;
                }
            }
        }

        if (d < 0)
        {
            all_quote += d;
            _quote += d;
        }
        else
        {
            all_extra += d;
            _extra += d;
        }
    }

    if (_extra || _quote)
    {
        if (_extra)
        {
            if (first >= 0)
                _extra += first;

            if (max_extra < _extra)
            {
                max_extra = _extra;
                max_st = st;
            }
            _extra = 0;
        }

        if (_quote)
        {
            if (first < 0)
                _quote += first;

            if (max_quote > _quote)
                max_quote = _quote;
            _quote = 0;
        }
    }

    int all = all_extra + all_quote;
    int max = max_extra + max_quote;
    printf("all e %d all q %d max e %d max q %d e %d q %d  st %d first %d.\n", all_extra, all_quote, max_extra, max_quote, _extra, _quote, max_st, first);

    if (all >= 0 && max >= 0)
        return st;
    return -1;
}
*/
