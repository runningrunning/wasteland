/* Careful about when ls lt are both 0 */
/* bool isSubsequence(char* s, char* t) */
/* { */
/*     if (!s) */
/*         return true; */

/*     if (!t) */
/*         return false; */

/*     int ls = strlen(s); */
/*     int lt = strlen(t); */

/*     if (!ls) */
/*         return true; */

/*     if (lt < ls) */
/*         return false; */

/*     while(lt && ls) */
/*     { */
/*         ls --; */
/*         lt --; */
/*         while (t[lt] != s[ls] && lt) lt --; */
/*     } */

/*     return lt ? ls == 0 : (t[lt] == s[ls]); */
/* } */

/* faster */
bool isSubsequence(char* s, char* t)
{
    if (!s)
        return true;

    if (!t)
        return false;

    int lt = 0;
    int ls = 0;

    while(t[lt])
    {
        if (t[lt] == s[ls])
        {
            ls ++;
            if (!s[ls])
                break;
        }
        lt ++;
    }
    return !s[ls];
}
