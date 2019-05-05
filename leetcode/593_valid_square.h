bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size)
{
    int x12 = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    int x13 = (p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]);
    int x14 = (p1[0] - p4[0]) * (p1[0] - p4[0]) + (p1[1] - p4[1]) * (p1[1] - p4[1]);

    if (!x12 || !x13 || !x14)
        return false;

    if (x13 == x14)
    {
        if (x12 != x13 + x14)
            return false;

        int x23 = (p2[0] - p3[0]) * (p2[0] - p3[0]) + (p2[1] - p3[1]) * (p2[1] - p3[1]);
        int x24 = (p2[0] - p4[0]) * (p2[0] - p4[0]) + (p2[1] - p4[1]) * (p2[1] - p4[1]);

        if (x23 != x24 || x23 != x13)
            return false;
    }
    else
    {
        if (x13 > x14)
        {
            if (x13 != x12 + x14)
                return false;

            int x23 = (p2[0] - p3[0]) * (p2[0] - p3[0]) + (p2[1] - p3[1]) * (p2[1] - p3[1]);
            int x34 = (p3[0] - p4[0]) * (p3[0] - p4[0]) + (p3[1] - p4[1]) * (p3[1] - p4[1]);

            if (x23 != x34 || x23 != x14)
                return false;
        }
        else
        {
            if (x14 != x12 + x13)
                return false;

            int x24 = (p2[0] - p4[0]) * (p2[0] - p4[0]) + (p2[1] - p4[1]) * (p2[1] - p4[1]);
            int x34 = (p3[0] - p4[0]) * (p3[0] - p4[0]) + (p3[1] - p4[1]) * (p3[1] - p4[1]);

            if (x24 != x34 || x24 != x13)
                return false;
        }
    }
    return true;
}
