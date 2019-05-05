// REMEMBER TO MERGE !!!!!!!!!!!!!!!!!
// 1. remember to merge same result into one node. !!!!!!!!
// 2. Value doesn't mean anything for not Leaf node, default to TRUE

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
    void dup(Node* n1, Node** r)
    {
        *r = new Node(n1->val, n1->isLeaf, NULL, NULL, NULL, NULL);
        if (n1->isLeaf)
            return;

        dup(n1->topLeft, &(*r)->topLeft);
        dup(n1->topRight, &(*r)->topRight);
        dup(n1->bottomLeft, &(*r)->bottomLeft);
        dup(n1->bottomRight, &(*r)->bottomRight);
    }

    void is(Node* n1, Node* n2, Node** r)
    {
        if (n1->isLeaf || n2->isLeaf)
        {
            if (n1->isLeaf && n2->isLeaf)
                *r = new Node(n1->val || n2->val, true, NULL, NULL, NULL, NULL);
            else if (n1->isLeaf)
            {
                if (n1->val)
                    *r = new Node(n1->val || n2->val, true, NULL, NULL, NULL, NULL);
                else
                    dup(n2, r);
            }
            else
            {
                if (n2->val)
                    *r = new Node(n1->val || n2->val, true, NULL, NULL, NULL, NULL);
                else
                    dup(n1, r);
            }
        }
        else
        {
            *r = new Node(n1->val || n2->val, false, NULL, NULL, NULL, NULL);
            is(n1->topLeft, n2->topLeft, &(*r)->topLeft);
            is(n1->topRight, n2->topRight, &(*r)->topRight);
            is(n1->bottomLeft, n2->bottomLeft, &(*r)->bottomLeft);
            is(n1->bottomRight, n2->bottomRight, &(*r)->bottomRight);

            if ((*r)->topLeft->isLeaf && (*r)->topLeft->val
                && (*r)->topRight->isLeaf && (*r)->topRight->val
                && (*r)->bottomLeft->isLeaf && (*r)->bottomLeft->val
                && (*r)->bottomRight->isLeaf && (*r)->bottomRight->val)
            {
                (*r)->val = true;
                (*r)->isLeaf = true;
                free((*r)->topLeft);
                free((*r)->topRight);
                free((*r)->bottomLeft);
                free((*r)->bottomRight);
                (*r)->topLeft = (*r)->topRight = (*r)->bottomLeft = (*r)->bottomRight = NULL;
            }
            else if ((*r)->topLeft->isLeaf && !(*r)->topLeft->val
                && (*r)->topRight->isLeaf && !(*r)->topRight->val
                && (*r)->bottomLeft->isLeaf && !(*r)->bottomLeft->val
                && (*r)->bottomRight->isLeaf && !(*r)->bottomRight->val)
            {
                (*r)->val = false;
                (*r)->isLeaf = true;
                free((*r)->topLeft);
                free((*r)->topRight);
                free((*r)->bottomLeft);
                free((*r)->bottomRight);
                (*r)->topLeft = (*r)->topRight = (*r)->bottomLeft = (*r)->bottomRight = NULL;
            }
        }
    }

 public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        Node* r = NULL;

        if (!quadTree1 && !quadTree2)
            return NULL;

        if (!quadTree1)
            dup(quadTree2, &r);
        else if (!quadTree2)
            dup(quadTree1, &r);
        else
            is(quadTree1, quadTree2, &r);
        return r;
    }
};
