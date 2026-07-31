/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    //lets first find the node to delete
    if(root==NULL) return root;
    struct TreeNode* prev=NULL, *curr=root;
    while(curr&&curr->val!=key){
        prev=curr;
        if(curr->val<key){
            curr=curr->right;
        }else{
            curr=curr->left;
        }
    }
    if(curr==NULL) return root;
    //now curr points to the node to delete
    //the main question that comes here is 
    //that how should we replace this node with another
    //while maintaining the BST properties
    //if its leaf node its pretty easy just point 
    //prev node poitnters left or rigth to null and we are done
    //but in case of the non leaf node its tricky
    // we should find some value which will not break the BST
    // see such values in left or right subtree
    //can you point those values 
    //it is either the greatest value of left subtree or smallest value of right subtree
    //to find that we simply can go to curr->right and then to its left until we find the leaf node
    // or go to curr->left and then to its right until we found a leaf node
    if(!curr->right){
        if(!prev) return curr->left;
        if(prev->left==curr){
            prev->left=curr->left;
        }else{
            prev->right=curr->left;
        }
        return root;
    }
    struct TreeNode* to_replace = curr->right,*prevtr=NULL;
    while(to_replace && to_replace->left){
        prevtr=to_replace;
        to_replace=to_replace->left;
    }
    if(prevtr){
        prevtr->left=to_replace->right;
        to_replace->right=curr->right;
    }
    to_replace->left=curr->left;
    if(!prev) return to_replace;
    if(prev->left==curr){
        prev->left=to_replace;
    }else{
        prev->right=to_replace;
    }
    return root;
}