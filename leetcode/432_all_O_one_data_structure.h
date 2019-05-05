// corner case, stupid wrong code !!!!!!!!!!!
// 1. INT overflow, counts can be more than 65536
// 2. DEC can be error, due to forget to set +2 offset
// 3. TRY USE MIN MAX HEAP, it's also O(1) as it's only changed once per call.

// remove element in hash, use separate chaining
// be careful, int over flow !!!
// min, max heap is also O(1) as it's only add once
// use heap is much easier !!!
// STUPID WRONG CODE !!

#define PRIMER 32771
class AllOne {
    int start;
    int end;
    int size;
    long* counts;
    vector<string> keys;
    int** hash;
public:
    /** Initialize your data structure here. */
    AllOne() {
        end = start = 0;
        size = 256;
        counts = (long*) malloc(sizeof(long) * size);
        hash = (int**) calloc(sizeof(int*), PRIMER);
    }

    int hash_key(const char* s)
    {
        int i = 0;
        int c = s[i ++];

        int k = 0;
        while (c)
        {
            k = ((k << 8) + c) % PRIMER;
            c = s[i ++];
        }
        return k;
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {

        int y = 0;
        int found = 0;

        int k = hash_key(key.c_str());

        if (!hash[k])
        {
            hash[k] = (int*) malloc(sizeof(int) * (10 + 2));
            hash[k][0] = 1;
            hash[k][1] = 10;
            y = 2;
        }
        else
        {
            for (int i = 0; i < hash[k][0]; i ++)
            {
                if (keys[hash[k][i + 2]] == key)
                {
                    y = i + 2;
                    found = hash[k][y] + 1;
                    break;
                }
            }

            if (!found && hash[k][0] == hash[k][1])
            {
                hash[k][1] += 10;
                hash[k] = (int*) realloc(hash[k], sizeof(int) * (hash[k][1] + 2));

                y = hash[k][0] + 2;
                hash[k][0] ++;
            }
        }

        if (!found)
        {
            if (end == size)
            {
                size *= 2;
                counts = (long*) realloc(counts, sizeof(long) * size);
            }

            hash[k][y] = end;
            counts[end] = (((long)k) << 32) | 1;
            keys.push_back(key);
            end ++;
        }
        else
        {
            found -= 1;
            counts[found] ++;

            int tf = found;
            int t = counts[found] & 0xFFFFFFFF;

            while (found && (counts[found - 1] & 0xFFFFFFFF) < t)
                found --;

            // switch found with tf
            if (found != tf)
            {
                long tc = counts[tf];
                counts[tf] = counts[found];
                counts[found] = tc;

                string tk = keys[tf];
                keys[tf] = keys[found];
                keys[found] = tk;

                int ok = k;

                k = (counts[tf]) >> 32;
                for (int i = 0; i < hash[k][0]; i ++)
                {
                    if (hash[k][i + 2] == found)
                    {
                        hash[k][i + 2] = tf;
                        break;
                    }
                }
                hash[ok][y] = found;
            }
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        int k = hash_key(key.c_str());

        if (!hash[k] || !hash[k][0])
            return;

        int y = 0;
        int found = 0;

        for (int i = 0; i < hash[k][0]; i ++)
        {
            if (keys[hash[k][i + 2]] == key)
            {
                y = i + 2;
                found = hash[k][y] + 1;
                break;
            }
        }

        if (!found)
            return;

        found --;
        counts[found] --;

        int tf = found;
        int t = counts[found] & 0xFFFFFFFF;

        while (found + 1 != end && (counts[found + 1] & 0xFFFFFFFF) > t)
            found ++;

        if (found != tf)
        {
            long tc = counts[tf];
            counts[tf] = counts[found];
            counts[found] = tc;

            string tk = keys[tf];
            keys[tf] = keys[found];
            keys[found] = tk;

            int ok = k;

            k = counts[tf] >> 32;

            for (int i = 0; i < hash[k][0]; i ++)
            {
                if (hash[k][i + 2] == found)
                {
                    hash[k][i + 2] = tf;
                    break;
                }
            }

            if (t)
            {
                hash[ok][y] = found;
            }
            else
            {
                hash[ok][0] --;
                hash[ok][y] = hash[ok][hash[ok][0] + 2];
                keys.pop_back();
                end --;
            }
        }
        else
        {
            if (!t)
            {
                hash[k][0] --;
                hash[k][y] = hash[k][hash[k][0] + 2];
                keys.pop_back();
                end --;
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return end ? keys[start] : string("");
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return end ? keys[end - 1] : string("");
    }
};



/* typedef struct { */
/*     int start; // current start, start is the max counts */
/*     int end;  // next insert, end is the min counts */
/*     int size; // size */
/*     long* counts; // counts and hash keys */
/*     char** keys; */
/*     int** hash; // hash with separate chaining */
/* } AllOne; */

/* #define PRIMER 65551 */

/* /\** Initialize your data structure here. *\/ */
/* AllOne* allOneCreate() { */
/*     AllOne* a = malloc(sizeof(AllOne)); */
/*     a->end = a->start = 0; */
/*     a->size = 256; */
/*     a->counts = malloc(sizeof(long) * a->size); */
/*     a->keys = malloc(sizeof(char*) * a->size); */
/*     a->hash = calloc(sizeof(int*), PRIMER); */
/*     return a; */
/* } */

/* int hash_key(char* s) */
/* { */
/*     int i = 0; */
/*     int c = s[i ++]; */
/*     int k = 0; */
/*     while (c) */
/*     { */
/*         k = ((k << 8) + c) % PRIMER; */
/*         c = s[i ++]; */
/*     } */
/*     return k; */
/* } */

/* /\** Inserts a new key <Key> with value 1. Or increments an existing key by 1. *\/ */
/* void allOneInc(AllOne* obj, char* key) { */
/*     if (obj) */
/*     { */
/*         int y = 0; */
/*         int found = 0; */
/*         int k = hash_key(key); */

/*         if (!obj->hash[k]) */
/*         { */
/*             obj->hash[k] = malloc(sizeof(int) * (10 + 2)); */
/*             obj->hash[k][0] = 1; */
/*             obj->hash[k][1] = 10; */
/*             y = 2; */
/*         } */
/*         else */
/*         { */
/*             for (int i = 0; i < obj->hash[k][0]; i ++) */
/*             { */
/*                 char* t = obj->keys[obj->hash[k][i + 2]]; */
/*                 if (!strcmp(t, key)) */
/*                 { */
/*                     y = i + 2; */
/*                     found = obj->hash[k][y] + 1; */
/*                     break; */
/*                 } */
/*             } */

/*             if (!found && obj->hash[k][0] == obj->hash[k][1]) */
/*             { */
/*                 obj->hash[k][1] += 10; */
/*                 obj->hash[k] = realloc(obj->hash[k], sizeof(int) * (obj->hash[k][1] + 2)); */
/*                 y = obj->hash[k][0] + 2; */
/*                 obj->hash[k][0] ++; */
/*             } */
/*         } */

/*         if (!found) */
/*         { */
/*             if (obj->end == obj->size) */
/*             { */
/*                 obj->size *= 2; */
/*                 obj->counts = realloc(obj->counts, sizeof(long) * obj->size); */
/*                 obj->keys  = realloc(obj->keys, sizeof(char*) * obj->size); */
/*             } */
/*             obj->hash[k][y] = obj->end; */
/*             obj->counts[obj->end] = (((long) k) << 32) | 1; */
/*             obj->keys[obj->end] = strdup(key); */
/*             // printf("add end %d %s.\n", obj->end, key); */
/*             obj->end ++; */
/*         } */
/*         else */
/*         { */
/*             found -= 1; */
/*             obj->counts[found] ++; */

/*             int tf = found; */
/*             int t = obj->counts[found] & 0xFFFFFFFF; */

/*             while (found && (obj->counts[found - 1] & 0xFFFFFFFF) < t) */
/*                 found --; */

/*             // switch found with tf, not only the counts, but also the hash */
/*             if (found != tf) */
/*             { */
/*                 long tc = obj->counts[tf]; */
/*                 obj->counts[tf] = obj->counts[found]; */
/*                 obj->counts[found] = tc; */

/*                 char* tk = obj->keys[tf]; */
/*                 obj->keys[tf] = obj->keys[found]; */
/*                 obj->keys[found] = tk; */

/*                 int ok = k; */
/*                 k = (obj->counts[tf]) >> 32; */

/*                 for (int i = 0; i < obj->hash[k][0]; i ++) */
/*                 { */
/*                     if (obj->hash[k][i + 2] == found) */
/*                     { */
/*                         obj->hash[k][i + 2] = tf; */
/*                         break; */
/*                     } */
/*                 } */
/*                 obj->hash[ok][y] = found; */
/*             } */
/*         } */
/*     } */
/* } */

/* /\** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. *\/ */
/* void allOneDec(AllOne* obj, char* key) { */
/*     if (obj) */
/*     { */
/*         int k = hash_key(key); */

/*         if (!obj->hash[k] || !obj->hash[k][0]) */
/*             return; */

/*         int y = 0; */
/*         int found = 0; */

/*         for (int i = 0; i < obj->hash[k][0]; i ++) */
/*         { */
/*             char* t = obj->keys[obj->hash[k][i + 2]]; */
/*             if (!strcmp(t, key)) */
/*             { */
/*                 y = i + 2; */
/*                 found = obj->hash[k][y] + 1; */
/*                 break; */
/*             } */
/*         } */

/*         if (!found) */
/*             return; */

/*         found --; */
/*         obj->counts[found] --; */

/*         int tf = found; */
/*         int t = obj->counts[found] & 0xFFFFFFFF; */

/*         while (found + 1 != obj->end && (obj->counts[found + 1] & 0xFFFFFFFF) > t) */
/*             found ++; */

/*         if (found != tf) */
/*         { */
/*             long tc = obj->counts[tf]; */
/*             obj->counts[tf] = obj->counts[found]; */
/*             obj->counts[found] = tc; */

/*             char* tk = obj->keys[tf]; */
/*             obj->keys[tf] = obj->keys[found]; */
/*             obj->keys[found] = tk; */

/*             int ok = k; */
/*             k = obj->counts[tf] >> 32; */

/*             printf("%d %p obj->end %d t %d.\n", k, obj->hash[k], obj->end); */
/*             for (int i = 0; i < obj->hash[k][0]; i ++) */
/*             { */
/*                 if (obj->hash[k][i + 2] == found) */
/*                 { */
/*                     obj->hash[k][i + 2] = tf; */
/*                     break; */
/*                 } */
/*             } */

/*             if (t) */
/*             { */
/*                 obj->hash[ok][y] = found; */
/*             } */
/*             else */
/*             { */
/*                 obj->hash[ok][0] --; */
/*                 obj->hash[ok][y] = obj->hash[ok][obj->hash[ok][0] + 2]; */
/*                 obj->end --; */
/*                 printf("%d %s.\n", obj->end, key); */
/*             } */
/*         } */
/*         else */
/*         { */
/*             if (!t) */
/*             { */
/*                 obj->hash[k][0] --; */
/*                 obj->hash[k][y] = obj->hash[k][obj->hash[k][0] + 2]; */
/*                 obj->end --; */
/*             } */
/*         } */
/*     } */
/* } */

/* /\** Returns one of the keys with maximal value. *\/ */
/* char* allOneGetMaxKey(AllOne* obj) { */
/*     if (obj) */
/*         return obj->end ? obj->keys[obj->start] : ""; */
/*     return ""; */
/* } */

/* /\** Returns one of the keys with Minimal value. *\/ */
/* char* allOneGetMinKey(AllOne* obj) { */
/*     if (obj) */
/*         return obj->end ? obj->keys[obj->end - 1] : ""; */
/*     return ""; */
/* } */

/* void allOneFree(AllOne* obj) { */
/*     if (obj) */
/*     { */
/*         free(obj->keys); */
/*         free(obj->counts); */
/*         free(obj->hash); */
/*         free(obj); */
/*     } */
/* } */
