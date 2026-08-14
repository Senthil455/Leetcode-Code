class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int start=0,end=rows*cols-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(matrix[mid/cols][mid%cols]==target)  return true;
            else if(matrix[mid/cols][mid%cols]>target)  end=mid-1;
            else start=mid+1;
        }
        return false;
    }
};