int findPeakElement(int* nums, int numsSize)
{
    int i;
    long max;

    i = 1;
    max = -2147483649;
    while (i < numsSize - 1)
    {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1] && nums[i] > max)
            max = i;
        i++;
    }
    if (max == -2147483649)
    {
        if (nums[0] > nums[numsSize - 1])
            return (0);
        return (numsSize - 1);
    }
    return ((int)max);
}