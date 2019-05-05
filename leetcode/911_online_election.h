// heap should be enough !!
// corner cases ~!!!!!
// time could be larger than last one
class TopVotedCandidate {
    int size;
    int* ti;
    int* p;

 public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        int hi = 0;

        size = persons.size();

        int* heap = (int*) malloc(sizeof(int) * size);
        int* pi = (int*) calloc(sizeof(int), (size + 1));

        ti = (int*) malloc(sizeof(int) * size);
        p = (int*) malloc(sizeof(int) * size);

        for (int i = 0; i < size; i ++)
        {
            ti[i] = times[i];

            int ps = persons[i];
            int x;

            if (pi[ps])
            {
                x = pi[ps] - 1;
                heap[x] += 1;
            }
            else
            {
                heap[hi] = ps << 16 | 1;
                x = hi;
                hi ++;
            }

            int v = heap[x];
            int xv = v & 0xFFFF;

            while (x)
            {
                int xp = (x - 1) / 2;
                if ((heap[xp] & 0xFFFF) > xv)
                    break;

                pi[heap[xp] >> 16] = x + 1;

                heap[x] = heap[xp];
                heap[xp] = v;
                x = xp;
            }

            pi[ps] = x + 1;
            p[i] = heap[0] >> 16;
        }

        free(pi);
        free(heap);
    }

    int q(int t) {

        if (t == ti[0])
            return p[0];

        if (t >= ti[size - 1])
            return p[size - 1];

        int s = 0;
        int e = size - 1;

        while(s < e)
        {
            int m = (s + e) / 2;
            if (ti[m] < t)
                s = m + 1;
            else
                e = m;
        }
        return p[ti[s] == t ? s : (s - 1)];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */

/* typedef struct { */
/*     int size; */
/*     int* t; // time */
/*     int* p; // person */
/* } TopVotedCandidate; */

/* TopVotedCandidate* topVotedCandidateCreate(int* persons, int* times) { */
/*     int hi = 0; */
/*     int* heap = malloc(sizeof(int) * ) */
/* } */

/* int topVotedCandidateQ(TopVotedCandidate* obj, int t) { */
/* } */

/* void topVotedCandidateFree(TopVotedCandidate* obj) { */
/* } */

/* /\** */
/*  * Your TopVotedCandidate struct will be instantiated and called as such: */
/*  * struct TopVotedCandidate* obj = topVotedCandidateCreate(persons, times); */
/*  * int param_1 = topVotedCandidateQ(obj, t); */
/*  * topVotedCandidateFree(obj); */
/*  *\/ */
