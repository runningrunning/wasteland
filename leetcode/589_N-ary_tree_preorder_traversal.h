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

    // void _pre(Node* r, vector<int>& v)
    // {
    //     if (r)
    //     {
    //         v.push_back(r->val);
    //         for (int i = 0; i < r->children.size(); i ++)
    //             _pre(r->children[i], v);
    //     }
    // }

 public:

    vector<int> preorder(Node* root) {
        vector<int> t;

        if (root)
        {
            vector<Node*> stack;
            stack.push_back(root);

            while (stack.size())
            {
                Node* x = stack.back();
                t.push_back(x->val);
                stack.pop_back();
                int s = x->children.size();
                for (int i = s - 1; i >= 0; i --)
                    stack.push_back(x->children[i]);
            }
        }

        return t;
    }
};
