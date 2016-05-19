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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == NULL || q == NULL)
        {
            return NULL;
        }
        
        // p is parent 
        if (p->left == q || p->right == q)
        {
            return p;
        }
        
        // q is parent
        if (q->left == p || q->right == p)
        {
            return q;
        }
        
        // p is left q is right
        if (root->val > p->val && root->val < q->val)
        {
            return root;
        }
        
        //  q isleft p is right
        if (root->val > q->val && root->val < p->val)
        {
            return root;
        }
        
        // all left
        if (root->val > p->val && root->val > q->val)
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        
        // all right
        if (root->val < p->val && root->val < q->val)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        
        return root;
    }
};
