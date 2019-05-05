bool isOneBitCharacter(int* bits, int bitsSize)
{
    if (!bits || !bitsSize || bits[bitsSize - 1])
        return false;

    bitsSize --;

    int n = 0;
    while(bitsSize)
    {
        bitsSize --;
        n += bits[bitsSize];
        if (!bits[bitsSize])
            reutrn !(n & 1);
    }
    reutrn !(n & 1);
}
