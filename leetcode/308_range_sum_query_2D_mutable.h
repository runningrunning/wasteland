// REWORK !!! DO IT AGAIN !!
// learn a lot
// my stupid 2d segment trees !!!!!!
// STUPID !!!!!!
// why my segment tree cost that much time !!!!

// ???? my stupid ????
// 2D Segment trees
// In this type of segment tree, for each node we have another segment tree (we may also have some other variables beside this) .

typedef struct {
    int rl; // level
    int cl;
    int rs; // size;
    int cs;
    int rst; // start
    int cst;

    int* tree;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize) {
    int rl = 0;
    int x = 1;
    while (x < matrixRowSize)
    {
        x <<= 1;
        rl ++;
    }

    int cl = 0;
    int y = 1;
    while (y < matrixColSize)
    {
        y <<= 1;
        cl ++;
    }

    int rs = x - 1 + matrixRowSize;
    int cs = y - 1 + matrixColSize;

    NumMatrix* m = malloc(sizeof(NumMatrix));
    int* tree = calloc(sizeof(int), rs * cs);
    m->tree = tree;
    m->rl = rl;
    m->cl = cl;
    m->rs = rs;
    m->cs = cs;
    m->rst = x - 1;
    m->cst = y - 1;

    for (int i = 0; i < matrixRowSize; i ++)
        for (int j = 0; j < matrixColSize; j ++)
        {
            int xi = i + x - 1;
            int yj = j + y - 1;
            int n = matrix[i][j];

            int x = xi;
            int y = yj;

            while (x >= 0)
            {
                y = yj;
                while (y >= 0)
                {
                    tree[x * cs + y] += n;
                    if (!y)
                        break;
                    y = (y - 1) / 2;
                }
                if (!x)
                    break;
                x = (x - 1) / 2;
            }
        }
    return m;
}

void numMatrixUpdate(NumMatrix* obj, int row, int col, int val)
{
    if (obj)
    {
        int cs = obj->cs;
        int* tree = obj->tree;
        row += obj->rst;
        col += obj->cst;
        int d = val - tree[row * cs + col];

        int x = row;
        int y = col;
        while (x >= 0)
        {
            y = col;
            while (y >= 0)
            {
                tree[x * cs + y] += d;
                if (!y)
                    break;
                y = (y - 1) / 2;
            }
            if (!x)
                break;
            x = (x - 1) / 2;
        }
    }
}

void _range(int* tree, int x, int y, int rl, int cl, int r1, int c1, int r2, int c2, int cs, int* r)
{
    if (rl < 0 && cl < 0)
        return;

    if (rl >= 0 && cl >= 0)
    {
        int tx = x + 1;
        int ty = y + 1;

        int xs = (tx << rl) - 1;
        int xe = xs + (1 << rl) - 1;
        int ys = (ty << cl) - 1;
        int ye = ys + (1 << cl) - 1;

        if (r1 > xe || r2 < xs || c1 > ye || c2 < ys)
            return;

        if (r1 <= xs && r2 >= xe && c1 <= ys && c2 >= ye)
            (*r) += tree[x * cs + y];
        else
        {
            if (rl && cl)
            {
                // it should go down always !!
                _range(tree, x * 2 + 1, y * 2 + 1, rl - 1, cl - 1, r1, c1, r2, c2, cs, r);
                _range(tree, x * 2 + 1, y * 2 + 2, rl - 1, cl - 1, r1, c1, r2, c2, cs, r);
                _range(tree, x * 2 + 2, y * 2 + 1, rl - 1, cl - 1, r1, c1, r2, c2, cs, r);
                _range(tree, x * 2 + 2, y * 2 + 2, rl - 1, cl - 1, r1, c1, r2, c2, cs, r);
            }
            else if (!rl)
            {
                _range(tree, x, y * 2 + 1, rl - 1, cl - 1, r1, c1, r2, c2, cs, r);
                _range(tree, x, y * 2 + 2, rl - 1, cl - 1, r1, c1, r2, c2, cs, r);
            }
            else if (!cl)
            {
                _range(tree, x * 2 + 1, y, rl - 1, cl - 1, r1, c1, r2, c2, cs, r);
                _range(tree, x * 2 + 2, y, rl - 1, cl - 1, r1, c1, r2, c2, cs, r);
            }
        }
    }
    else if (rl >= 0)
    {
        int tx = x + 1;
        int xs = (tx << rl) - 1;
        int xe = xs + (1 << rl) - 1;

        if (r1 > xe || r2 < xs)
            return;

        if (r1 <= xs && r2 >= xe)
        {
            (*r) += tree[x * cs + y];
        }
        else if (rl)
        {
            _range(tree, x * 2 + 1, y, rl - 1, cl - 1, r1, c1, r2, c2, cs, r);
            _range(tree, x * 2 + 2, y, rl - 1, cl - 1, r1, c1, r2, c2, cs, r);
        }
    }
    else if (cl >= 0)
    {
        int ty = y + 1;
        int ys = (ty << cl) - 1;
        int ye = ys + (1 << cl) - 1;

        if (c1 > ye || c2 < ys)
            return;

        if (c1 <= ys && c2 >= ye)
        {
            (*r) += tree[x * cs + y];
        }
        else if (cl)
        {
            _range(tree, x, y * 2 + 1, rl - 1, cl - 1, r1, c1, r2, c2, cs, r);
            _range(tree, x, y * 2 + 2, rl - 1, cl - 1, r1, c1, r2, c2, cs, r);
        }
    }
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2)
{
    int r = 0;
    if (obj)
        _range(obj->tree, 0, 0, obj->rl, obj->cl, row1 + obj->rst, col1 + obj->cst,
               row2 + obj->rst, col2 + obj->cst, obj->cs, &r);
    return r;
}

void numMatrixFree(NumMatrix* obj) {
    if (obj)
    {
        free(obj->tree);
        free(obj);
    }
}
