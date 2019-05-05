/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    void _max(Node* r, int l, int* m)
    {
        if (l > *m)
            *m = l;

        for (int i = 0; i < r->children.size(); i ++)
            _max(r->children[i], l + 1, m);
    }

 public:
    int maxDepth(Node* root) {
        int m = 0;
        if (root)
            _max(root, 1, &m);
        return m;
    }
};
