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
        
        //Setting for the root level
        root->next = NULL;
        
        //This is the leftmost node of any level
        TreeLinkNode* curr = root;
        
        while(curr->left){  //This is for checking whether next level is NULL or not
            
            //Movable pointer for this level
            TreeLinkNode* temp = curr;
            
            while(temp){ //Setting for the level below
                
                //Setting the next for the left child
                temp->left->next = temp->right;
                
                //Setting the next for the left child
                temp->right->next = (temp->next)?   temp->next->left:NULL;
                
                //Moving the movable pointer forward
                temp = temp->next;
            }
            
            //Moving the curr pointer to the lower level
            curr = curr->left;
        }
    }
};