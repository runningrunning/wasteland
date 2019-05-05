// WHY JAVA IS FASTER THAN C !!
// BECAUSE THEY ADD MORE TCs ??????
// DO MORE TIMES !
// STUPID ME !!!!!!!
// !!!!!!!!!!!!!!! FIND THE 4ms SOLUTION !!!!!!!!!
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// think too much !!!!!!!!!
// stupid wrong algorithm
// INT_MAX / 8500 / 8500 = 29
// just scan, no need to do dynamic comparing

// int m[] = {3, 9, 20, 0, 0, 15, 7};
// IT'S NOT THE SHORTEST STRING WINS, it's the smallest wins !!
// REALLY REALLY STUPID ME !!!!

#define _MAX 8501
void _sml(struct TreeNode* n, char* s, int* sn, char* c, int cn)
{
    if (!n->left && !n->right)
    {
        c[cn ++] = n->val + 'a';
        if (!(*sn))
        {
            memcpy(s, c, cn);
            *sn = cn;
        }
        else
        {
            int is = (*sn) - 1;
            int ic = cn - 1;

            do {
                if (s[is] < c[ic])
                    break;

                if (s[is] > c[ic])
                {
                    memcpy(s, c, cn);
                    *sn = cn;
                    break;
                }
                is --;
                ic --;

            } while (is >= 0 && ic >= 0);

            if (ic < 0)
            {
                memcpy(s, c, cn);
                *sn = cn;
            }
        }
    }
    else
    {
        c[cn] = n->val + 'a';
        if (n->left)
            _sml(n->left, s, sn, c, cn + 1);
        if (n->right)
            _sml(n->right, s, sn, c, cn + 1);
    }
}

char* smallestFromLeaf(struct TreeNode* root)
{
    char* s = malloc(sizeof(char) * _MAX);
    int sl = 0;
    char* c = malloc(sizeof(char) * _MAX);
    int cl = 0;
    _sml(root, s, &sl, c, cl);
    for (int i = 0; i < sl; i ++)
        c[i] = s[sl - 1 - i];
    c[sl] = 0;
    return c;
}

// char* smallestFromLeaf(struct TreeNode* root)
// {
//     int sn = 1024;
//     struct TreeNode** stack = malloc(sizeof(struct TreeNode*) * sn);
//     int cn = 1024;
//     int ci = 0;
//     int cc = INT_MAX;
//     int* cs = malloc(sizeof(int) * cn);

//     int si = 0;
//     stack[si ++] = root;
//     int sc = 0;

//     root->val += 0xFFFF << 5;
//     while (sc < si)
//     {
//         struct TreeNode* s = stack[sc];

//         if (s->left)
//         {
//             s->left->val += sc << 5;
//             if (si >= sn)
//             {
//                 sn += 1024;
//                 stack = realloc(stack, sizeof(struct TreeNode*) * sn);
//             }
//             stack[si ++] = s->left;
//         }

//         if (s->right)
//         {
//             s->right->val += sc << 5;
//             if (si >= sn)
//             {
//                 sn += 1024;
//                 stack = realloc(stack, sizeof(struct TreeNode*) * sn);
//             }
//             stack[si ++] = s->right;
//         }

//         if (!s->left && !s->right)
//         {
//             if (cc > (s->val & 0x1F))
//             {
//                 ci = 1;
//                 cs[0] = sc;
//                 cc = s->val & 0x1F;
//             }
//             else if (cc == (s->val & 0x1F))
//             {
//                 if (ci == cn)
//                 {
//                     cn += 1024;
//                     cs = realloc(cs, sizeof(int) * cn);
//                 }
//                 cs[ci ++] = sc;
//             }
//         }
//         sc ++;
//     }

//     int c = cs[0];
//     for (int i = 1; i < ci; i ++)
//     {
//         int a = c;
//         int b = cs[i];

//         do
//         {
//             int _a = stack[a]->val & 0x1F;
//             int _b = stack[b]->val & 0x1F;
//             if (_a == _b)
//             {
//                 a = stack[a]->val >> 5;
//                 b = stack[b]->val >> 5;
//             }
//             else
//             {
//                 if (_b < _a)
//                     c = cs[i];
//                 break;
//             }
//         } while (a != 0xFFFF && b != 0xFFFF);

//         if (b == 0xFFFF)
//             c = cs[i];
//     }

//     int ti = 0;
//     char* t = NULL;

//     do
//     {
//         t = realloc(t, sizeof(char) * (ti + 1));
//         t[ti ++] = (stack[c]->val & 0x1F) + 'a';
//         c = stack[c]->val >> 5;
//     } while(c != 0xFFFF);

//     t = realloc(t, sizeof(char) * (ti + 1));
//     t[ti] = 0;
//     return t;
// }

// char* smallestFromLeaf(struct TreeNode* root)
// {
//     int sn = 1024;
//     struct TreeNode** stack = malloc(sizeof(struct TreeNode*) * sn);
//     int* istack = malloc(sizeof(int) * sn);
//     int si = 0;
//     istack[si] = 0;
//     stack[si ++] = root;

//     int lv = 0;
//     int sc = 0;
//     int slv = INT_MAX;

//     while(sc < si)
//     {
//         struct TreeNode* s = stack[sc];
//         int _lv = istack[sc] >> 16;
//         if (_lv > slv)
//         {
//             sc --;
//             break;
//         }

//         if (s->left)
//         {
//             if (si >= sn)
//             {
//                 sn += 1024;
//                 stack = realloc(stack, sizeof(struct TreeNode*) * sn);
//                 istack = realloc(istack, sizeof(int) * sn);
//             }
//             stack[si] = s->left;
//             istack[si] = (_lv + 1) << 16 | sc;

//             si ++;
//         }

//         if (s->right)
//         {
//             if (si >= sn)
//             {
//                 sn += 1024;
//                 stack = realloc(stack, sizeof(struct TreeNode*) * sn);
//                 istack = realloc(istack, sizeof(int) * sn);
//             }
//             stack[si] = s->right;
//             istack[si] = (_lv + 1) << 16 | sc;
//             si ++;
//         }

//         if (!s->right && !s->left && slv == INT_MAX)
//             slv = _lv;
//         sc ++;
//     }

//     if (sc == si)
//         sc --;

//     int cs = -1;

//     while(sc >= 0)
//     {
//         struct TreeNode* s = stack[sc];
//         int _lv = istack[sc] >> 16;
//         if (_lv < slv)
//             break;

//         if (!stack[sc]->left && !stack[sc]->right)
//         {

//             if (cs == -1)
//                 cs = sc;
//             else
//             {
//                 if (stack[cs]->val == stack[sc]->val)
//                 {
//                     int _a = cs;
//                     int _b = sc;
//                     for (int i = _lv; i > 0; i --)
//                     {
//                         _a = istack[_a] & 0xFFFF;
//                         _b = istack[_b] & 0xFFFF;
//                         if (stack[_a]->val < stack[_b]->val)
//                             break;
//                         if (stack[_a]->val > stack[_b]->val)
//                         {
//                             cs = sc;
//                             break;
//                         }
//                     }
//                 }
//                 cs = stack[cs]->val < stack[sc]->val ? cs : sc;
//             }
//         }
//         sc --;
//     }

//     char* t = malloc(sizeof(char) * (slv + 2));
//     t[slv + 1] = 0;

//     int in = 0;
//     for (int i = slv; i >= 0; i --)
//     {
//         t[in ++] = stack[cs]->val + 'a';
//         cs = istack[cs] & 0xFFFF;
//     }

//     return t;
// }
