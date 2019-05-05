/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    void _ttdl(Node* r, Node*** post, Node** pre, Node** s, Node** e)
    {
        if (r->left)
            _ttdl(r->left, post, pre, s, e);

        if (!(*s))
            *s = r;
        *e = r;

        (*(*post)) = r;
        *post = &(r->right);
        r->left = *pre;
        *pre = r;

        if (r->right)
            _ttdl(r->right, post, pre, s, e);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return NULL;
        Node* s = NULL;
        Node** ps = &s;
        Node*** pps = &ps;
        Node* rs = NULL;
        Node* re = NULL;
        Node* t = NULL;
        _ttdl(root, pps, &t, &rs, &re);
        rs->left = re;
        re->right = rs;

        return rs;
    }
};

/* typedef struct TreeNode Node; */
/* void _ttdl(Node* r, Node*** post, Node** pre, Node** s, Node** e) */
/* { */
/*     if (r->left) */
/*         _ttdl(r->left, post, pre, s, e); */

/*     if (!(*s)) */
/*         *s = r; */

/*     *e = r; */
/*     (*(*post)) = r; */
/*     *post = &(r->right); */
/*     r->left = *pre; */
/*     *pre = r; */

/*     if (r->right) */
/*         _ttdl(r->right, post, pre, s, e); */
/* } */
