
int rob(int* nums, int numsSize)
{
    /* the optimal outcome at house `i` only depends on the 
        previous 2 houses */
    int optimal[3] = { 0, 0, 0 };
    for ( int i = 0; i < numsSize; ++i )
    {
        optimal[2] = (int) fmax( optimal[1], optimal[0]+nums[i] );
        optimal[0] = optimal[1];
        optimal[1] = optimal[2];
    }
    return optimal[2];
}