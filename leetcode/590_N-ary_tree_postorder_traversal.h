// BE CAREFUL, REFERENCE CAN NOT BE ASSIGN VALUE AGAIN !!!!
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
public:
    vector<int> postorder(Node* root) {
        vector<int> ret;
        if (root)
        {
            vector<int> ref_i;
            vector<vector<Node*>> ref;

            ref_i.push_back(0);
            ref.push_back(root->children);

            while(true)
            {
                int x = ref_i.back();
                vector<Node*> xs = ref.back();

                if (x >= xs.size())
                {
                    ref_i.pop_back();
                    ref.pop_back();

                    if (ref_i.size())
                    {
                        x = ref_i.back();
                        xs = ref.back();
                        ret.push_back(xs[x]->val);
                        ref_i[ref_i.size() - 1] = x + 1;
                        continue;
                    }

                    break;
                }

                Node* t = xs[x];
                if (!t->children.size())
                {
                    ret.push_back(t->val);
                    ref_i[ref_i.size() - 1] = x + 1;
                }
                else
                {
                    ref_i.push_back(0);
                    ref.push_back(t->children);
                }
            }
            ret.push_back(root->val);
        }
        return ret;
    }
};
