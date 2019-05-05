// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        return _guess(1, n);
    }
 private:
    int _guess(int s, int e)
    {
        if (s >= e)
            return s;
        int m = s + (e - s) / 2;
        int r = guess(m);

        if (!r)
            return m;

        if (r > 0)
            return _guess(m + 1, e);
        return _guess(s, m - 1);
    }
};
