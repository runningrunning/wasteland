// INT LONG OVERFLOW AGAIN !!!
// SHAME ONE ME !!!!
// JUST BE MORE CAREFUL !!!!
// use heap to find the most recent tweets
// use hash to find whether this user is exist ?

#define PRIME 16411

typedef struct {
    int _t;
    int in;
    int num;
    long time_id[10];
} Tweets;

typedef struct {
    int id;

    int followby_cap;
    int followby_num;
    Tweets** followby;

    int follow_cap;
    int follow_num;
    Tweets** follow;

    Tweets own;
    Tweets news;
} User;

typedef struct {
    int time;
    int user_num;
    int user_cap;
    short* hash;
    User** users;

    int heap_num;
    Tweets** heap;
} Twitter;

/** Initialize your data structure here. */
Twitter* twitterCreate() {
    Twitter* t = malloc(sizeof(Twitter));
    t->time = 1;
    t->user_num = 1;
    t->user_cap = 256;
    t->users = malloc(sizeof(User*) * t->user_cap);
    t->hash = calloc(sizeof(short), PRIME);
    t->heap_num = 0;
    t->heap = NULL;
    return t;
}

short findUser(short* hash, int uid, User** us)
{
    int x = uid % PRIME;
    while (hash[x] && us[hash[x]]->id != uid)
        x = (x + 1) % PRIME;
    return hash[x];
}

void addUser(short* hash, int uid, int id)
{
    int x = uid % PRIME;
    while (hash[x])
        x = (x + 1) % PRIME;
    hash[x] = id;
}

bool addFollowby(User* u, User* f)
{
    for (int i = 0; i < u->followby_num; i ++)
        if (u->followby[i] ==  &(f->news))
            return false;

    if (u->followby_num == u->followby_cap)
    {
        u->followby_cap *= 2;
        u->followby = realloc(u->followby, sizeof(Tweets*) * u->followby_cap);
    }

    u->followby[u->followby_num] = &(f->news);
    u->followby_num ++;
    return true;
}

bool addFollow(User* u, User* f)
{
    for (int i = 0; i < u->follow_num; i ++)
        if (u->follow[i] ==  &(f->own))
            return false;

    if (u->follow_num == u->follow_cap)
    {
        u->follow_cap *= 2;
        u->follow = realloc(u->follow, sizeof(Tweets*) * u->follow_cap);
    }

    u->follow[u->follow_num] = &(f->own);
    u->follow_num ++;
    return true;
}

bool removeFollowby(User* u, User* f)
{
    int i;

    for (i = 0; i < u->followby_num; i ++)
        if (u->followby[i] == &(f->news))
            break;

    if (i != u->followby_num)
    {
        u->followby[i] = u->followby[u->followby_num - 1];
        u->followby_num --;
        return true;
    }

    return false;
}

bool removeFollow(User* u, User* f)
{
    int i;

    for (i = 0; i < u->follow_num; i ++)
        if (u->follow[i] == &(f->own))
            break;

    if (i != u->follow_num)
    {
        u->follow[i] = u->follow[u->follow_num - 1];
        u->follow_num --;
        return true;
    }
    return false;
}

void addUserNews(Tweets* t, long tid)
{
    t->time_id[t->in] = tid;
    t->num ++;
    t->in ++;
    t->in %= 10;
}

long pTweets(Tweets* t)
{
    if (t->_t >= t->num || t->_t >= 10)
        return 0;
    long x = t->time_id[(t->in + 9 - t->_t) % 10];
    return x;
}

long rTweets(Tweets* t)
{
    long x = pTweets(t);
    t->_t ++;
    return x;
}

void aHeap(Tweets** heap, int hi, Tweets* t)
{
    t->_t = 0;
    heap[hi ++] = t;
    int x = hi - 1;
    // WRONG conversation !!!!!! INT OVERFLOW !!!
    long v = pTweets(t);
    while (x)
    {
        int p = (x - 1) / 2;
        if (pTweets(heap[p]) > v)
            break;

        heap[x] = heap[p];
        heap[p] = t;
        x = p;
    }
}

long rHeap(Tweets** heap, int* hi)
{
    int len = *hi;

    if (!len)
        return 0;

    if (!pTweets(heap[0]))
    {
        len --;
        heap[0] = heap[len];
    }
    *hi = len;

    if (!len)
        return 0;

    int x = 0;
    Tweets* t = heap[0];
    long p = pTweets(heap[0]);

    while (x * 2 + 1 < len)
    {
        long l = pTweets(heap[x * 2 + 1]);
        long r = l;

        if (x * 2 + 2 < len)
            r = pTweets(heap[x * 2 + 2]);

        if (l >= r)
        {
            if (p > l)
                break;
            heap[x] = heap[x * 2 + 1];
            heap[x * 2 + 1] = t;
            x = x * 2 + 1;
        }
        else
        {
            if (p > r)
                break;
            heap[x] = heap[x * 2 + 2];
            heap[x * 2 + 2] = t;
            x = x * 2 + 2;
        }
    }

    return rTweets(heap[0]);
}

void genNews(Twitter* obj, User* u)
{
    if (obj->heap_num < obj->user_num)
    {
        obj->heap = realloc(obj->heap, sizeof(Tweets*) * obj->user_num);
        obj->heap_num = obj->user_num;
    }

    int hi = 0;
    aHeap(obj->heap, hi ++, &u->own);

    for (int i = 0; i < u->follow_num; i ++)
    {
        if (u->follow[i]->num)
            aHeap(obj->heap, hi ++, u->follow[i]);
    }

    long news[10] = {0};

    int i = 0;
    for (i = 0; i < 10; i ++)
    {
        long r = rHeap(obj->heap, &hi);
        if (!r)
            break;
        news[i] = r;
    }

    i --;

    int in = 0;
    for (; i >= 0; i --)
        u->news.time_id[in ++] = news[i];

    u->news.in = in % 10;
    u->news.num = in;
}

void addUserTweets(User* u, long tid)
{
    addUserNews(&u->own, tid);
    addUserNews(&u->news, tid);

    for (int i = 0; i < u->followby_num; i ++)
        addUserNews(u->followby[i], tid);
}

User* getUser(Twitter* obj, int userId)
{
    int id = findUser(obj->hash, userId, obj->users);
    if (!id)
    {
        id = obj->user_num;

        if (obj->user_num == obj->user_cap)
        {
            obj->user_cap *= 2;
            obj->users = realloc(obj->users, sizeof(User*) * obj->user_cap);
        }

        User* u = malloc(sizeof(User));
        memset(&u->own, 0, sizeof(Tweets));
        memset(&u->news, 0, sizeof(Tweets));

        u->id = userId;
        u->follow_num = 0;
        u->followby_num = 0;
        u->follow_cap = 16;
        u->followby_cap = 16;
        u->follow = malloc(sizeof(Tweets*) * u->follow_cap);
        u->followby = malloc(sizeof(Tweets*) * u->followby_cap);
        addUser(obj->hash, userId, id);
        obj->users[obj->user_num] = u;
        obj->user_num ++;
    }
    return obj->users[id];
}

/** Compose a new tweet. */
void twitterPostTweet(Twitter* obj, int userId, int tweetId) {
    if (obj)
    {
        long tid = ((long) obj->time) << 32 | tweetId;
        obj->time ++;
        addUserTweets(getUser(obj, userId), tid);
    }
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
int* twitterGetNewsFeed(Twitter* obj, int userId, int *returnSize) {
    int* r = NULL;
    *returnSize = 0;

    if (obj)
    {
        int id = findUser(obj->hash, userId, obj->users);
        if (!id)
            return NULL;

        Tweets* t = &(obj->users[id]->news);
        int s = t->in + 9;
        int l = t->num >= 10 ? 10 : t->num;

        *returnSize = l;
        r = malloc(sizeof(int) * l);

        for (int i = 0; i < l; i ++)
        {
            r[i] = (t->time_id[s % 10]) & 0xFFFFFFFF;
            s --;
        }
    }
    return r;
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
void twitterFollow(Twitter* obj, int followerId, int followeeId)
{
    if (followerId == followeeId)
        return;

    if (obj)
    {
        User* u_frid = getUser(obj, followerId);
        User* u_feid = getUser(obj, followeeId);

        addFollowby(u_feid, u_frid);

        if (addFollow(u_frid, u_feid))
            genNews(obj, u_frid);
}
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
void twitterUnfollow(Twitter* obj, int followerId, int followeeId) {

    if (followerId == followeeId)
        return;

    if (obj)
    {
        User* u_frid = getUser(obj, followerId);
        User* u_feid = getUser(obj, followeeId);
        removeFollowby(u_feid, u_frid);

        if (removeFollow(u_frid, u_feid))
            genNews(obj, u_frid);
    }
}

void twitterFree(Twitter* obj) {

    if (obj)
    {
        free(obj->hash);
        free(obj->heap);
        free(obj->users);
        free(obj);
    }
}

/**
 * Your Twitter struct will be instantiated and called as such:
 * struct Twitter* obj = twitterCreate();
 * twitterPostTweet(obj, userId, tweetId);
 * int* param_2 = twitterGetNewsFeed(obj, userId);
 * twitterFollow(obj, followerId, followeeId);
 * twitterUnfollow(obj, followerId, followeeId);
 * twitterFree(obj);
 */


/* // JUST BE MORE CAREFUL !!!! */
/* // use heap to find the most recent tweets */
/* // use hash to find whether this user is exist ? */

/* #define PRIME 16411 */

/* typedef struct { */
/*     int id; */
/*     int _t; */
/*     int in; */
/*     int num; */
/*     long time_id[10]; */
/* } Tweets; */

/* typedef struct { */
/*     int id; */

/*     int followby_cap; */
/*     int followby_num; */
/*     Tweets** followby; */

/*     int follow_cap; */
/*     int follow_num; */
/*     Tweets** follow; */

/*     Tweets own; */
/*     Tweets news; */
/* } User; */

/* typedef struct { */
/*     int time; */
/*     int user_num; */
/*     int user_cap; */
/*     short* hash; */
/*     User** users; */

/*     int heap_num; */
/*     Tweets** heap; */
/* } Twitter; */

/* /\** Initialize your data structure here. *\/ */
/* Twitter* twitterCreate() { */
/*     Twitter* t = malloc(sizeof(Twitter)); */
/*     t->time = 1; */
/*     t->user_num = 1; */
/*     t->user_cap = 256; */
/*     t->users = malloc(sizeof(User*) * t->user_cap); */
/*     t->hash = calloc(sizeof(short), PRIME); */
/*     t->heap_num = 0; */
/*     t->heap = NULL; */
/*     return t; */
/* } */

/* short findUser(short* hash, int uid, User** us) */
/* { */
/*     int x = uid % PRIME; */
/*     while (hash[x] && us[hash[x]]->id != uid) */
/*         x = (x + 1) % PRIME; */
/*     return hash[x]; */
/* } */

/* void addUser(short* hash, int uid, int id) */
/* { */
/*     int x = uid % PRIME; */
/*     while (hash[x]) */
/*         x = (x + 1) % PRIME; */
/*     hash[x] = id; */
/* } */

/* bool addFollowby(User* u, User* f) */
/* { */
/*     for (int i = 0; i < u->followby_num; i ++) */
/*         if (u->followby[i] ==  &(f->news)) */
/*             return false; */

/*     if (u->followby_num == u->followby_cap) */
/*     { */
/*         u->followby_cap *= 2; */
/*         u->followby = realloc(u->followby, sizeof(Tweets*) * u->followby_cap); */
/*     } */

/*     u->followby[u->followby_num] = &(f->news); */
/*     u->followby_num ++; */
/*     return true; */
/* } */

/* bool addFollow(User* u, User* f) */
/* { */
/*     for (int i = 0; i < u->follow_num; i ++) */
/*         if (u->follow[i] ==  &(f->own)) */
/*             return false; */

/*     if (u->follow_num == u->follow_cap) */
/*     { */
/*         u->follow_cap *= 2; */
/*         u->follow = realloc(u->follow, sizeof(Tweets*) * u->follow_cap); */
/*     } */

/*     u->follow[u->follow_num] = &(f->own); */
/*     u->follow_num ++; */
/*     return true; */
/* } */

/* bool removeFollowby(User* u, User* f) */
/* { */
/*     int i; */

/*     for (i = 0; i < u->followby_num; i ++) */
/*         if (u->followby[i] == &(f->news)) */
/*             break; */

/*     if (i != u->followby_num) */
/*     { */
/*         u->followby[i] = u->followby[u->followby_num - 1]; */
/*         u->followby_num --; */
/*         return true; */
/*     } */

/*     return false; */
/* } */

/* bool removeFollow(User* u, User* f) */
/* { */
/*     int i; */

/*     for (i = 0; i < u->follow_num; i ++) */
/*         if (u->follow[i] == &(f->own)) */
/*             break; */

/*     if (i != u->follow_num) */
/*     { */
/*         u->follow[i] = u->follow[u->follow_num - 1]; */
/*         u->follow_num --; */
/*         return true; */
/*     } */
/*     return false; */
/* } */

/* void addUserNews(Tweets* t, long tid) */
/* { */
/*     t->time_id[t->in] = tid; */
/*     t->num ++; */
/*     t->in ++; */
/*     t->in %= 10; */
/* } */

/* long pTweets(Tweets* t) */
/* { */
/*     if (t->_t >= t->num || t->_t >= 10) */
/*         return 0; */
/*     long x = t->time_id[(t->in + 9 - t->_t) % 10]; */
/*     return x; */
/* } */

/* long pTweetsd(Tweets* t) */
/* { */
/*     if (t->_t >= t->num || t->_t >= 10) */
/*         return 0; */
/*     long x = t->time_id[(t->in + 9 - t->_t) % 10]; */
/*     return x; */
/* } */

/* long rTweets(Tweets* t) */
/* { */
/*     long x = pTweets(t); */
/*     t->_t ++; */
/*     return x; */
/* } */

/* void aHeap(Tweets** heap, int hi, Tweets* t) */
/* { */
/*     t->_t = 0; */
/*     heap[hi ++] = t; */
/*     int x = hi - 1; */
/*     long v = pTweets(t); */

/*     while (x) */
/*     { */
/*         int p = (x - 1) / 2; */
/*         if (pTweets(heap[p]) > v) */
/*             break; */

/*         heap[x] = heap[p]; */
/*         heap[p] = t; */
/*         x = p; */
/*     } */
/* } */

/* long rHeap(Tweets** heap, int* hi) */
/* { */
/*     int len = *hi; */

/*     if (!len) */
/*         return 0; */

/*     if (!pTweets(heap[0])) */
/*     { */
/*         len --; */
/*         heap[0] = heap[len]; */
/*     } */
/*     *hi = len; */

/*     if (!len) */
/*         return 0; */

/*     int x = 0; */
/*     Tweets* t = heap[0]; */
/*     long p = pTweets(heap[0]); */

/*     while (x * 2 + 1 < len) */
/*     { */
/*         long l = pTweets(heap[x * 2 + 1]); */
/*         long r = l; */

/*         if (x * 2 + 2 < len) */
/*             r = pTweets(heap[x * 2 + 2]); */

/*         if (l >= r) */
/*         { */
/*             if (p > l) */
/*                 break; */
/*             heap[x] = heap[x * 2 + 1]; */
/*             heap[x * 2 + 1] = t; */
/*             x = x * 2 + 1; */
/*         } */
/*         else */
/*         { */
/*             if (p > r) */
/*                 break; */
/*             heap[x] = heap[x * 2 + 2]; */
/*             heap[x * 2 + 2] = t; */
/*             x = x * 2 + 2; */
/*         } */
/*     } */

/*     return rTweets(heap[0]); */
/* } */

/* long rHeapd(Tweets** heap, int* hi) */
/* { */
/*     int len = *hi; */

/*     if (!len) */
/*         return 0; */

/*     if (!pTweets(heap[0])) */
/*     { */
/*         len --; */
/*         heap[0] = heap[len]; */
/*     } */
/*     *hi = len; */

/*     if (!len) */
/*         return 0; */

/*     int x = 0; */
/*     Tweets* t = heap[0]; */
/*     long p = pTweets(heap[0]); */

/*     while (x * 2 + 1 < len) */
/*     { */
/*         long l = pTweets(heap[x * 2 + 1]); */
/*         long r = l; */

/*         if (x * 2 + 2 < len) */
/*             r = pTweets(heap[x * 2 + 2]); */

/*         if (l >= r) */
/*         { */
/*             if (p > l) */
/*                 break; */
/*             heap[x] = heap[x * 2 + 1]; */
/*             heap[x * 2 + 1] = t; */
/*             x = x * 2 + 1; */
/*         } */
/*         else */
/*         { */
/*             if (p > r) */
/*                 break; */
/*             heap[x] = heap[x * 2 + 2]; */
/*             heap[x * 2 + 2] = t; */
/*             x = x * 2 + 2; */
/*         } */
/*     }

/*     return rTweets(heap[0]); */
/* } */

/* void genNews(Twitter* obj, User* u) */
/* { */
/*     if (obj->heap_num < obj->user_num) */
/*     { */
/*         obj->heap = realloc(obj->heap, sizeof(Tweets*) * obj->user_num); */
/*         obj->heap_num = obj->user_num; */
/*     } */

/*     int hi = 0; */
/*     aHeap(obj->heap, hi ++, &u->own); */

/*     for (int i = 0; i < u->follow_num; i ++) */
/*     { */
/*         if (u->follow[i]->num) */
/*             aHeap(obj->heap, hi ++, u->follow[i]); */
/*         /\\* if (u->id == 107) *\\/ */
/*         /\\* { *\\/ */
/*         /\\*     printf("uid %d num is %d %ld %d === %ld.\n", u->follow[i]->id, u->follow[i]->num, pTweetsd(u->follow[i]), *\\/ */
/*         /\\*            u->follow[i]->time_id[(u->follow[i]->in - 1)] & 0xFFFFFFFF, pTweets(obj->heap[0])); *\\/ */
/*         /\\* } *\\/ */
/*     } */

/*     /\\* if (u->id == 107) *\\/ */
/*     /\\*     printf("=== %ld.\n", pTweets(obj->heap[0]) & 0xFFFFFFFF); *\\/ */

/*     long news[10] = {0}; */

/*     int i = 0; */
/*     for (i = 0; i < 10; i ++) */
/*     { */
/*         long r; */

/*         if (u->id == 107) */
/*         { */
/*             // printf("got r is %d.\n", r & 0xFFFFFFFF); */
/*             r = rHeapd(obj->heap, &hi); */
/*         } */
/*         else */
/*             r = rHeap(obj->heap, &hi); */
/*         if (!r) */
/*             break; */
/*         news[i] = r; */
/*     } */

/*     i --; */

/*     int in = 0; */
/*     for (; i >= 0; i --) */
/*         u->news.time_id[in ++] = news[i]; */

/*     u->news.in = in % 10; */
/*     u->news.num = in; */
/* } */

/* void addUserTweets(User* u, long tid) */
/* { */
/*     addUserNews(&u->own, tid); */
/*     addUserNews(&u->news, tid); */

/*     for (int i = 0; i < u->followby_num; i ++) */
/*     { */
/*         /\\* if (u->followby[i]->id == 107) *\\/ */
/*         /\\*     printf("%d write %d to 107.\n", u->id, tid); *\\/ */
/*         addUserNews(u->followby[i], tid); */
/*     } */
/* } */

/* User* getUser(Twitter* obj, int userId) */
/* { */
/*     int id = findUser(obj->hash, userId, obj->users); */
/*     if (!id) */
/*     { */
/*         id = obj->user_num; */

/*         if (obj->user_num == obj->user_cap) */
/*         { */
/*             obj->user_cap *= 2; */
/*             obj->users = realloc(obj->users, sizeof(User*) * obj->user_cap); */
/*         } */

/*         User* u = malloc(sizeof(User)); */
/*         memset(&u->own, 0, sizeof(Tweets)); */
/*         memset(&u->news, 0, sizeof(Tweets)); */
/*         u->own.id = userId; */
/*         u->news.id = userId; */

/*         u->id = userId; */
/*         u->follow_num = 0; */
/*         u->followby_num = 0; */
/*         u->follow_cap = 16; */
/*         u->followby_cap = 16; */
/*         u->follow = malloc(sizeof(Tweets*) * u->follow_cap); */
/*         u->followby = malloc(sizeof(Tweets*) * u->followby_cap); */
/*         addUser(obj->hash, userId, id); */
/*         obj->users[obj->user_num] = u; */
/*         obj->user_num ++; */
/*     } */
/*     return obj->users[id]; */
/* } */

/* /\\** Compose a new tweet. *\\/ */
/* void twitterPostTweet(Twitter* obj, int userId, int tweetId) { */
/*     if (obj) */
/*     { */
/*         /\\* if (tweetId == 46107 || tweetId == 18397) *\\/ */
/*         /\\*     printf("%d post %d.\n", userId, tweetId); *\\/ */
/*         long tid = ((long) obj->time) << 32 | tweetId; */
/*         obj->time ++; */
/*         addUserTweets(getUser(obj, userId), tid); */
/*     } */
/* } */

/* /\\** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. *\\/ */
/* int* twitterGetNewsFeed(Twitter* obj, int userId, int *returnSize) { */
/*     int* r = NULL; */
/*     *returnSize = 0; */

/*     if (obj) */
/*     { */
/*         int id = findUser(obj->hash, userId, obj->users); */
/*         if (!id) */
/*             return NULL; */

/*         // why regenerate is correct? */
/*         /\\* if (userId == 107) *\\/ */
/*         /\\*     genNews(obj, getUser(obj,userId)); *\\/ */
/*         // printf("107 got %d.\n", pTweets(u->follow[i])); */

/*         Tweets* t = &(obj->users[id]->news); */
/*         int s = t->in + 9; */
/*         int l = t->num >= 10 ? 10 : t->num; */

/*         *returnSize = l; */
/*         r = malloc(sizeof(int) * l); */
/*         for (int i = 0; i < l; i ++) */
/*         { */
/*             r[i] = (t->time_id[s % 10]) & 0xFFFFFFFF; */
/*             s --; */
/*         } */
/*     } */
/*     return r; */
/* } */

/* /\\** Follower follows a followee. If the operation is invalid, it should be a no-op. *\\/ */
/* void twitterFollow(Twitter* obj, int followerId, int followeeId) */
/* { */
/*     if (followerId == followeeId) */
/*         return; */

/*     /\\* if (followerId == 107) *\\/ */
/*     /\\*     printf("107 follow %d.\n", followeeId); *\\/ */

/*     if (obj) */
/*     { */
/*         User* u_frid = getUser(obj, followerId); */
/*         User* u_feid = getUser(obj, followeeId); */

/*         addFollowby(u_feid, u_frid); */

/*         if (addFollow(u_frid, u_feid)) */
/*         { */
/*             if (followerId == 107) */
/*             { */
/*                 /\\* printf("107 follow %d and genNews before.\n", followeeId); *\\/ */
/*                 int rs = 0; */
/*                 int* r = twitterGetNewsFeed(obj, followerId, &rs); */
/*                 out(r, rs); */
/*             } */
/*             genNews(obj, u_frid); */
/*             if (followerId == 107) */
/*             { */
/*                 /\\* printf("107 follow %d and genNews end.\n", followeeId); *\\/ */
/*                 int rs = 0; */
/*                 int* r = twitterGetNewsFeed(obj, followerId, &rs); */
/*                 out(r, rs); */
/*             } */
/*         } */
/* } */
/* } */

/* /\\** Follower unfollows a followee. If the operation is invalid, it should be a no-op. *\\/ */
/* void twitterUnfollow(Twitter* obj, int followerId, int followeeId) { */

/*     if (followerId == followeeId) */
/*         return; */

/*     /\\* if (followerId == 107) *\\/ */
/*     /\\*     printf("107 unfollow %d.\n", followeeId); *\\/ */

/*     if (obj) */
/*     { */
/*         User* u_frid = getUser(obj, followerId); */
/*         User* u_feid = getUser(obj, followeeId); */
/*         removeFollowby(u_feid, u_frid); */

/*         if (removeFollow(u_frid, u_feid)) */
/*             genNews(obj, u_frid); */
/*     } */
/* } */

/* void twitterFree(Twitter* obj) { */

/*     if (obj) */
/*     { */
/*         free(obj->hash); */
/*         free(obj->heap); */
/*         free(obj->users); */
/*         free(obj); */
/*     } */
/* } */

/* /\\** */
/*  * Your Twitter struct will be instantiated and called as such: */
/*  * struct Twitter* obj = twitterCreate(); */
/*  * twitterPostTweet(obj, userId, tweetId); */
/*  * int* param_2 = twitterGetNewsFeed(obj, userId); */
/*  * twitterFollow(obj, followerId, followeeId); */
/*  * twitterUnfollow(obj, followerId, followeeId); */
/*  * twitterFree(obj); */
/*  *\\/ */
