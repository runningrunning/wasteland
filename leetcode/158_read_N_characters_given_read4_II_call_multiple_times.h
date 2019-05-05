// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
    int left;
    char obuf[4];
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    Solution()
    {
        left = 0;
        memset(obuf, 0, 4);
    }

    int read(char *buf, int n) {
        int o = 0;

        if (left)
        {
            if (n <= left)
            {
                for (int i = 0; i < n; i ++)
                    buf[i] = obuf[i];

                left -= n;

                for (int i = 0; i < left; i ++)
                    obuf[i] = obuf[i + n];

                return n;
            }

            for (int i = 0; i < left; i ++)
                buf[i] = obuf[i];

            n -= left;
            o = left;
            left = 0;
        }

        while (n >= 4)
        {
            int x = read4(buf + o);
            o += x;
            n -= x;

            if (x < 4)
                return o;
        }

        if (n)
        {
            left = read4(obuf);
            int x = (left < n) ? left : n;

            for (int i = 0; i < x; i ++)
                buf[o + i]  = obuf[i];

            left -= x;
            for (int i = 0; i < left; i ++)
                obuf[i] = obuf[i + x];
            o += x;
        }
        return o;
    }
};
