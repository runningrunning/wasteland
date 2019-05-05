/* TODO make if faster */
void _cmbt_sort(int* nums, int s, int e, int* ids)
{
    if (s >= e)
    {
        return;
    }

    int t;

    if (nums[s] > nums[e])
    {
        t = nums[e];
        nums[e] = nums[s];
        nums[s] = t;

        t = ids[e];
        ids[e] = ids[s];
        ids[s] = t;
    }

    if (s + 1 == e)
        return;

    int cs = s;
    int ce = e;

    for (int i = s + 1; i <= e; i ++)
    {
        while(nums[i] < nums[s]) i ++;
        while(nums[e] > nums[s]) e --;

        if (i >= e)
        {
            t = nums[e];
            nums[e] = nums[s];
            nums[s] = t;

            t = ids[e];
            ids[e] = ids[s];
            ids[s] = t;
        }
        else
        {
            t = nums[e];
            nums[e] = nums[i];
            nums[i] = t;

            t = ids[e];
            ids[e] = ids[i];
            ids[i] = t;
        }
    }

    _cmbt_sort(nums, cs, e - 1, ids);
    _cmbt_sort(nums, e + 1, ce, ids);
}


void _cmbt(struct TreeNode* r, int* nums)
{
    r->val = nums[r->val];
    if (r->left)
        _cmbt(r->left, nums);
    if (r->right)
        _cmbt(r->right, nums);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize)
{
    if (!numsSize)
        return NULL;

    int* orgs = malloc(sizeof(int) * numsSize);
    memcpy(orgs, nums, sizeof(int) * numsSize);
    int* ids = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i ++)
        ids[i] = i;
    out(nums, numsSize);
    out(ids, numsSize);
    _cmbt_sort(nums, 0, numsSize - 1, ids);
    out(nums, numsSize);
    out(ids, numsSize);

    struct TreeNode* r = malloc(sizeof(struct TreeNode));
    r->val = ids[numsSize - 1];
    r->left = NULL;
    r->right = NULL;
    struct TreeNode* p = NULL;
    struct TreeNode* t = r;

    for (int i = 1; i < numsSize; i ++)
    {
        int c = ids[numsSize - 1 - i];
        t = r;

        while(t)
        {
            p = t;
            if (c > t->val)
                t = t->right;
            else
                t = t->left;
        }

        t = malloc(sizeof(struct TreeNode));
        t->val = c;
        t->left = NULL;
        t->right = NULL;

        if (c > p->val)
            p->right = t;
        else
            p->left = t;
    }
    _cmbt(r, orgs);
    return r;
}
