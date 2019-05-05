// UNIFORM !!
// code optimized !!
// overflow: int, float, double overflow
// how to make it faster
// don't need to be 0.00001 accurate, just make it UNIFORM, so rand can be used directly
// rand / INT_MAX !
// use SQRT TO OPTIMIZE IT
//
// random 360 or 36000 or ?
// random 360 * 100 should be enough
// pi is 3.14159265358979
// wrong answer ?? why ??? ALWAYS !!
// stupid WRONG ALGORITHM !!!!!!!!!!!!!!!!!!!
// The product between two uniform random variables does not follow a uniform distribution. More points are generated close to the center of the circle in your code.
// UNIFORM DISTRIBUTION !!!

int _random(long x)
{
    return ((x * 48271L) % INT_MAX) & 0xFFFFFFFF;
}

typedef struct {
    double r;
    double x;
    double y;
    long rand;
    double d;
    double p;
} Solution;

Solution* solutionCreate(double radius, double x_center, double y_center) {
    Solution* s = malloc(sizeof(Solution));
    s->r = radius;
    s->x = x_center;
    s->y = y_center;
    s->rand = _random((long) s);
    s->d = radius * radius;
    s->p = 2.0 * radius / (double) INT_MAX;
    return s;
}

double* solutionRandPoint(Solution* obj, int *returnSize) {
    if (!obj)
        return NULL;

    double* r = malloc(sizeof(double) * 2);
    *returnSize = 2;

    r[0] = obj->x;
    r[1] = obj->y;

    if (obj->r == 0.0)
        return r;

    // while (true)
    {
        // UNIFORM !!!
        double x1 = obj->p * obj->rand - obj->r;
        obj->rand = _random(obj->rand);

        double yx = sqrt(obj->d - x1 * x1);
        double y1 = 2.0 * yx * obj->rand / (double) INT_MAX - yx;

        /* double y1 = obj->p * obj->rand - obj->r; */
        /* obj->rand = _random(obj->rand); */

        // if (x1 * x1 + y1 * y1 <= obj->d)
        {
            r[0] = x1 + obj->x;
            r[1] = y1 + obj->y;
        }
    }

    return r;
}



void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * struct Solution* obj = solutionCreate(radius, x_center, y_center);
 * double* param_1 = solutionRandPoint(obj);
 * solutionFree(obj);
 */
