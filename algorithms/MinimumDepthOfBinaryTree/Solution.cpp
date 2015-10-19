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
    int minDepth(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }

        int min_depth = 0;
        
        vector<TreeNode*> queue1;
        queue1.clear();
        vector<TreeNode*> queue2;
        queue2.clear();
        
        queue1.push_back(root);
        while(queue1.size()>0)
        {
            TreeNode* cur = queue1[0];
            if (!cur->left && !cur->right)
            {
                return min_depth+1;
            }
            queue2.push_back(cur);
            queue1.erase(queue1.begin());
            
            if (queue1.size() == 0)
            {
                min_depth++;
                vector<TreeNode*>::iterator it;
                for (it = queue2.begin(); it!= queue2.end(); it++)
                {
                    if ((*it)->left)
                    {
                        queue1.push_back((*it)->left);    
                    }
                    
                    if ((*it)->right)
                    {
                        queue1.push_back((*it)->right);
                    }
                    
                }
                queue2.clear();
            }
        }
        
        return min_depth;
        
    }
};