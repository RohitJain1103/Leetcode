/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {  //This is just inorder traversal !! 
    stack<TreeNode *> sta;
public:
    BSTIterator(TreeNode *root) {
        pushall(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !sta.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *temp = sta.top(); sta.pop();
        pushall( temp->right );
        return temp->val;
    }
    void pushall(TreeNode *root){
        while(root){
            sta.push(root); root = root->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */