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
    int countNodes(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
        
        int leftDepth = leftTreeDepth(root->left);
        int rightDepth = rightTreeDepth(root->right);
        if (leftDepth == rightDepth)
        {
            return pow(2,leftDepth+1)-1;
        }
        else
        {
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }
    
    
    private:
    int leftTreeDepth(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        
        int cnt = 1;
        TreeNode* p = root;
        while(p = p->left)
        {
            cnt++;
        }
        
        return cnt;
    }
    
    int rightTreeDepth(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        
        int cnt = 1;
        TreeNode* p = root;
        while(p = p->right)
        {
            cnt++;
        }
        
        return cnt;
        
    }
    

};
