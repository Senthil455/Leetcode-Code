/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    bool *out=(bool*)malloc(candiesSize*sizeof(bool));
    for(int i=0; i<candiesSize ; i++){
        int k=candies[i]+extraCandies;
        for(int j=0; j<candiesSize ; j++){
            if(k<candies[j]){
                out[i]=false;
                break;
            }
            out[i]=true;
        }
    }
    *returnSize=candiesSize;
    return out;
}