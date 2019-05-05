/**
 * #define NEIGHBORS_MAX_SIZE 100
 * struct UndirectedGraphNode {
 *     int label;
 *     struct UndirectedGraphNode *neighbors[NEIGHBORS_MAX_SIZE];
 *     int neighborsCount;
 * };
 */
#define PRIMER 32771
struct UndirectedGraphNode* _cg(struct UndirectedGraphNode *g, struct UndirectedGraphNode** h)
{
    if (!g)
        return NULL;

    int l = g->label;
    l %= PRIMER;
    if (l < 0)
        l += PRIMER;

    while (h[l] && h[l]->label != g->label)
        l = (l + 1) % PRIMER;

    if (h[l])
        return h[l];

    struct UndirectedGraphNode* ug = malloc(sizeof(struct UndirectedGraphNode));
    ug->label = g->label;
    ug->neighborsCount = g->neighborsCount;
    h[l] = ug;
    for (int i = 0; i < ug->neighborsCount; i ++)
        ug->neighbors[i] = _cg(g->neighbors[i], h);
    return ug;
}

struct UndirectedGraphNode *cloneGraph(struct UndirectedGraphNode *graph)
{
    struct UndirectedGraphNode** hash = calloc(sizeof(struct UndirectedGraphNode*), PRIMER);
    return _cg(graph, hash);
}
