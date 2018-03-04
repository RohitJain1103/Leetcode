/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {  //The logic behind the solution is making use of next pointers in previous level
public:
    void connect(TreeLinkNode *root) {
        if(!root) 
            return;
        root->next = NULL;
        TreeLinkNode* curr = root;  //This is the starting of any level
        while(curr->left){  //This is for checking whether next level is NULL or not
            TreeLinkNode* temp = curr;
            while(temp){ //At the level below
                temp->left->next = temp->right;
                temp->right->next = (temp->next)?   temp->next->left:NULL;
                temp = temp->next;
            }
            curr = curr->left;
        }
    }
};
