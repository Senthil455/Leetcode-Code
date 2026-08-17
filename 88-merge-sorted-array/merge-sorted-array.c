void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int result[m+n];
    int i=0, j=0, k=0;
    while(i<m && j<n){
        if (nums1[i]<= nums2[j])
            result[k++] =nums1[i++];
        else
            result[k++]=nums2[j++];
    }
    while(i<m){
            result[k++] =nums1[i++];
    }
    while(j<n){
            result[k++] =nums2[j++];
    }
    for(int i=0;i<m+n;i++){
        nums1[i]=result[i];
    }
}