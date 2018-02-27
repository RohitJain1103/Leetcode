/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int maxi = 0;  //This is the answer that we want
    int f(TreeNode *root){ //This will return the value of the maxm. length
        if(!root) return 0;
        
        //'l' and 'r' save the maxm. length for left and right child
        int l = f(root->left),r = f(root->right),maxim = 1;
        
        //Only left child has same value as parent
        if(root->left && root->val == root->left->val)
            maxim = 1 + l;
        
        //Only right child has same value as parent
        if(root->right && root->val == root->right->val)
            maxim = max( maxim , 1 + r );
        
        //Both the child have same value as parent
        if(root->left && root->right && root->val==root->left->val && root->val==root->right->val)
            maxi = max(maxi,l+r+1);
        
        //Saving the maximum uptil now
        maxi = max(maxi,maxim);
        
        return maxim;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        //We go on to leaf and then backtrack it
        if(!root)
            return 0;
        f(root);
        return maxi-1;
    }
};