bool validUtf8(int* data, int dataSize)
{
    int own = 0;
    for (int i = 0; i < dataSize; i ++)
    {
        int n = data[i];
        if (n < 128)
        {
            if (own)
                return false;
        }
        else
        {
            if (own)
            {
                if ((n & 0xC0) != 0x80)
                    return false;
                own --;
            }
            else
            {
                if ((n & 0xE0) == 0xC0)
                    own = 1;
                else if ((n & 0xF0) == 0xE0)
                    own = 2;
                else if ((n & 0xF8) == 0xF0)
                    own = 3;
                else
                    return false;
            }
        }
    }
    return own == 0;
}
