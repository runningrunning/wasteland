
//     unordered_map<string, map<int, string>> m;
// void set(string key, string value, int timestamp) {
//   m[key].insert({ timestamp, value });
// }
// string get(string key, int timestamp) {
//   auto it = m[key].upper_bound(timestamp);
//   return it == m[key].begin() ? "" : prev(it)->second;
// }

// STUPID COPY SOLUTIONS !!!
unordered_map<string, vector<pair<string, int>>> mymap;
/** Initialize your data structure here. */
TimeMap() {

}

void set(string key, string value, int timestamp) {
	mymap[key].push_back(make_pair(value, timestamp));
}

string get(string key, int timestamp) {
	if (mymap.find(key) == mymap.end())  return "";                   //if key does not exist
	vector<pair<string, int>> & k = mymap[key];
	int s = 0, e = k.size()-1;
	if (timestamp < k[s].second)     return "";                              //if timestamp is smaller than the first time, no necessary to check again.
    if (timestamp >= k[e].second) return k[e].first;

    while (s < e)
    {
        int m = s + (e - s) / 2;
        if (k[m].second <= timestamp)
            s = m + 1;
        else
            e = m;
    }
	return k[s - 1].first;
}

// typedef struct {
//     char* key;
//     int vn;
//     int* t;
//     char** value;
// } KV;

// class TimeMap {
//     int n;
//     int prime;
//     KV** store;
//     KV** hash;
// public:
//     /** Initialize your data structure here. */
//     TimeMap() {
//         prime = 4194319;
//         hash = calloc(sizeof(struct KV*), dp);
//         n = 0;
//         store = NULL;
//     }
//     void set(string _key, string value, int timestamp)
//     {
//         int i = 0;
//         int k = 0;
//         int PRIME = prime;
//         char* key = _key.c_str();
//         while (key[i])
//         {
//             k = k * 26 + (key[i] - 'a');
//             k %= PRIME;
//             i ++;
//         }

//         if (hash[k] && strcmp(hash[k]->key, key))
//             k ++;

//         int n = 0;
//         KV* kv = NULL;
//         if (hash[k])
//         {
//             kv = hash[k];
//             n = kv->vn;
//         }
//         else
//         {
//             kv = malloc(sizeof(KV));
//             kv->key = strdup(key);
//             kv->vn = 0;
//             kv->t = NULL;
//             kv->value = NULL;
//             n ++;
//             store = realloc(store, sizeof(KV*) * n);
//             store[n - 1] = kv;
//             hash[k] = kv;
//         }

//         kv->t = realloc(kv->t, sizeof(int) * (n + 1));
//         kv->value = realloc(kv->value, sizeof(char*) * (n + 1));
//         kv->t[n] = timestamp;
//         kv->value[n] = strdup(value.c_str());
//         kv->vn ++;
//     }
//     string get(string _key, int timestamp) {
//         int i = 0;
//         int k = 0;
//         int PRIME = obj->prime;
//         char* key = strdup(_key.c_str());

//         while (key[i])
//         {
//             k = k * 26 + (key[i] - 'a');
//             k %= PRIME;
//             i ++;
//         }

//         if (hash[k] && strcmp(hash[k]->key, key))
//             k ++;
//         if (!hash[k])
//             return "";

//         KV* kv = hash[k];

//         int s = 0;
//         int e = kv->vn - 1;
//         if (timestamp < kv->t[s])
//             return "";
//         if (timestamp >= kv->t[e])
//             return kv->value[e];

//         // binary search here again
//         while (s < e)
//         {
//             int m = (s + e) / 2;
//             if (kv->t[m] <= timestamp)
//                 s = m + 1;
//             else
//                 e = m;
//         }
//         return kv->value[s - 1];
//     }
// };

// // /**
// //  * Your TimeMap object will be instantiated and called as such:
// //  * TimeMap* obj = new TimeMap();
// //  * obj->set(key,value,timestamp);
// //  * string param_2 = obj->get(key,timestamp);
// //  */

// // /**
// //  * Your TimeMap object will be instantiated and called as such:
// //  * TimeMap* obj = new TimeMap();
// //  * obj->set(key,value,timestamp);
// //  * string param_2 = obj->get(key,timestamp);
// //  */

// // // WTF TLE
// // // how to use hash in c
// // // find better way for binary search here !!
// // typedef struct {
// //     char* key;
// //     int vn;
// //     int* t;
// //     char** value;
// // } KV;
// // typedef struct {
// //     int n;
// //     int prime;
// //     KV** store;
// //     KV** hash;
// // } TimeMap;

// // /** Initialize your data structure here. */
// // TimeMap* timeMapCreate(int maxSize) {

// //     int pri[] = {5, 11, 17, 31, 67, 131, 257, 521, 1031, 2053, 4099, 8209, 16411, 32771, 65551, 131101, 262147, 524309, 1048583, 2097169, 4194319, 8388617};
// //     int pl = sizeof(pri)/sizeof(pri[0]);
// //     int dp;

// //     for (int i = 5; i < pl; i ++)
// //     {
// //         dp = pri[i];
// //         if (dp / 4 >= maxSize)
// //             break;
// //     }

// //     TimeMap* tm = malloc(sizeof(TimeMap));
// //     tm->prime = dp;
// //     tm->hash = calloc(sizeof(struct KV*), dp);
// //     tm->n = 0;
// //     tm->store = NULL;
// //     return tm;
// // }

// // void timeMapSet(TimeMap* obj, char* key, char* value, int timestamp) {
// //     if (!obj)
// //         return;

// //     int i = 0;
// //     int k = 0;
// //     int PRIME = obj->prime;
// //     while (key[i])
// //     {
// //         k = k * 26 + (key[i] - 'a');
// //         k %= PRIME;
// //         i ++;
// //     }

// //     if (obj->hash[k] && strcmp(obj->hash[k]->key, key))
// //         k ++;

// //     int n = 0;
// //     KV* kv = NULL;
// //     if (obj->hash[k])
// //     {
// //         kv = obj->hash[k];
// //         n = kv->vn;
// //     }
// //     else
// //     {
// //         kv = malloc(sizeof(KV));
// //         kv->key = key;
// //         kv->vn = 0;
// //         kv->t = NULL;
// //         kv->value = NULL;
// //         obj->n ++;
// //         obj->store = realloc(obj->store, sizeof(KV*) * obj->n);
// //         obj->store[obj->n - 1] = kv;
// //         obj->hash[k] = kv;
// //     }

// //     kv->t = realloc(kv->t, sizeof(int) * (n + 1));
// //     kv->value = realloc(kv->value, sizeof(char*) * (n + 1));
// //     kv->t[n] = timestamp;
// //     kv->value[n] = value;
// //     kv->vn ++;
// // }

// // char* timeMapGet(TimeMap* obj, char* key, int timestamp) {
// //     if (!obj || !obj->n)
// //         return "";
// //     int i = 0;
// //     int k = 0;
// //     int PRIME = obj->prime;

// //     while (key[i])
// //     {
// //         k = k * 26 + (key[i] - 'a');
// //         k %= PRIME;
// //         i ++;
// //     }

// //     if (obj->hash[k] && strcmp(obj->hash[k]->key, key))
// //         k ++;
// //     if (!obj->hash[k])
// //         return "";

// //     KV* kv = obj->hash[k];

// //     int s = 0;
// //     int e = kv->vn - 1;
// //     if (timestamp < kv->t[s])
// //         return "";
// //     if (timestamp >= kv->t[e])
// //         return kv->value[e];

// //     // binary search here again
// //     while (s < e)
// //     {
// //         int m = (s + e) / 2;
// //         if (kv->t[m] <= timestamp)
// //             s = m + 1;
// //         else
// //             e = m;
// //     }
// //     return kv->value[s];
// // }

// // void timeMapFree(TimeMap* obj) {
// //     return;
// //     if (obj)
// //     {
// //         for (int i = 0; i < obj->n; i ++)
// //         {
// //             KV* t = obj->store[i];
// //             free(t->value);
// //             free(t->t);
// //             free(t);
// //         }

// //         free(obj->hash);
// //         free(obj->store);
// //         free(obj);
// //     }
// // }

// // /**
// //  * Your TimeMap struct will be instantiated and called as such:
// //  * struct TimeMap* obj = timeMapCreate(maxSize);
// //  * timeMapSet(obj, key, value, timestamp);
// //  * char* param_2 = timeMapGet(obj, key, timestamp);
// //  * timeMapFree(obj);
// //  */
