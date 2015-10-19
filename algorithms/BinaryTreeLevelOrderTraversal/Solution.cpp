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
    vector<vector<int> > levelOrder(TreeNode* root) {
        // the result
        vector<vector<int> > result;
        result.clear();
        
        vector<TreeNode*> queue1;
        queue1.clear();
        
        vector<TreeNode*> queue2;
        queue2.clear();
        
        if (root == NULL)
        {
            return result;
        }
        
        // one level nodes
        vector<int> single_vec;
        single_vec.clear();
        
        queue1.push_back(root);
        while(queue1.size()>0)
        {
            single_vec.push_back(queue1[0]->val);
            queue2.push_back(queue1[0]);
            queue1.erase(queue1.begin());
            
            if (queue1.size() ==0 )
            {
                result.push_back(single_vec);
                single_vec.clear();
                
                vector<TreeNode*>::iterator it;
                for (it = queue2.begin();it!=queue2.end();it++)
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
        
        return result; 
    }
    
};