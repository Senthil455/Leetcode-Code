int compare(const void *a,const void *b)
{
    int *intervals_A=*(int**)a;
    int *intervals_B=*(int**)b;
    return intervals_A[0]-intervals_B[0];
}



int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) 
{
    int count=0;

 qsort(intervals,intervalsSize,sizeof(int*),compare);

int prev_End=intervals[0][1];
for(int i=1;i<intervalsSize;i++)

if(intervals[i][0]<prev_End)
{
    count++;
    prev_End=(intervals[i][1]<prev_End)?intervals[i][1]:prev_End;
}
    else
    {
       prev_End=intervals[i][1]; 
    }

return count;
    
}