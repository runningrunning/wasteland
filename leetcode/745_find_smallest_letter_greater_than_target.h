/* variant of binary searching */
int ngl(char* letters, int s, int e, char t)
{
    if (s >= e)
        return s;

    int m = s + (e - s) / 2;
    char mc = letters[m];

    if (mc <= t)
        return ngl(letters, m + 1, e, t);
    return ngl(letters, s, m, t);
}

char nextGreatestLetter(char* letters, int lettersSize, char target)
{
    int s = letters[0];
    int e = letters[lettersSize - 1];

    if (s > target || e <= target)
        return s;

    return letters[ngl(letters, 0, lettersSize - 1, target)];
}
