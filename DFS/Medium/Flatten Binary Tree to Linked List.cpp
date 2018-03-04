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
    //This keeps the previous pointer
    TreeNode* prev;
    
    //This is basically the preorder traversal
    void f(TreeNode* root){
        //If reached NULL pointer
        if(!root) 
            return;
        
        //Moving the prev pointer to the left
        prev = root;
        
        //As left is already linked we don't need to do anything
        f(root->left);
        
        //previous pointer(i.e. leftmost node uptil now) is linked to this right child
        if(root->right)
            prev->left = root->right;
        
        f(root->right);
    }
    
public:
    void flatten(TreeNode* root) {
        f(root);
        TreeNode* temp = root;
        while(temp){
            temp->right = temp->left;
            temp->left = NULL;
            temp = temp->right;
        }
    }
};
