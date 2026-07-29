int largestAltitude(int* gain, int gainSize) {
    int *out=(int *)calloc(gainSize+1, sizeof(int));
    int max=out[0];
    for(int i=1; i<=gainSize; i++){
        out[i]=out[i-1]+gain[i-1];
        if(out[i]>max) max=out[i];
    }
    return max;
}