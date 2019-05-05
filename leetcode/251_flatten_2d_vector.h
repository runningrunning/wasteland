// DONT DEALLOCATES MEMORY NOT ALLOCATED BY US
struct Vector2D {
    int r;
    int c;
    int rs;
    int* cs;
    int** v2d;
};

struct Vector2D *vector2DCreate(int** vec2d, int vec2dRowSize, int* vec2dColSizes) {
    struct Vector2D* v = malloc(sizeof(struct Vector2D));
    v->v2d = vec2d;
    v->rs = vec2dRowSize;
    v->cs = vec2dColSizes;
    v->r = 0;
    v->c = 0;
    for (int i = 0; i < vec2dRowSize; i ++)
        if (vec2dColSizes[i] != 0)
        {
            v->r = i;
            break;
        }
    return v;
}

bool vector2DHasNext(struct Vector2D *iter) {
    if (!iter || !iter->v2d || !iter->rs)
        return false;
    return iter->r < iter->rs && iter->c < iter->cs[iter->r];
}

int vector2DNext(struct Vector2D *iter) {
    /* if (!vector2DHasNext(iter)) */
    /*     return 0; */
    int ret = iter->v2d[iter->r][iter->c ++];
    int i = iter->r;
    // find next
    for (; i < iter->rs; i ++)
    {
        if (iter->cs[i] == iter->c)
        {
            iter->c = 0;
            continue;
        }
        break;
    }
    iter->r = i;
    return ret;
}

/** Deallocates memory previously allocated for the iterator */
void vector2DFree(struct Vector2D *iter) {
    // DONT DEALLOCATES MEMORY NOT ALLOCATED BY US
    return;
    /* if (iter) */
    /* { */
    /*     free(iter->cs); */
    /*     for (int i = 0; i < iter->rs; i ++) */
    /*         free(iter->v2d[i]); */
    /*     free(iter->v2d); */
    /*     free(iter); */
    /* } */
}

/**
 * Your Vector2D will be called like this:
 * struct Vector2D *i = vector2DCreate(vec2d, rowSize, colSizes);
 * while (vector2DHasNext(i)) printf("%d\n", vector2DNext(i));
 * vector2DFree(i);
 */
