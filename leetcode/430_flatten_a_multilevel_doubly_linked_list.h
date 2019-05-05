/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
    Node* ft(Node* h, Node* c)
    {
        h->next = c;
        c->prev = h;

        Node* p = h;
        Node* r = h->next;

        while (r)
        {
            if (r->child)
            {
                if (r->child->prev)
                    r->child = NULL;
                else
                {
                    Node* c = r->child;
                    Node* n = r->next;
                    r->child = NULL;
                    r = ft(r, c);
                    r->next = n;
                    if (n)
                        n->prev = r;
                }
            }
            p = r;
            r = r->next;
        }
        return p;
    }

 public:
    Node* flatten(Node* head) {
        if (!head)
            return NULL;
        Node* r = head;
        while (r)
        {
            if (!r->child)
                r = r->next;
            else if (r->child->prev)
            {
                r->child = NULL;
                r = r->next;
            }
            else
            {
                Node* c = r->child;
                Node* n = r->next;
                r->child = NULL;
                r = ft(r, c);
                r->next = n;
                if (n)
                    n->prev = r;
                r = r->next;
            }
        }
        return head;
    }
};
