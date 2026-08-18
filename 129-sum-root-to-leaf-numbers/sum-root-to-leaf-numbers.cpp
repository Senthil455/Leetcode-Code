class Solution {
public:
    void solve(TreeNode* root,int& sum,int temp){
      if(!root)return;
      
      if(!root->left && !root->right){
        temp = 10* temp + root->val;
        sum+=temp;
        temp=0;
      }
      
      temp = 10* temp + root->val;
      
      solve(root->left,sum,temp);
      solve(root->right,sum,temp);
      
      return;
    }
    int sumNumbers(TreeNode* root) {
      int sum=0;
      int temp=0;
      solve(root,sum,temp);
      return sum;
    }
};