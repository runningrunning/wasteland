char* complexNumberMultiply(char* a, char* b)
{
    int an, ai;
    int bn, bi;
    sscanf(a, "%d+%di", &an, &ai);
    sscanf(b, "%d+%di", &bn, &bi);

    int cn = an * bn - ai * bi;
    int ci = an * bi + bn * ai;

    char* c = malloc(256);
    memset(c, 0, 256);

    sprintf(c, "%d+%di", cn, ci);
    return c;
}
