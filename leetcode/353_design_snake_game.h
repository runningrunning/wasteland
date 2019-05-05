/*
------------------- y
-
-
-
-
x
*/

// try to improve the coding speed !
typedef struct {
    int* sx;
    int* sy;
    int sh;     // snake head index

    int w;
    int h;

    int** f; // food
    int fi;
    int fn;

    bool fail;
} SnakeGame;

/** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
SnakeGame* snakeGameCreate(int width, int height, int** food, int foodSize) {
    SnakeGame* s = malloc(sizeof(SnakeGame));
    int l = (width * height > foodSize ? foodSize : width * height) + 1;
    s->sx = malloc(sizeof(int) * l);
    s->sy = malloc(sizeof(int) * l);
    s->sh = 0;
    s->w = width;
    s->h = height;

    s->f = food;
    s->fi = 0;
    s->fn = foodSize;

    s->sx[0] = 0;
    s->sy[0] = 0;

    s->fail = false;
    return s;
}

/** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
int snakeGameMove(SnakeGame* s, char* d) {
    // direction +-
    //          A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
    int xd[] = {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0};
    int yd[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};

    if (s)
    {
        if (s->fail)
            return -1;

        int fx = -1;
        int fy = -1;
        int w = s->w;
        int h = s->h;

        int fi = s->fi;
        char di = d[0] - 'A';

        if (fi < s->fn)
        {
            fx = s->f[fi][0];
            fy = s->f[fi][1];
        }

        int l = 1 + fi;
        int sh = s->sh;
        int sx = s->sx[sh];
        int sy = s->sy[sh];

        int tx = sx + xd[di];
        int ty = sy + yd[di];

        if (tx == -1 || ty == -1 || tx == h || ty == w)
        {
            s->fail = true;
            return -1;
        }

        if (fi)
        {
            int ph = (sh - 1 + l) % l;
            int px = s->sx[ph];
            int py = s->sy[ph];

            if (tx == px && ty == py)
                return fi;
        }

        printf("%s fx %d fy %d tx %d ty %d.\n", d, fx, fy, tx, ty);

        int nh = (sh + 1) % l;
        // food
        if (tx == fx && ty == fy)
        {
            s->fi ++;

            if (!nh)
                sh ++;
            else
            {
                for (int i = l; i > nh; i --)
                {
                    s->sx[i] = s->sx[i - 1];
                    s->sy[i] = s->sy[i - 1];
                }

                sh = nh;
            }

            s->sh = sh;
            s->sx[sh] = tx;
            s->sy[sh] = ty;
        }
        else
        {
            sh = nh;

            s->sh = sh;
            s->sx[sh] = tx;
            s->sy[sh] = ty;

            for (int i = 0; i < l; i ++)
            {
                if (i == sh)
                    continue;

                if (s->sx[i] == tx && s->sy[i] == ty)
                {
                    s->fail = true;
                    return -1;
                }
            }
        }
        return s->fi;
    }
    return -1;
}

void snakeGameFree(SnakeGame* obj) {
    if (obj)
    {
        free(obj->sx);
        free(obj->sy);
        free(obj);
    }
}

/**
 * Your SnakeGame struct will be instantiated and called as such:
 * struct SnakeGame* obj = snakeGameCreate(width, height, food, foodSize);
 * int param_1 = snakeGameMove(obj, direction);
 * snakeGameFree(obj);
 */
