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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root)
            return 0;
        
        //saves maxm. width
        int maxi = 0;
        
        //We will do simple level wise bfs and save the nodes,node_val(like a heap) as a pair in queue
        queue< pair< TreeNode* , int > > q;
        
        q.push( make_pair( root,0 ) );
        
        while( !q.empty() ){ //For each level
            
            //Saving the value for leftmost and rightmost node in this level
            int leftmost = q.front().second , rightmost, sz = q.size();
            
            for( int i = 0 ; i < sz ; i++ ){
                pair< TreeNode* , int > pp = q.front();
                q.pop();
                
                //If left child is not NULL then push it 
                if( pp.first->left ) q.push( make_pair( pp.first->left, 2*pp.second + 1 ) );
                
                //If right child is not NULL then push it 
                if( pp.first->right ) q.push( make_pair( pp.first->right, 2*pp.second + 2 ) );
                
                //At the end of this loop we will get the value for the rightmost node
                rightmost = pp.second;
            }
            
            //Seeing the width for the present level
            maxi = max( maxi , rightmost - leftmost + 1 );
            
        }
        
        return maxi;
    }
};