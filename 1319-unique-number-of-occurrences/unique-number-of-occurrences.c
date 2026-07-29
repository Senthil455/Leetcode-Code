bool uniqueOccurrences(int* arr,int n) {
    int min=arr[0], max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<min) min=arr[i];
        if(arr[i]>max) max=arr[i];
    }
    int size = max-min+1;
    int*count=(int*)calloc(size,sizeof(int));
    for(int i=0;i<n;i++){
        count[arr[i]-min]++;
    }
    for(int i=0;i<size;i++){
        if(count[i]==0) continue;
        for(int j=i+1;j<size;j++){
            if(count[i]==count[j]){
                free(count);
                return false;
            }
        }
    }
    free(count);
    return true;
}