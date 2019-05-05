/* HINT!!! malloc array must reset to 0 */
/* int* rl = malloc(sizeof(int) * mx); */
/* int* rr = malloc(sizeof(int) * mx); */

/* // !!!!!!!!!!!  Must reset rl, rr here, or it's not 0 by default */
/* memset(rl, 0, sizeof(int) * mx); */
/* memset(rr, 0, sizeof(int) * mx); */


/*
typedef struct {
    int* rl;
    int* rr;
    int* cu;
    int* cd;
    int r;
    int c;
    int all;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize)
{
    NumMatrix* m = malloc(sizeof(NumMatrix));
    m->r = matrixRowSize;
    m->c = matrixColSize;

    m->rl = malloc(sizeof(int) * m->c);
    m->rr = malloc(sizeof(int) * m->c);
    m->cu = malloc(sizeof(int) * m->r);
    m->cd = malloc(sizeof(int) * m->r);

    for (int i = 0; i < m->r; i ++)
    {
        int l = 0;
        int r = 0;
        int s = m->c - 1;

        for (int j = 0; j < m->c; j ++)
        {
            l += matrix[i][j];
            r += matrix[i][s - j];
            m->rl[j] += l;
            m->rr[s - j] += r;
        }
    }

    m->all = m->rr[0];

    for (int i = 0; i < m->c; i++)
    {
        int l = 0;
        int r = 0;
        int s = m->r - 1;
        for (int j = 0; j < m->r; j ++)
        {
            l += matrix[j][i];
            r += matrix[s - j][i];
            m->cu[j] += l;
            m->cd[s - j] += r;
        }
    }
    return m;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2)
{
    if (!obj || row1 < 0 || col1 < 0 || row2 >= obj->r || col2 >= obj->c)
        return 0;

    int lr = obj->rl[row2] + obj->rl[row1] - obj->all;

    return obj->cu[col2] + obj->cu[col1] - lr;
}

void numMatrixFree(NumMatrix* obj)
{
    if (obj)
    {
        free(obj->rl);
        free(obj->rr);
        free(obj->cu);
        free(obj->cd);
        free(obj);
    }
}
*/
typedef struct {
    int* tl;
    int* tr;
    int* dl;
    int* dr;
    int r;
    int c;
    int all;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize)
{
    NumMatrix* m = malloc(sizeof(NumMatrix));
    m->r = matrixRowSize;
    m->c = matrixColSize;
    m->all = 0;

    int n = m->r * m->c;
    m->tl = malloc(sizeof(int) * n);
    m->tr = malloc(sizeof(int) * n);
    m->dl = malloc(sizeof(int) * n);
    m->dr = malloc(sizeof(int) * n);

    int mx = m->c;

    int* rl = malloc(sizeof(int) * mx);
    int* rr = malloc(sizeof(int) * mx);

    // !!!!!!!!!!!  Must reset rl, rr here, or it's not 0 by default
    memset(rl, 0, sizeof(int) * mx);
    memset(rr, 0, sizeof(int) * mx);

    for (int i = 0; i < m->r; i ++)
    {
        int l = 0;
        int r = 0;
        int s = m->c - 1;

        for (int j = 0; j < m->c; j ++)
        {
            l += matrix[i][j];
            r += matrix[i][s - j];
            rl[j] += l;
            rr[s - j] += r;
        }

        for (int k = 0; k < m->c; k ++)
        {
            m->tl[i * m->c + k] = rl[k];
            m->tr[i * m->c + k] = rr[k];
        }
    }

    m->all = rr[0];

    memset(rl, 0, sizeof(int) * mx);
    memset(rr, 0, sizeof(int) * mx);

    for (int i = m->r - 1; i >= 0; i --)
    {
        int l = 0;
        int r = 0;
        int s = m->c - 1;

        for (int j = 0; j < m->c; j ++)
        {
            l += matrix[i][j];
            r += matrix[i][s - j];
            rl[j] += l;
            rr[s - j] += r;
        }
        for (int k = 0; k < m->c; k ++)
        {
            m->dl[i * m->c + k] = rl[k];
            m->dr[i * m->c + k] = rr[k];
        }
    }

    free(rl);
    free(rr);
    return m;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2)
{
    if (!obj || row1 < 0 || col1 < 0 || row2 >= obj->r || col2 >= obj->c)
        return 0;
    int c = obj->c;

    int tl = 0;
    int tr = 0;
    int dl = 0;
    int dr = 0;

    if (row1)
        tl = obj->tl[(row1 - 1) * c + col2];

    if (col2 != obj->c - 1)
        tr = obj->tr[row2 * c + col2 + 1];

    if (row2 != obj->r - 1)
        dr = obj->dr[(row2 + 1) * c + col1];

    if (col1)
        dl = obj->dl[row1 * c + col1 - 1];

    return obj->all - tl - tr - dl - dr;
}

void numMatrixFree(NumMatrix* obj)
{
    if (obj)
    {
        free(obj->tl);
        free(obj->tr);
        free(obj->dl);
        free(obj->dr);
        free(obj);
    }
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * struct NumMatrix* obj = numMatrixCreate(matrix, matrixRowSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 * numMatrixFree(obj);
 */

