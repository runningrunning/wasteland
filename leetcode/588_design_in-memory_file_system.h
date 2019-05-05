// hash to make it faster ?
// ls file only return file
// be careful, more patients.
// try with other structure !!
#define PRIME 16411

typedef struct _Node{
    bool add;
    bool file;
    char* path;

    // file
    char* content;

    // dir
    int length;
    char** names;
} Node;

typedef struct {
    Node* f;
    Node** hash;
} FileSystem;

int _hash(char* s)
{
    int i = 0;
    int c = s[i ++];
    int t = 0;
    while (c)
    {
        t = (t << 8) + c;
        t %= PRIME;
        c = s[i ++];
    }
    return t;
}

Node* cNode(char* s, bool file, Node** hash)
{
    Node* n = malloc(sizeof(Node));
    n->add = false;
    n->file = file;
    n->path = strdup(s);
    n->content = NULL;
    n->length = 0;
    n->names = NULL;

    int x = _hash(s);
    while (hash[x])
        x = (x + 1) % PRIME;
    hash[x] = n;
    return n;
}

void aNode(Node* p, Node* c)
{
    if (c->add)
        return;

    p->length ++;
    p->names = realloc(p->names, sizeof(char*) * p->length);

    char* name = strrchr(c->path, '/') + 1;

    if (p->length == 1)
        p->names[0] = strdup(name);
    else
    {
        int i = p->length - 2;
        while (i >= 0)
        {
            if (strcmp(p->names[i], name) < 0)
                break;
            p->names[i + 1] = p->names[i];
            i --;
        }
        p->names[i + 1] = strdup(name);
    }

    c->add = true;
}

void wNode(Node* p, char* s)
{
    if (!p->content)
        p->content = strdup(s);
    else
    {
        p->content = realloc(p->content, strlen(p->content) + strlen(s) + 1);
        p->content = strcat(p->content, s);
    }
}

Node* fNode(char* s, Node** hash)
{
    int x = _hash(s);
    while (hash[x] && strcmp(s, hash[x]->path))
        x = (x + 1) %  PRIME;
    return hash[x];
}

FileSystem* fileSystemCreate() {
    FileSystem* f = malloc(sizeof(FileSystem));
    f->hash = calloc(sizeof(Node*), PRIME);
    f->f = cNode("/", false, f->hash);
    return f;
}

char** fileSystemLs(FileSystem* obj, char* path, int *returnSize) {
    *returnSize = 0;
    char** r = NULL;
    if (obj)
    {
        Node* n = fNode(path, obj->hash);
        if (n)
        {
            if (!n->file)
            {
                *returnSize = n->length;
                r = malloc(sizeof(char*) * n->length);
                memcpy(r, n->names, sizeof(char*) * n->length);
            }
            else
            {
                *returnSize = 1;
                r = malloc(sizeof(char*) * 1);
                char* name = strrchr(path, '/') + 1;
                r[0] = strdup(name);
            }
        }
    }
    return r;
}

void _mk(FileSystem* obj, char* path, bool file)
{
    int l = strlen(path);
    l --;

    if (path[l] == '/')
    {
        path[l] = 0;

        l --;
    }

    if (l <= 0)
        return;

    Node* p = NULL;
    while (true)
    {
        Node* c = fNode(path, obj->hash);

        if (!c)
        {
            if (file && !p)
                c = cNode(path, true, obj->hash);
            else
                c = cNode(path, false, obj->hash);
        }

        if (p)
            aNode(c, p);

        p = c;
        while (path[l] != '/')
            l --;

        if (l == 0)
        {
            aNode(obj->f, p);
            break;
        }

        path[l] = 0;
    }
}

void fileSystemMkdir(FileSystem* obj, char* path) {
    _mk(obj, path, false);
}

void fileSystemAddContentToFile(FileSystem* obj, char* path, char* content) {
    Node* c = fNode(path, obj->hash);
    if (!c)
    {
        _mk(obj, strdup(path), true);
        c = fNode(path, obj->hash);
    }
    wNode(c, content);
}

char* fileSystemReadContentFromFile(FileSystem* obj, char* path) {
    Node* c = fNode(path, obj->hash);
    if (!c)
        return NULL;
    return c->content;
}

void fileSystemFree(FileSystem* obj) {
    if (obj)
    {
        free(obj->hash);
        free(obj->f);
        free(obj);
    }
}

/**
 * Your FileSystem struct will be instantiated and called as such:
 * struct FileSystem* obj = fileSystemCreate();
 * char** param_1 = fileSystemLs(obj, path);
 * fileSystemMkdir(obj, path);
 * fileSystemAddContentToFile(obj, filePath, content);
 * char* param_4 = fileSystemReadContentFromFile(obj, filePath);
 * fileSystemFree(obj);
 */
