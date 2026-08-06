int hIndex(int* citations, int citationsSize){
    int *buckets = calloc(citationsSize+1, sizeof(*buckets));

    for (int i = 0; i < citationsSize; ++i) {
        if(citations[i] >= citationsSize) {
            buckets[citationsSize]++;
        } else {
            buckets[citations[i]]++;
        }
    }
    int count = 0;
    for (int i = citationsSize; i >= 0; --i) {
        count += buckets[i];
        if (count >= i) {
            return i;
        }
    }
    free(buckets);
    
    return 0;
}