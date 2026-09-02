bool uniformArray(int* nums1, int nums1Size) {
    /*int *nums2= (int *)malloc(nums1Size * sizeof(int));
    for(int i=0; i<nums1Size; i++){
        for(int j=i; j<nums1Size; j++){
            if(j!=i){
                nums2[i] = nums1[i] - nums1[j];
            }
            else{
                nums2[i] = nums1[i];
            }
        }
    }
    int res= abs(nums2[0] %2);
    for(int i=0; i<nums1Size; i++){
        if(abs(nums2[i] % 2) != res){
            return false;
        }
    }
    free(nums2); */
    return true;
}