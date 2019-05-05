// understand the questions !!!!!!!!!!!!
// it's nested int, every int is NestedInteger !!!!
/**
 * *********************************************************************
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * *********************************************************************
 *
 * // Initializes an empty nested list and return a reference to the nested integer.
 * struct NestedInteger *NestedIntegerInit();
 *
 * // Return true if this NestedInteger holds a single integer, rather than a nested list.
 * bool NestedIntegerIsInteger(struct NestedInteger *);
 *
 * // Return the single integer that this NestedInteger holds, if it holds a single integer
 * // The result is undefined if this NestedInteger holds a nested list
 * int NestedIntegerGetInteger(struct NestedInteger *);
 *
 * // Set this NestedInteger to hold a single integer.
 * void NestedIntegerSetInteger(struct NestedInteger *ni, int value);
 *
 * // Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
 * void NestedIntegerAdd(struct NestedInteger *ni, struct NestedInteger *elem);
 *
 * // Return the nested list that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);
 *
 * // Return the nested list's size that this NestedInteger holds, if it holds a nested list
 * // The result is undefined if this NestedInteger holds a single integer
 * int NestedIntegerGetListSize(struct NestedInteger *);
 * };
 */

void _de(char* s, int* i, struct NestedInteger** r)
{
    int ti = *i;
    struct NestedInteger* ci = *r;

    while(true)
    {
        if (s[ti] == '[')
        {
            struct NestedInteger* t = NestedIntegerInit();

            if (ci)
                NestedIntegerAdd(ci, t);
            else
                *r = t;
            *i = ti + 1;
            _de(s, i, &t);
            ti = *i;
        }

        if (!s[ti] || s[ti] == ']')
            break;

        if (s[ti] == '[')
            continue;

        int x = 0;
        bool negative = false;

        if (s[ti] == '-')
        {
            negative = true;
            ti ++;
        }

        while (s[ti] >= '0' && s[ti] <= '9')
        {
            x = x * 10 + s[ti] - '0';
            ti ++;
        }

        if (negative)
            x = -x;

        if (s[ti] == ',')
            ti ++;

        struct NestedInteger* t = NestedIntegerInit();
        NestedIntegerSetInteger(t, x);
        if (ci)
            NestedIntegerAdd(ci, t);
        else
        {
            *r = t;
            ci = t;
        }
    }
    if (s[ti] == ']')
        *i = ti + (s[ti + 1] == ',' ? 2: 1);
}

struct NestedInteger* deserialize(char* s)
{
    int i = 0;
    struct NestedInteger* r = NULL;
    _de(s, &i, &r);
    return r;
}
