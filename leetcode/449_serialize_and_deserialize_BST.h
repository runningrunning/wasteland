/* 297 BT */
/* this BST */
/* NULL Node */
/* Thinking too much, this one is simpler than 297. */
/* It's BST, binary search tree !!! */
/* So we can just store every INT value from root to leaf, then recreate it agian */
/* Take care of INT_MAX INT_MIN and overflow of byte char converting */
/* should find simpler way to solve this function, it BST, not BT */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
    int ri = 0;
    int rn = 4196;
    char* ret = malloc(rn);

    if (!root)
    {
        ret[0] = 'Z';
        ret[1] = 0;
        return ret;
    }

    int si = 0;
    int sn = 2048;
    struct TreeNode** stack = malloc(sizeof(struct TreeNode*) * sn);

    stack[si ++] = root;

    while (si)
    {
        if (si == sn)
        {
            sn += 2048;
            stack = realloc(stack, sizeof(struct TreeNode*) * sn);
        }

        struct TreeNode* t = stack[-- si];

        char type = 'N';
        if (t->left && t->right)
            type = 'A';
        else if (t->left)
            type = 'L';
        else if (t->right)
            type = 'R';

        if (ri + 16 >= rn)
        {
            rn += 4096;
            ret = realloc(ret, rn);
        }

        long val = (long) t->val;
        ret[ri ++] = type;

        if (val < 0)
        {
            val = - val;
            ret[ri ++] = 'M';
        }

        do
        {
            ret[ri ++] = 'Z' + val % 100;
            val /= 100;
        } while(val);

        if (t->right)
            stack[si ++] = t->right;

        if (t->left)
            stack[si ++] = t->left;
    }

    ret[ri] = 0;
    return ret;
}


/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    struct TreeNode* root = NULL;

    if (data[0] == 'Z')
        return root;

    root = malloc(sizeof(struct TreeNode));

    int i = 0;
    int si = -1;
    int sn = 2048;
    struct TreeNode** stack = malloc(sizeof(struct TreeNode*) * sn);
    stack[si ++] = root;

    while(data[i])
    {
        if (si == sn)
        {
            sn += 2048;
            stack = realloc(stack, sizeof(struct TreeNode*) * sn);
        }

        struct TreeNode* s = stack[ -- si];
        s->left = s->right = NULL;

        char type = data[i];

        if (type == 'A' || type == 'R')
        {
            stack[si ++] = malloc(sizeof(struct TreeNode));
            s->right = stack[si - 1];
        }

        if (type == 'A' || type == 'L')
        {
            stack[si ++] = malloc(sizeof(struct TreeNode));
            s->left = stack[si - 1];
        }

        i ++;

        bool minus = false;
        if (data[i] == 'M')
        {
            minus = true;
            i ++;
        }

        long val = 0;
        int level = 1;
        while (true)
        {
            int r = data[i] & 0xFF;
            if (r < 'Z')
                break;

            val += (r - 'Z') * level;
            level *= 100;
            i ++;
        }

        if (minus)
            val = -val;

        s->val = val;
    }

    return root;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
