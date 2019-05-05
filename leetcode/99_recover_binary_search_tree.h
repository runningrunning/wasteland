/* void _frt(struct TreeNode* root, struct TreeNode** n1, struct TreeNode** n2) */
/* { */
/*     if (!root) */
/*         return; */

/*     if (root->left) */
/*     { */
/*         if (root->val < root->left->val) */
/*         { */
/*             if (*n1) */
/*                 *n2 = root; */
/*             else */
/*                 *n1 = root; */
/*         } */
/*         else */
/*             _frt(root->left, n1, n2); */
/*     } */

/*     if (root->right) */
/*     { */
/*         if (root->val > root->right->val) */
/*         { */
/*             if (*n1) */
/*                 *n2 = root; */
/*             else */
/*                 *n1 = root; */
/*         } */
/*         else */
/*             _frt(root->right, n1, n2); */
/*     } */
/* } */

/* void _rt(struct TreeNode* root, struct TreeNode** n1, struct TreeNode** n2) */
/* { */
/*     _frt(root, n1, n2); */

/*     int tmp; */

/*     struct TreeNode* t1 = *n1; */
/*     struct TreeNode* t2 = *n2; */
/*     struct TreeNode* p1 = NULL; */
/*     struct TreeNode* p2 = NULL; */

/*     if (!t1) */
/*         return; */

/*     if (t1->left && t1->left->val > t1->val) */
/*         p1 = t1->left; */
/*     else */
/*         p1 = t1->right; */

/*     if (!t2) */
/*     { */
/*         *n1 = NULL; */
/*         tmp = t->val; */
/*         t->val = t1->val; */
/*         _frt(t, n1, n2); */

/*         if (!*n1) */
/*         { */
/*             t1->val = tmp; */
/*             t1 = NULL; */
/*             t2 = NULL; */
/*         } */
/*         else */
/*         { */
/*             *n1 = NULL; */
/*             t->val = tmp; */
/*             _frt(t, n1, n2); */
/*             t2 = *n1; */
/*         } */
/*     } */

/*     if (t1 && t2) */
/*     { */
/*         if (t1 == t2) */
/*         { */
/*             int t = t1->left->val; */
/*             t1->left->val = t1->right->val; */
/*             t1->right->val = t; */
/*         } */
/*         else */
/*         { */
/*             struct TreeNode** p; */

/*             if (t2->left && t2->left->val > t2->val) */
/*                 p = &t2->left; */
/*             else */
/*                 p = &t2->right; */

/*             if (t == t2) */
/*             { */
/*                 t = t1; */
/*             } */
/*             else */
/*             { */
/*                 if (t)->val) */
/*             } */

/*             { */
/*                 tmp = t2->left->val; */
/*                 t2->left->val = (*t)->val; */
/*                 (*t)->val = tmp; */
/*             } */
/*             else */
/*             { */
/*                 tmp = t2->right->val; */
/*                 t2->right->val = (*t)->val; */
/*                 (*t)->val = tmp; */
/*             } */
/*         } */
/*     } */
/* } */


void _frt(struct TreeNode* r, struct TreeNode* min, struct TreeNode* max, struct TreeNode** r1, struct TreeNode** p1, struct TreeNode** r2, struct TreeNode** p2)
{
    if (!r)
        return;

    if (r->val < min->val || r->val > max->val)
    {
        struct TreeNode* t = NULL;

        if (r->val < min->val)
            t = min;
        else
            t = max;

        if (*r1)
        {
            *r2 = t;
            *p2 = r;
        }
        else
        {
            *r1 = t;
            *p1 = r;
        }
    }
    else
    {
        if (r->left)
            _frt(r->left, min, r, r1, p1, r2, p2);

        if (r->right)
            _frt(r->right, r, max, r1, p1, r2, p2);
    }
}
/*
void _rt(struct TreeNode* r)
{
    struct TreeNode* r1 = NULL;
    struct TreeNode* p1 = NULL;
    struct TreeNode* r2 = NULL;
    struct TreeNode* p2 = NULL;

    int tmp;
    struct TreeNode min;
    min.val = INT_MIN;
    min.left = NULL;
    min.right = NULL;
    struct TreeNode max;
    max.val = INT_MAX;
    max.left = NULL;
    max.right = NULL;

    _frt(r, &min, &max, &r1, &p1, &r2, &p2);

    if (!r1)
        return;

    if (!r2)
    {
        tmp = p1->val;
        p1->val = r1->val;
        r1->val = tmp;
        min.val = INT_MIN;
        max.val = INT_MAX;
        _frt(r, &min, &max, &r1, &p1, &r2, &p2);

        if (!r2)
            return;

        r1->val = p1->val;
        p1->val = tmp;
        min.val = INT_MIN;
        max.val = INT_MAX;
        r2 = NULL;
        p2 = NULL;
        _frt(p1, &min, &max, &r1, &p1, &r2, &p2);
    }

    if (r1 && r2)
    {
        if (r1 == r2)
        {
            tmp = p1->val;
            p1->val = p2->val;
            p2->val = tmp;
        }
        else if (p1 == r2)
        {
            tmp = r1->val;
            r1->val = p2->val;
            p2->val = tmp;
        }
        else
        {
            bool b1 = r1->val > p1->val;
            bool b2 = r2->val > p2->val;

            // r1 <=> r2
            if (b1 != (r2->val > p1->val)
                && b2 != (r1->val > p2->val))
            {
                // printf("try r1 <=> r2.\n");
                tmp = r1->val;
                r1->val = r2->val;
                r2->val = tmp;
            }

            // r1 <=> p2
            if (b1 != (p2->val > p1->val)
                && b2 != (r2->val > r1->val))
            {
                // printf("try r1 <=> p2.\n");
                tmp = r1->val;
                r1->val = p2->val;
                p2->val = tmp;
            }

            // p1 <=> r2
            if (b1 != (r1->val > r2->val)
                && b2 != (p1->val > p2->val))
            {
                // printf("try p1 <=> r2.\n");
                tmp = p1->val;
                p1->val = r2->val;
                r2->val = tmp;
            }

            // p1 <=> p2
            if (b1 != (r1->val > p2->val)
                && b2 != (r2->val > p1->val))
            {
                // printf("try p1 <=> p2.\n");
                tmp = p1->val;
                p1->val = p2->val;
                p2->val = tmp;
            }
        }
    }

}

*/
void _rt(struct TreeNode* r)
{
    struct TreeNode* r1 = NULL;
    struct TreeNode* p1 = NULL;
    struct TreeNode* r2 = NULL;
    struct TreeNode* p2 = NULL;

    int tmp;
    struct TreeNode min;
    min.val = INT_MIN;
    min.left = NULL;
    min.right = NULL;
    struct TreeNode max;
    max.val = INT_MAX;
    max.left = NULL;
    max.right = NULL;

    _frt(r, &min, &max, &r1, &p1, &r2, &p2);

    if (!r1)
        return;

    if (!r2)
    {
        tmp = p1->val;
        p1->val = r1->val;
        r1->val = tmp;
        min.val = INT_MIN;
        max.val = INT_MAX;
        _frt(r, &min, &max, &r1, &p1, &r2, &p2);

        if (!r2)
            return;

        r1->val = p1->val;
        p1->val = tmp;
        min.val = INT_MIN;
        max.val = INT_MAX;
        r2 = NULL;
        p2 = NULL;
        _frt(p1, &min, &max, &r1, &p1, &r2, &p2);
    }

    if (r1 && r2)
    {
        if (r1 == r2)
        {
            tmp = p1->val;
            p1->val = p2->val;
            p2->val = tmp;
        }
        else if (p1 == r2)
        {
            tmp = r1->val;
            r1->val = p2->val;
            p2->val = tmp;
        }
        else
        {
            bool b1 = r1->val > p1->val;
            bool b2 = r2->val > p2->val;
            // printf("%d %d %d %d.\n", r1->val, p1->val, r2->val, p2->val);
            // r1 <=> r2
            if (b1 != (r2->val > p1->val)
                && b2 != (r1->val > p2->val))
            {
                // printf("try r1 <=> r2.\n");
                tmp = r1->val;
                r1->val = r2->val;
                r2->val = tmp;
            }

            // r1 <=> p2
            if (b1 != (p2->val > p1->val)
                && b2 != (r2->val > r1->val))
            {
                // printf("try r1 <=> p2.\n");
                tmp = r1->val;
                r1->val = p2->val;
                p2->val = tmp;
            }

            // p1 <=> r2
            if (b1 != (r1->val > r2->val)
                && b2 != (p1->val > p2->val))
            {
                // printf("try p1 <=> r2.\n");
                tmp = p1->val;
                p1->val = r2->val;
                r2->val = tmp;
            }

            // p1 <=> p2
            if (b1 != (r1->val > p2->val)
                && b2 != (r2->val > p1->val))
            {
                // printf("try p1 <=> p2.\n");
                tmp = p1->val;
                p1->val = p2->val;
                p2->val = tmp;
            }
        }
    }
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void recoverTree(struct TreeNode* root)
{
    if (!root)
        return;

    _rt(root);
}

