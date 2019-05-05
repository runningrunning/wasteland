// be more careful, just simple BST, don't look at the value
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (node->right)
        {
            Node* p = node->right;
            while (p->left)
                p = p->left;
            return p;
        }
        if (!node->parent)
            return NULL;
        if (node->parent->right == node)
        {
            Node* p = node->parent;
            while (p->parent && p->parent->right == p)
                p = p->parent;
            return p->parent;
        }
        return node->parent;
    }
};
