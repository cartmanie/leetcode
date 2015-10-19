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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
        {
            return root;
        }
        
        if (root->left || root->right)
        {
            swap(root,invertTree(root->left),invertTree(root->right));
        }
        
        return root;
    }
    
    private:
    void swap(TreeNode* parent,TreeNode* left,TreeNode* right)
    {
        parent->left = right;
        parent->right = left;
    }
};