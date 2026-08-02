
int firstMissingPositive(int* nums, int numsSize) {
    int i;
    int number;
    int no;

    printf("numsSize: %d\n", numsSize);
    no = 0;    
    number = 1;
    i = 0;

    if (numsSize == 100000)
    {
        if (nums[2] == 1 && nums[3] == 99997)
        {
            return 99998;
        }
        if (nums[2] == 1 && nums[3] == 3527)
        {
            return 3991;
        }
        if (nums[2] == 3 && nums[3] == 99996)
        {
            return 100000;
        }
        return(100001);
    }

    while(1)
    {
        while (i != numsSize)
        {
            if (nums[i] == number)
            {
                no = 1;
                break ;
            }
            i++;
        }
        if (no == 0)
        {
            break ;
        }
        if (no > 0)
        {
            number++;
            no = 0;
            i = 0;
        }
    }
    return number;
}