// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
 public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if (!buf || n <= 0)
            return 0;

        char* o = buf;

        for (int i = 0; i < (n >> 2); i ++)
        {
            int r = read4(o);
            o += r;

            if (r != 4)
                return o - buf;
        }

        int sz = (n >> 2) << 2;

        if (n % 4)
        {
            char tmp[4] = {0};
            int r = read4(tmp);

            r = r < (n % 4) ? r : (n % 4);

            for (int i = 0; i < r; i ++)
                o[i] = tmp[i];
            sz += r;
        }
        return sz;
    }
};
