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
    bool isValidBST(TreeNode* root) {
        if (root == NULL)    
        {
            return true;
        }
        
        if (root->left && root->right)
        {
            return 
               isLeftValid(root,root->left) 
            && isRightValid(root,root->right)
            && isValidBST(root->left) 
            && isValidBST(root->right);
        }
        
        if (root->left && !root->right)
        {
            return isLeftValid(root,root->left) 
            && isValidBST(root->left);
        }
        
        if (!root->left && root->right)
        {
            return 
              isRightValid(root,root->right)
            &&isValidBST(root->right);
        }
        
        return true;
    }
    
    
    private:
    //root > all of left
    bool isLeftValid(TreeNode* root,TreeNode* left)
    {
        if (left == NULL)
            return true;
            
            
        //visitRoot(left);
        if (!(root->val > left->val))
            return false;
        
        //visitLeft(left->left);
        //root->val > all of left->left;
        if (!isLeftValid(root,left->left))
            return false;
        
        //visitRight(left->right);
        //root->val > all of left->right;
        if (!isLeftValid(root,left->right))
            return false;
            
        return true;
    }
    
    
    // root < all of right
    bool isRightValid(TreeNode* root,TreeNode* right)
    {
        if (right == NULL)
            return true;
            
            
        //visitRoot(right);
        if (!(root->val < right->val))
            return false;
        
        //visitLeft(right->left);
        //root->val < all of right->left;
        if (!isRightValid(root,right->left))
            return false;
        
        //visitRight(right->right);
        //root->val < all of right->right;
        if (!isRightValid(root,right->right))
            return false;
            
        return true;
    }
    

};
