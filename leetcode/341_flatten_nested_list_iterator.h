// use queue ?
// use common  data structure !!
// try optimize CPP code
// It's wrong C interface !!!!!!!!!!!!
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    int si;
    vector<vector<NestedInteger>> st;
    vector<int> sis;
    vector<int> sts;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        si = 0;
        st.push_back(nestedList);
        sis.push_back(0);
        sts.push_back(nestedList.size());
    }

    bool _step()
    {
        int _si = si;
        int c = sis[_si];
        int l = sts[_si];

        while (c < l)
        {
            NestedInteger n = st[_si][c];
            if (n.isInteger())
                return true;
            sis[_si] = ++ c;
            si ++;
            st.resize(si + 1);
            sis.resize(si + 1);
            sts.resize(si + 1);
            st[si] = n.getList();
            sis[si] = 0;
            sts[si] = n.getList().size();
            if (_step())
                return true;
            si = _si;
        }
        si --;
        return false;
    }
    bool step()
    {
        while (si >= 0)
        {
            if (_step())
                return true;
        }
        return false;
    }

    int next() {
        int x = st[si][sis[si]].getInteger();
        sis[si] ++;
        step();
        return x;
    }

    bool hasNext() {
        if (si < 0)
            return false;
        return step();
    }
};

/*  * Your NestedIterator object will be instantiated and called as such: */
/*  * NestedIterator i(nestedList); */
/*  * while (i.hasNext()) cout << i.next(); */
/*  *\/ */


/* /\* complicated, do more times ! *\/ */
/* /\* corner cases !! *\/ */
/* // stupid error here, always realloc then refer the old value !!! */

/* /\** */
/*  * ********************************************************************* */
/*  * // This is the interface that allows for creating nested lists. */
/*  * // You should not implement it, or speculate about its implementation */
/*  * ********************************************************************* */
/*  * */
/*  * // Return true if this NestedInteger holds a single integer, rather than a nested list. */
/*  * bool NestedIntegerIsInteger(struct NestedInteger *); */
/*  * */
/*  * // Return the single integer that this NestedInteger holds, if it holds a single integer */
/*  * // The result is undefined if this NestedInteger holds a nested list */
/*  * int NestedIntegerGetInteger(struct NestedInteger *); */
/*  * */
/*  * // Return the nested list that this NestedInteger holds, if it holds a nested list */
/*  * // The result is undefined if this NestedInteger holds a single integer */
/*  * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *); */
/*  * */
/*  * // Return the nested list's size that this NestedInteger holds, if it holds a nested list */
/*  * // The result is undefined if this NestedInteger holds a single integer */
/*  * int NestedIntegerGetListSize(struct NestedInteger *); */
/*  * }; */
/*  *\/ */

/* struct NestedIterator { */
/*     int si; */
/*     int ss; */
/*     struct NestedInteger*** st; */
/*     int* sis; */
/*     int* sts; */
/* }; */

/* bool _step(struct NestedIterator* i) */
/* { */
/*     int si = i->si; */
/*     int c = i->sis[si]; */
/*     int l = i->sts[si]; */
/*     while (c < l) */
/*     { */
/*         struct NestedInteger* cn = i->st[si][c]; */
/*         if (NestedIntegerIsInteger(cn)) */
/*             return true; */

/*         if (si + 1 == i->ss) */
/*         { */
/*             i->ss += 1024; */
/*             i->st = realloc(i->st, sizeof(struct NestedInteger**) * i->ss); */
/*             i->sis = realloc(i->sis, sizeof(int) * i->ss); */
/*             i->sts = realloc(i->sts, sizeof(int) * i->ss); */
/*         } */

/*         i->si ++; */
/*         i->st[i->si] = NestedIntegerGetList(cn); */
/*         i->sis[i->si] = 0; */
/*         i->sts[i->si] = NestedIntegerGetListSize(cn); */
/*         i->sis[si] = ++ c; */

/*         if (_step(i)) */
/*             return true; */

/*         i->si = si; */
/*     } */

/*     i->si = si - 1; */
/*     return false; */
/* } */

/* struct NestedIterator *nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize) { */
/*     struct NestedIterator* i = malloc(sizeof(struct NestedIterator)); */
/*     i->si = 0; */
/*     i->ss = 1024; */
/*     i->st = malloc(sizeof(struct NestedInteger**) * i->ss); */
/*     i->sis = malloc(sizeof(int) * i->ss); */
/*     i->sts = malloc(sizeof(int) * i->ss); */
/*     i->st[0] = nestedList; */
/*     i->sis[0] = 0; */
/*     i->sts[0] = nestedListSize; */
/*     _step(i); */
/*     return i; */
/* } */

/* bool nestedIterHasNext(struct NestedIterator *iter) */
/* { */
/*     if (iter->si < 0) */
/*         return false; */
/*     return _step(iter); */
/* } */

/* int nestedIterNext(struct NestedIterator *iter) */
/* { */
/*     int x = NestedIntegerGetInteger(iter->st[iter->si][iter->sis[iter->si]]); */
/*     iter->sis[iter->si] ++; */
/*     _step(iter); */
/*     return x; */
/* } */

/* /\** Deallocates memory previously allocated for the iterator *\/ */
/* void nestedIterFree(struct NestedIterator *iter) { */
/*     if (iter) */
/*     { */
/*         free(iter->st); */
/*         free(iter->sts); */
/*         free(iter->sis); */
/*         free(iter); */
/*     } */
/* } */

/* /\** */
/*  * Your NestedIterator will be called like this: */
/*  * struct NestedIterator *i = nestedIterCreate(nestedList, nestedListSize); */
/*  * while (nestedIterHasNext(i)) printf("%d\n", nestedIterNext(i)); */
/*  * nestedIterFree(i); */
/*  *\/ */


/* /\* /\\** *\/ */
/* /\*  * ********************************************************************* *\/ */
/* /\*  * // This is the interface that allows for creating nested lists. *\/ */
/* /\*  * // You should not implement it, or speculate about its implementation *\/ */
/* /\*  * ********************************************************************* *\/ */
/* /\*  * *\/ */
/* /\*  * // Return true if this NestedInteger holds a single integer, rather than a nested list. *\/ */
/* /\*  * bool NestedIntegerIsInteger(struct NestedInteger *); *\/ */
/* /\*  * *\/ */
/* /\*  * // Return the single integer that this NestedInteger holds, if it holds a single integer *\/ */
/* /\*  * // The result is undefined if this NestedInteger holds a nested list *\/ */
/* /\*  * int NestedIntegerGetInteger(struct NestedInteger *); *\/ */
/* /\*  * *\/ */
/* /\*  * // Return the nested list that this NestedInteger holds, if it holds a nested list *\/ */
/* /\*  * // The result is undefined if this NestedInteger holds a single integer *\/ */
/* /\*  * struct NestedInteger **NestedIntegerGetList(struct NestedInteger *); *\/ */
/* /\*  * *\/ */
/* /\*  * // Return the nested list's size that this NestedInteger holds, if it holds a nested list *\/ */
/* /\*  * // The result is undefined if this NestedInteger holds a single integer *\/ */
/* /\*  * int NestedIntegerGetListSize(struct NestedInteger *); *\/ */
/* /\*  * }; *\/ */
/* /\*  *\\/ *\/ */
/* /\* struct NestedIterator { *\/ */
/* /\*     int next; *\/ */
/* /\*     int stack_size; *\/ */
/* /\*     int stack_index; *\/ */
/* /\*     int* index_stack; *\/ */
/* /\*     int* size_stack; *\/ */
/* /\*     struct NestedInteger*** stack; *\/ */
/* /\* }; *\/ */

/* /\* bool tryNext(struct NestedIterator *iter) *\/ */
/* /\* { *\/ */
/* /\*     int index; *\/ */
/* /\*     int s_index = iter->stack_index; *\/ */

/* /\*     while (s_index >= 0) *\/ */
/* /\*     { *\/ */
/* /\*         index = iter->index_stack[s_index]; *\/ */
/* /\*         if (index < iter->size_stack[s_index]) *\/ */
/* /\*             break; *\/ */
/* /\*         s_index --; *\/ */
/* /\*     } *\/ */

/* /\*     iter->stack_index = s_index; *\/ */
/* /\*     if (s_index < 0) *\/ */
/* /\*         return false; *\/ */

/* /\*     struct NestedInteger* in = iter->stack[s_index][index]; *\/ */

/* /\*     /\\* find the next *\\/ *\/ */
/* /\*     while (!NestedIntegerIsInteger(in)) *\/ */
/* /\*     { *\/ */
/* /\*         iter->index_stack[s_index] ++; *\/ */
/* /\*         s_index = ++ iter->stack_index; *\/ */
/* /\*         if (s_index == iter->stack_size) *\/ */
/* /\*         { *\/ */
/* /\*             iter->stack_size += 4096; *\/ */
/* /\*             iter->stack = realloc(iter->stack, sizeof(struct NestedInteger**) * iter->stack_size); *\/ */
/* /\*             iter->size_stack = realloc(iter->size_stack, sizeof(int) * iter->stack_size); *\/ */
/* /\*             iter->index_stack = realloc(iter->index_stack, sizeof(int) * iter->stack_size); *\/ */
/* /\*         } *\/ */

/* /\*         struct NestedInteger** in_list = NestedIntegerGetList(in); *\/ */
/* /\*         int in_size = NestedIntegerGetListSize(in); *\/ */

/* /\*         if (!in_size) *\/ */
/* /\*         { *\/ */
/* /\*             -- s_index; *\/ */

/* /\*             while (s_index >= 0) *\/ */
/* /\*             { *\/ */
/* /\*                 index = iter->index_stack[s_index]; *\/ */
/* /\*                 if (index < iter->size_stack[s_index]) *\/ */
/* /\*                     break; *\/ */
/* /\*                 s_index --; *\/ */
/* /\*             } *\/ */
/* /\*             iter->stack_index = s_index; *\/ */

/* /\*             if (s_index < 0) *\/ */
/* /\*                 return false; *\/ */

/* /\*             in = iter->stack[s_index][index]; *\/ */
/* /\*         } *\/ */
/* /\*         else *\/ */
/* /\*         { *\/ */
/* /\*             iter->stack[s_index] = in_list; *\/ */
/* /\*             iter->size_stack[s_index] = in_size; *\/ */
/* /\*             iter->index_stack[s_index] = 0; *\/ */
/* /\*             in = in_list[0]; *\/ */
/* /\*         } *\/ */
/* /\*     } *\/ */

/* /\*     iter->next = NestedIntegerGetInteger(in); *\/ */
/* /\*     return true; *\/ */
/* /\* } *\/ */

/* /\* struct NestedIterator *nestedIterCreate(struct NestedInteger** nestedList, int nestedListSize) { *\/ */
/* /\*     struct NestedIterator* iter = malloc(sizeof(struct NestedIterator)); *\/ */
/* /\*     iter->stack_index = 0; *\/ */
/* /\*     iter->stack_size = 1024; *\/ */
/* /\*     iter->stack = malloc(sizeof(struct NestedInteger**) * iter->stack_size); *\/ */
/* /\*     iter->size_stack = malloc(sizeof(int) * iter->stack_size); *\/ */
/* /\*     iter->index_stack = malloc(sizeof(int) * iter->stack_size); *\/ */

/* /\*     iter->stack[0] = nestedList; *\/ */
/* /\*     iter->index_stack[0] = 0; *\/ */
/* /\*     iter->size_stack[0] = nestedListSize; *\/ */

/* /\*     /\\* try to find the next *\\/ *\/ */
/* /\*     if (!tryNext(iter)) *\/ */
/* /\*         iter->stack_index = -1; *\/ */
/* /\*     return iter; *\/ */
/* /\* } *\/ */

/* /\* bool nestedIterHasNext(struct NestedIterator *iter) { *\/ */
/* /\*     if (!iter || iter->stack_index < 0) *\/ */
/* /\*         return false; *\/ */
/* /\*     return true; *\/ */
/* /\* } *\/ */

/* /\* int nestedIterNext(struct NestedIterator *iter) { *\/ */
/* /\*     /\\* if (!iter || !nestedIterHasNext(iter)) *\\/ *\/ */
/* /\*     /\\*     return 0; *\\/ *\/ */
/* /\*     int val = iter->next; *\/ */
/* /\*     iter->index_stack[iter->stack_index] ++; *\/ */
/* /\*     tryNext(iter); *\/ */
/* /\*     return val; *\/ */
/* /\* } *\/ */

/* /\* /\\** Deallocates memory previously allocated for the iterator *\\/ *\/ */
/* /\* void nestedIterFree(struct NestedIterator *iter) { *\/ */
/* /\*     if (iter) *\/ */
/* /\*     { *\/ */
/* /\*         free(iter->index_stack); *\/ */
/* /\*         free(iter->size_stack); *\/ */
/* /\*         free(iter->stack); *\/ */
/* /\*         free(iter); *\/ */
/* /\*     } *\/ */
/* /\* } *\/ */

/* /\* /\\** *\/ */
/* /\*  * Your NestedIterator will be called like this: *\/ */
/* /\*  * struct NestedIterator *i = nestedIterCreate(nestedList, nestedListSize); *\/ */
/* /\*  * while (nestedIterHasNext(i)) printf("%d\n", nestedIterNext(i)); *\/ */
/* /\*  * nestedIterFree(i); *\/ */
/* /\*  *\\/ *\/ */
