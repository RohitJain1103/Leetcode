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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        //Searching for the element
        TreeNode *temp = root,*temp1,*prev = root;
        while(temp && temp->val != key){
            prev = temp;
            if(temp->val > key)
                temp = temp->left;
            else
                temp = temp->right;
        }
        
        //If we didn't find the element
        if(!temp) return root;
        
        //Finding the leftmost child of the right child
        temp1 = temp->right;
        //If right child is NULL, then just make the left node as this node
        if(!temp1){
            if(prev == temp) return prev->left;
            else if(prev->left == temp)
                prev->left = temp->left;
            else
                prev->right = temp->left;
            return root;
        }
        //This is for finding the parent of the root to be deleted
        while(temp1->left && temp1->left->left)  temp1 = temp1->left;
        if(!temp1->left){
            temp->val = temp1->val;
            temp->right = temp1->right;
        }
        else{
            temp->val = temp1->left->val;
            temp1->left = temp1->left->right;
        }
        return root;
    }
};