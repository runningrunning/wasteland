class SnapshotArray {
    long snaps;
    vector<vector<long>> all;
public:
    SnapshotArray(int length) {
        snaps = 0;
        all.resize(length);
    }
    void set(int index, int val) {
        all[index].push_back(snaps << 32L | val);
    }

    int snap() {
        snaps ++;
    }

    int get(int index, int snap_id) {
        vector<long>& v = all[index];
        int s = 0;
        int e = v.size() - 1;

        if (snap_id < v[0] >> 32)
            return 0;

        if (snap_id >= v[e] >> 32)
            return v[e] & 0xFFFFFFFF;

        while (s < e)
        {
            int m = (s + e) / 2;

            if (snap_id >= a[m] >> 32)
                s = m + 1;
            else
                e = m;
        }
        return v[s - 1] & 0xFFFFFFFF;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
/*
typedef struct {
    long snaps;
    int length;
    long** all;
} SnapshotArray;


SnapshotArray* snapshotArrayCreate(int length) {
    SnapshotArray* s = malloc(sizeof(SnapshotArray));
    s->all = calloc(sizeof(long*), length);
    s->length = length;
    s->snaps = 0;
    return s;
}

void snapshotArraySet(SnapshotArray* s, int index, int val) {
    if (s)
    {
        if (s->all[index])
        {
            if (!((s->all[index][0] + 2) % 256))
                s->all[index] = realloc(s->all[index], sizeof(long) * (s->all[index][0] + 2 + 256));
            s->all[index][0] += 1;
        }
        else
        {
            s->all[index] = malloc(sizeof(long) * 256);
            s->all[index][0] = 1;
        }
        s->all[index][s->all[index][0]] = s->snaps << 32 | val;
    }
}

int snapshotArraySnap(SnapshotArray* obj) {
    if (obj)
        return obj->snaps ++;
    return 0;
}

int snapshotArrayGet(SnapshotArray* obj, int index, int snap_id)
{
    if (obj)
    {
        if (!obj->all[index])
            return 0;

        long* a = obj->all[index];
        int s = 1;
        int e = a[0];

        if (snap_id < a[1] >> 32)
            return 0;

        if (snap_id >= a[e] >> 32)
            return a[e] >> 32;

        while (s < e)
        {
            int m = (s + e) / 2;

            if (snap_id >= a[m] >> 32)
                s = m + 1;
            else
                e = m;
        }
        return a[s - 1] & 0xFFFFFFFF;
    }
    return 0;
}

void snapshotArrayFree(SnapshotArray* obj)
{
    if (obj)
    {
        for (int i = 0; i < obj->length; i ++)
            if (obj->all[i])
                free(obj->all[i]);
        free(obj);
    }
}
*/

/**
 * Your SnapshotArray struct will be instantiated and called as such:
 * SnapshotArray* obj = snapshotArrayCreate(length);
 * snapshotArraySet(obj, index, val);
 
 * int param_2 = snapshotArraySnap(obj);
 
 * int param_3 = snapshotArrayGet(obj, index, snap_id);
 
 * snapshotArrayFree(obj);
*/
