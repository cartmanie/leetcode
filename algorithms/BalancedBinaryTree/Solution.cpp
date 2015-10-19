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
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
        {
            return true;
        }
        
        int depth_left = depthTree(root->left);
        int depth_right = depthTree(root->right);
        if (abs(depth_left-depth_right) <= 1)
        {
            return isBalanced(root->left) && isBalanced(root->right);
        }
        else
        {
            return false;
        }
    }
    
    private:
    int depthTree(TreeNode* root)
    {
        if (root == NULL)
        {
            return -1;
        }
        
        int depth_left = 0;
        int depth_right = 0;
        
        if (root->left)
        {
            depth_left = 1;
            depth_left = depth_left+depthTree(root->left);
        }
            
        if (root->right)
        {
            depth_right = 1;
            depth_right = depth_right+depthTree(root->right); 
        }
            
            
        return depth_left>depth_right?depth_left:depth_right;
    }
};