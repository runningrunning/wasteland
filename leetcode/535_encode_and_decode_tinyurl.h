// is it possible to get statusless solution
// just can covert 8 bits to 7 or 6 bits, then else ?
// stupid algorithm!

int size = 0;
char** strs;

/** Encodes a URL to a shortened URL. */
char* encode(char* longUrl) {
    if (size == 0)
        strs = malloc(sizeof(char*) * 1024);
    else if (!((size + 1) % 1024))
        strs = realloc(strs, sizeof(char*) * (size + 1 + 1024));

    int* id = malloc(sizeof(int));
    strs[size] = longUrl;
    id[0] = size;
    size ++;
    return (char*) id;
}

/** Decodes a shortened URL to its original URL. */
char* decode(char* shortUrl) {
    int* id = (int*) shortUrl;
    return strs[*id];
}

// Your functions will be called as such:
// char* s = encode(s);
// decode(s);

