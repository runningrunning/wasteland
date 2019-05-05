// corner case too much !!!
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head)
            return new Node(insertVal, NULL);
        Node* p = head;
        Node* n = head->next;

        bool all_equal = true;

        while (n != head)
        {
            if (n->val != p->val)
            {
                all_equal = false;
                break;
            }
            p = n;
            n = n->next;
        }

        if (all_equal)
        {
            head->next = new Node(insertVal, head->next);
            return head;
        }

        p = head;

        while (true)
        {
            if (p->val > p->next->val)
            {
                if (insertVal >= p->val || insertVal <= p->next->val)
                {
                    p->next = new Node(insertVal, p->next);
                    break;
                }
            }
            if (p->val <= insertVal && p->next->val >= insertVal)
            {
                p->next = new Node(insertVal, p->next);
                break;
            }
            p = p->next;
        }
        return head;
    }
};

// #include <stdio.h>
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;

//     Node() {}

//     Node(int _val, Node* _next) {
//         val = _val;
//         next = _next;
//     }
// };
// class Solution {
// public:
// };

//     Node* insert(Node* head, int insertVal) {
//         if (!head)
//             return new Node(insertVal, NULL);
//         Node* p = head;

//         while (true)
//         {
//             if (p->val > p->next->val)
//             {
//                 if (insertVal >= p->val || insertVal <= p->next->val)
//                     p->next = new Node(insertVal, p->next);
//                 break;
//             }

//             if (p->val <= insertVal && p->next->val >= insertVal)
//             {
//                 p->next = new Node(insertVal, p->next);
//                 break;
//             }

//             p = p->next;

//         }
//         return head;
//     }

// int main(int argn, char** argv)
// {
//     Node* node1 = new Node(1, NULL);
//     Node* node2 = new Node(2, NULL);
//     Node* node3 = new Node(3, NULL);

//     node1->next = node2;
//     node2->next = node3;
//     node3->next = node1;

//     insert(node1, 0);
//     return 0;

// }
