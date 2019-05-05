/* // C++ VERSION WORKS, C VERSION RUN TIME ERROR */
// HINT DON'T FREE THE MEMORY ALLOCATE BY THE TEST CASE !!!

/* /\** */
/*  * Definition for a binary tree node. */
/*  * struct TreeNode { */
/*  *     int val; */
/*  *     TreeNode *left; */
/*  *     TreeNode *right; */
/*  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {} */
/*  * }; */
/*  *\/ */

/* void _num(struct TreeNode* r, int n, int* num) */
/* { */
/*     if (*num < n) */
/*         *num = n; */

/*     if (r->left) */
/*         _num(r->left, n * 2 + 1, num); */

/*     if (r->right) */
/*         _num(r->right, n * 2 + 2, num); */
/* } */

/* void _free(struct TreeNode* n) */
/* { */
/*     if (n->left) */
/*         _free(n->left); */
/*     if (n->right) */
/*         _free(n->right); */
/*     _free(n); */
/* } */

/* void _insert(struct TreeNode* r, int num, int l, int v, int* p) */
/* { */
/*     struct TreeNode** t = NULL; */
/*     if (num & (1 << l)) */
/*         t = &(r->right); */
/*     else */
/*         t = &(r->left); */

/*     *p = r->val; */

/*     if (l) */
/*         _insert(*t, num, l - 1, v, p); */
/*     else */
/*     { */
/*         struct TreeNode* n = (struct TreeNode*) malloc(sizeof(struct TreeNode)); */
/*         n->left = n->right = NULL; */
/*         n->val = v; */
/*         *t = n; */
/*     } */
/* } */

/* class CBTInserter { */
/*     int num; */
/*     TreeNode* root; */
/* public: */
/*     CBTInserter(TreeNode* _root) { */
/*         root = _root; */
/*         num = 0; */
/*         _num(root, 0, &num); */
/*     } */
/*     int insert(int v) { */
/*         int p = 0; */
/*         num ++; */
/*         int level = num + 1; */
/*         int i = 16; */
/*         for (; i >= 0; i --) */
/*             if (level & (1 << i)) */
/*                 break; */
/*         _insert(root, num + 1, i - 1, v, &p); */
/*         return p; */
/*     } */

/*     TreeNode* get_root() { */
/*         return root; */
/*     } */
/* }; */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct {
    int num;
    struct TreeNode* root;
} CBTInserter;

void _num(struct TreeNode* r, int n, int* num)
{
    if (*num < n)
        *num = n;
    if (r->left)
        _num(r->left, n * 2 + 1, num);
    if (r->right)
        _num(r->right, n * 2 + 2, num);
}

CBTInserter* cBTInserterCreate(struct TreeNode* root) {
    CBTInserter* c = malloc(sizeof(CBTInserter));
    c->root = root;
    c->num = 0;
    _num(c->root, 0, &c->num);
    return c;
}

void _insert(struct TreeNode* r, int num, int l, int v, int* p)
{
    struct TreeNode** t = NULL;

    if (num & (1 << l))
        t = &(r->right);
    else
        t = &(r->left);

    *p = r->val;

    if (l)
        _insert(*t, num, l - 1, v, p);
    else
    {
        struct TreeNode* n = malloc(sizeof(struct TreeNode));
        n->left = n->right = NULL;
        n->val = v;
        *t = n;
    }
}

int cBTInserterInsert(CBTInserter* obj, int v) {
    int p = 0;

    if (obj)
    {
        obj->num ++;
        int level = obj->num + 1;
        int i = 16;
        for (; i >= 0; i --)
            if (level & (1 << i))
                break;
        _insert(obj->root, obj->num + 1, i - 1, v, &p);
    }
    return p;
}

struct TreeNode* cBTInserterGet_root(CBTInserter* obj) {
    return obj->root;
}

/* void _free(struct TreeNode* n) */
/* { */
/*     if (n->left) */
/*         _free(n->left); */
/*     if (n->right) */
/*         _free(n->right); */
/*     _free(n); */
/* } */

void cBTInserterFree(CBTInserter* obj) {
    if (obj)
    {
        /* if (obj->root) */
        /*     _free(obj->root); */
        free(obj);
    }
}

/**
 * Your CBTInserter struct will be instantiated and called as such:
 * struct CBTInserter* obj = cBTInserterCreate(root);
 * int param_1 = cBTInserterInsert(obj, v);
 * struct TreeNode* param_2 = cBTInserterGet_root(obj);
 * cBTInserterFree(obj);
 */
