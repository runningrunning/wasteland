bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size)
{
    if (rec2[0] >= rec1[2])
        retun false;

    if (rec2[2] <= rec1[0])
        return false;

    if (rec2[1] >= rec1[3])
        return false;

    if (rec2[3] <= rec1[1])
        return false;

    return true;
}
