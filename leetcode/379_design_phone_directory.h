// Use lookup Bits Table is kinda of waste !
struct PDNode {
    int num;
    struct PDNode* next;
} PDNode;

typedef struct {
    int max_num; // max number
    int cur_num; // next allocate
    int* flags;
    struct PDNode* free;
} PhoneDirectory;

/** Initialize your data structure here
    @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
PhoneDirectory* phoneDirectoryCreate(int maxNumbers) {
    PhoneDirectory* pd = malloc(sizeof(PhoneDirectory));
    pd->cur_num = 0;
    pd->max_num = maxNumbers;
    pd->free = NULL;
    int fl = (maxNumbers + 31) / 32;
    pd->flags = malloc(sizeof(int) * fl);
    memset(pd->flags, 0, sizeof(int) * fl);
    return pd;
}

/** Provide a number which is not assigned to anyone.
    @return - Return an available number. Return -1 if none is available. */
int phoneDirectoryGet(PhoneDirectory* pd) {
    if (!pd)
        return -1;

    int num = -1;

    if (pd->free)
    {
        struct PDNode* t = pd->free;
        pd->free = t->next;
        num = t->num;
        free(t);
    }
    else
    {
        if (pd->cur_num < pd->max_num)
            num = pd->cur_num ++;
    }

    int fl = num / 32;
    int fb = num % 32;
    pd->flags[fl] |= 1 << fb;

    return num;
}

/** Check if a number is available or not. */
bool phoneDirectoryCheck(PhoneDirectory* pd, int number) {
    if (!pd || number < 0 || number >= pd->max_num)
        return false;

    if (number >= pd->cur_num)
        return true;

    int fl = number / 32;
    int fb = number % 32;
    return !(pd->flags[fl] & (1 << fb));

    /* struct PDNode* t = pd->free; */
    /* while(t) */
    /* { */
    /*     if (t->num == number) */
    /*         return true; */

    /*     t = t->next; */
    /* } */

    /* return false; */
}

/** Recycle or release a number. */
void phoneDirectoryRelease(PhoneDirectory* pd, int number) {
    if (!pd)
        return;

    if (number < 0 || number >= pd->cur_num)
        return;

    int fl = number / 32;
    int fb = number % 32;
    if (!(pd->flags[fl] & (1 << fb)))
        return;

    pd->flags[fl] &= ~(1 << fb);

    if (number == pd->cur_num - 1)
    {
        pd->cur_num --;
        return;
    }


    // struct PDNode* t = pd->free;
    /* while(t) */
    /* { */
    /*     if (t->num == number) */
    /*         return; */
    /*     t = t->next; */
    /* } */

    struct PDNode* t = malloc(sizeof(struct PDNode));
    t->num = number;
    t->next = pd->free;
    pd->free = t;
}

void phoneDirectoryFree(PhoneDirectory* pd) {
    if (pd)
    {
        struct PDNode* t = pd->free;
        while(t)
        {
            struct PDNode* r = t;
            t = t->next;
            free(r);
        }

        free(pd->flags);
        free(pd);
    }
}

/**
 * Your PhoneDirectory struct will be instantiated and called as such:
 * struct PhoneDirectory* obj = phoneDirectoryCreate(maxNumbers);
 * int param_1 = phoneDirectoryGet(obj);
 * bool param_2 = phoneDirectoryCheck(obj, number);
 * phoneDirectoryRelease(obj, number);
 * phoneDirectoryFree(obj);
 */
