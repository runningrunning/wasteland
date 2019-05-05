// k largest !!
class KthLargest {
    int hk;
    int hi;
    int* heap;

    void aHeap(int v)
    {
        heap[hi ++] = v;

        int x = hi - 1;
        while (x)
        {
            int p = (x - 1) / 2;
            if (heap[p] <= heap[x])
                break;
            heap[x] = heap[p];
            heap[p] = v;
            x = p;
        }
    }

    void bHeap()
    {
        int x = 0;
        int v = heap[x];

        while (x * 2 + 1 < hi)
        {
            int l = heap[x * 2 + 1];
            int r = l;

            if (x * 2 + 2 < hi)
                r = heap[x * 2 + 2];

            if (l <= r)
            {
                if (v <= l)
                    break;

                heap[x] = l;
                heap[x * 2 + 1] = v;
                x = x * 2 + 1;
            }
            else
            {
                if (v <= r)
                    break;

                heap[x] = r;
                heap[x * 2 + 2] = v;
                x = x * 2 + 2;
            }
        }
    }

    void rHeap()
    {
        heap[0] = heap[-- hi];
        bHeap();
    }


 public:
    KthLargest(int k, vector<int> nums) {
        hi = 0;
        hk = k;
        int size = nums.size() < k ? (k + 1) : nums.size();
        heap = (int*) malloc(sizeof(int) * size);

        size = nums.size();
        for (int i = 0; i < size; i ++)
            aHeap(nums[i]);

        while (hi > hk)
            rHeap();
    }

    int add(int val) {
        if (hi < hk)
            aHeap();
        else
        {
            if (val <= heap[0])
                return heap[0];

            heap[0] = val;
            bHeap();
        }
        return heap[0];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
