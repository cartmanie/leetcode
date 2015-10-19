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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
        
        int depth_left = 1;
        int depth_right = 1;
        
        if (root->left)
        {
             depth_left =  depth_left+ maxDepth(root->left);   
        }
        
        if (root->right)
        {
            depth_right = depth_right+maxDepth(root->right);
        }
        
        return depth_left>depth_right?depth_left:depth_right;
    }
};