// CORNER CASE!!!!!!!!!!!
// a!=a
// core case
bool equationsPossible(char** equations, int equationsSize)
{
    int v[26] = {0};
    int n = 1;
    int no = 0;
    for (int i = 0; i < equationsSize; i ++)
    {
        char* c = equations[i];
        if (c[1] == '!')
        {
            no ++;
            continue;
        }
        int a = c[0] - 'a';
        int b = c[3] - 'a';

        if (v[a] && !v[b])
            v[b] = v[a];
        else if (v[b] && !v[a])
            v[a] = v[b];
        else if (v[a] && v[b])
        {
            int o = v[b];
            for (int j = 0; j < 26; j ++)
            {
                if (v[j] == o) // ERROR HERE, v[b] could be changed !!!
                    v[j] = v[a];
            }
        }
        else
            v[a] = v[b] = n ++;
    }

    if (!no)
        return true;

    for (int i = 0; i < equationsSize; i ++)
    {
        char* c = equations[i];
        if (c[1] == '=')
            continue;

        int a = c[0] - 'a';
        int b = c[3] - 'a';

        if (a == b)
            return false;

        if (v[a] && v[b] && v[a] == v[b])
            return false;
    }
    return true;
}
