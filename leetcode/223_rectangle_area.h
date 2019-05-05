int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int ar = (C - A) * (D - B);
    int br = (G - E) * (H - F);

    if (!ar || !br)
        return ar + br;

    if (G <= A || C <= E || H <= B || D <= F)
        return ar + br;

    if (A >= E && C <= G && B >= F && D <= H)
        return br;

    if (E >= A && G <= C && F >= B && H <= D)
        return ar;

    int a = A;
    int b = B;
    int c = C;
    int d = D;

    int e = A;
    int f = D;
    int g = C;
    int h = B;

    long r = (long) ar + (long) br;
    int tx, ty;

    if (a >= E && a < G && b >= F && b < H)
    {
        tx = c < G ? c : G;
        ty = d < H ? d : H;
        return (int)(r - (tx - a) * (ty - b));
    }
    else if (c >= E && c < G && d >= F && d < H)
    {
        tx = a < E ? E : a;
        ty = b < F ? F : b;
        return (int)(r - (tx - c) * (ty - d));
    }
    else if (e >= E && e < G && f >= F && f < H)
    {
        tx = g < G ? g : G;
        ty = h < F ? F : h;
        return (int)(r - (tx - e) * (f - ty));
    }
    else if (g >= E && g < G && h >= F && h < H)
    {
        tx = e < E ? E : e;
        ty = f < H ? f : H;
        return (int)(r - (g - tx) * (ty - h));
    }
    else
    {
        if (a <= E && c >= G)
        {
            tx = G - E;
            if (F >= b && F < d)
                ty = d - F;
            else if (H >= b && H < d)
                ty = H - b;
            else
                ty = d - b;
            return (int)(r - tx * ty);
        }
        else
        {
            ty = H - F;
            if (E >= a && E < c)
                tx = c - E;
            else if (G >= a && G < c)
                tx = G - a;
            else
                tx = c - a;
            return (int)(r - tx * ty);
        }
    }

    return 0;
}
