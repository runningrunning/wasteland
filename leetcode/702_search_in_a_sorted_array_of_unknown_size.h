/* // Forward declaration of ArrayReader's getElement API. */
int getElement(struct ArrayReader* reader, int index);

// value from -9999 to 9999
int search(struct ArrayReader* reader, int target) {
    if (!reader)
        return -1;

    int s = 0;
    int e = 20000;

    while (s < e)
    {
        int m = e - (e - s) / 2;
        int x = getElement(reader, m);
        if (x > target)
            e = m - 1;
        else
            s = m;
    }

    return getElement(reader, s) == target ? s : -1;
}
