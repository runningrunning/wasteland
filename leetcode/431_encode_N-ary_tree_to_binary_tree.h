/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void _encode(TreeNode** t, Node* r, bool left)
    {
        (*t) = new TreeNode(r->val);

        int s = r->children.size();

        if (!s)
            return;

        TreeNode* x = *t;

        for (int i = 0; i < s; i ++)
        {
            if (left)
            {
                x->left = new TreeNode(r->children[i]->val);
                _encode(&x->right, r->children[i], !left);
                x = x->left;
            }
            else
            {
                x->right = new TreeNode(r->children[i]->val);
                _encode(&x->left, r->children[i], !left);
                x = x->right;
            }
        }
    }

    void _decode(Node** t, TreeNode* r, bool left)
    {
        (*t) = new Node(r->val, vector<Node*>());
        TreeNode* x = NULL;
        x = left ? r->left : r->right;

        if (!x)
            return;

        while (x)
        {
            Node* n = NULL;
            _decode(&n, x, !left);
            (*t)->children.push_back(n);
            x = left ? x->left : x->right;
        }
    }

    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root)
            return NULL;
        TreeNode* r = NULL;
        _encode(&r, root, false);
        return r;
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (!root)
            return NULL;
        Node* r = NULL;
        _decode(&r, root, false);
        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
