typedef struct _Node {
    int value;
    struct _Node* next;
} Node;

typedef struct {
    int size;
    Node* r;
    Node* t;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* l = malloc(sizeof(MyLinkedList));
    l->size = 0;
    l->r = NULL;
    l->t = NULL;
    return l;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (!obj || index > obj->size - 1)
        return -1;

    Node* t = obj->r;
    while (index --)
        t = t->next;

    return t->value;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if (obj)
    {
        Node* t = malloc(sizeof(Node));
        t->value = val;
        t->next = obj->r;
        obj->r = t;
        obj->size ++;

        if (!obj->t)
            obj->t = t;
    }
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if (obj)
    {
        Node* t = malloc(sizeof(Node));
        t->value = val;
        t->next = NULL;
        obj->size ++;

        if (obj->t)
        {
            obj->t->next = t;
            obj->t = t;
        }
        else
            obj->t = t;

        if (!obj->r)
            obj->r = t;
    }
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (obj)
    {
        if (index > obj->size)
            return;

        if (index == obj->size)
        {
            myLinkedListAddAtTail(obj, val);
            return;
        }

        if (!index)
        {
            myLinkedListAddAtHead(obj, val);
            return;
        }

        Node** t = &obj->r;

        while (index --)
            t = &(*t)->next;

        obj->size ++;

        Node* n = malloc(sizeof(Node));
        n->value = val;
        n->next = (*t);
        *t = n;
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (obj)
    {
        if (index >= obj->size)
            return;

        if (!index)
        {
            obj->size --;
            obj->r = obj->r->next;

            if (!obj->size)
                obj->r = obj->t = NULL;

            return;
        }

        Node* p = NULL;
        Node** t = &obj->r;
        int o_index = index;
        while (index --)
        {
            p = *t;
            t = &(*t)->next;
        }

        if (o_index == obj->size - 1)
            obj->t = p;

        obj->size --;
        (*t) = (*t)->next;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */
