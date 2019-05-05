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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root)
            return string("");
        string s = string("[");
        s += to_string(root->val);
        for (int i = 0; i < root->children.size(); i ++)
            s += serialize(root->children[i]);
        s += string("]");
        return s;
    }

    Node* des(const char* s, int* pi)
    {
        int i = *pi;
        if (!s[i] || s[i] != '[')
            return NULL;

        i ++;

        int x = 0;
        while (s[i] && s[i] != ']' && s[i] != '[')
            x = x * 10 + (s[i++] - '0');

        Node* r = new Node(x, vector<Node*> ());

        *pi = i;

        while (s[*pi] && s[*pi] != ']')
            r->children.push_back(des(s, pi));

        if (s[*pi])
            (*pi) ++;

        return r;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        const char* s = data.c_str();
        if (!strlen(s))
            return NULL;
        int i = 0;
        return des(s, &i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

/* /\* */
/* // Definition for a Node. */
/* class Node { */
/* public: */
/*     int val = NULL; */
/*     vector<Node*> children; */

/*     Node() {} */

/*     Node(int _val, vector<Node*> _children) { */
/*         val = _val; */
/*         children = _children; */
/*     } */
/* }; */
/* *\/ */
/* class Codec { */
/* public: */

/*     // Encodes a tree to a single string. */
/*     string serialize(Node* root) { */
/*         if (!root) */
/*             return string(""); */
/*         string s = string("["); */
/*         s += to_string(root->val); */
/*         for (int i = 0; i < root->children.size(); i ++) */
/*             s += serialize(root->children[i]); */
/*         s += string("]"); */
/*         return s; */
/*     } */

/*     Node* des(const char* s, int* pi) */
/*     { */
/*         int i = *pi; */
/*         if (!s[i] || s[i] != '[') */
/*             return NULL; */

/*         i ++; */

/*         int x = 0; */
/*         while (s[i] && s[i] != ']' && s[i] != '[') */
/*             x = x * 10 + (s[i++] - '0'); */

/*         Node* r = new Node(x, vector<Node*> ()); */

/*         *pi = i; */

/*         if (!s[i] || s[i] == ']') */
/*         { */
/*             (*pi) += (s[i] == ']') ? 1 : 0; */
/*             return r; */
/*         } */

/*         while (s[*pi] && s[*pi] != ']') */
/*         { */
/*             Node* n = des(s, pi); */
/*             r->children.push_back(n); */
/*         } */

/*         if (s[*pi]) */
/*             (*pi) ++; */

/*         return r; */
/*     } */

/*     // Decodes your encoded data to tree. */
/*     Node* deserialize(string data) { */
/*         const char* s = data.c_str(); */
/*         if (!strlen(s)) */
/*             return NULL; */
/*         int i = 0; */
/*         return des(s, &i); */
/*     } */
/* }; */

/* // Your Codec object will be instantiated and called as such: */
/* // Codec codec; */
/* // codec.deserialize(codec.serialize(root)); */
