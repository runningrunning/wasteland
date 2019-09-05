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
class Solution {
    void _lo(Node* r, vector<vector<int>>& t, int l)
    {
        if (t.size() < l + 1)
        {
            vector<int> s;
            t.push_back(s);
        }

        vector<int> x = t[l];
        x.push_back(r->val);

        for (int i = 0; i < r->children.size(); i ++)
            _lo(r->children[i], t, l + 1);
    }

 public:
    vector<vector<int>> levelOrder(Node* root) { 
       vector<vector<int>> t;
        if (root)
            _lo(root, t, 0);
        return t;
    }
};
