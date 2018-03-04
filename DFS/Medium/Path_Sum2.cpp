/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {  //Single node case
private:
    vector<vector<int>> res;
    void f(vector<int> prev, int sum, TreeNode* root ){
        //If a null node return
        if(!root)
            return;
        
        prev.push_back(root->val); 
        
        //If it is a leaf node
        if( !root->left  &&  !root->right ){
            if( sum - root->val == 0 )
                res.push_back(prev);
            return;
        }
        
        //If not a leaf node
        f(prev, sum - root->val , root->left);
        f(prev, sum - root->val , root->right);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)
            return res;
        
        //To every node a vector is attached
        vector<int> prev(1,root->val);
        
        //For single node case
        if(!root->left   &&   !root->right  &&  sum == root->val )
            res.push_back(prev);
        
        f( prev, sum - root->val, root->left );
        f( prev, sum - root->val, root->right );
        return res;
    }
};
