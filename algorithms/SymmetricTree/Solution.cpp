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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)    
        {
            return true;
        }
        
        vector<TreeNode*> queue1;
        queue1.clear();
        vector<TreeNode*> queue2;
        queue2.clear();
        
        if (root->left)
        {
            queue1.push_back(root->left);
        }
        
        if (root->right)
        {
            queue1.push_back(root->right);
        }
        
        
        if (!isSymmetricVector(queue1))
        {
            return false;
        }
        

        while(queue1.size()>0)
        {
            queue2.push_back(queue1[0]);
            queue1.erase(queue1.begin());
            
            if (queue1.size() == 0)
            {
                vector<TreeNode*>::iterator it ;
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
                
                if (!isSymmetricNodeChild(queue2))
                {
                    return false;
                }
                
                if (!isSymmetricVector(queue1))
                {
                    return false;
                }

                queue2.clear();
            }
        }
        
        return true;
    }
    
    private:
    bool isSymmetricVector(vector<TreeNode *> vec)
    {
        int size = vec.size();
        if (size == 0)
        {
            return true;
        }
        
        if (size == 1)
        {
            return false;
        }
      
        for (int i =0;i<vec.size()/2;i++)
        {
            if (vec[i]->val != vec[size-1-i]->val)
            {
                return false;
            }

        }
        
        return true;
    }
    
    bool isSymmetricNodeChild(vector<TreeNode*> vec)
    {
        int size = vec.size();
        if (size == 0 )
        {
            return true;
        }
        
        if (size == 1)
        {
            return false;
        }
        
        for (int i =0;i<vec.size()/2;i++)
        {
            TreeNode* first = vec[i];
            TreeNode* second = vec[size-1-i];
            
            // case : NULL NULL NULL NULL
            if (first->left == second->right && first->right == second->left)
            {
                continue;
            }
            
            if (first->left)
            {
                if (second->right)
                {
                    if (first->left->val != second->right->val)
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (second->right)
                {
                    return false;
                }
            }
            
            if (first->right)
            {
                if (second->left)
                {
                    if (first->right->val != second->left->val)
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (second->left)
                {
                    return false;
                }
            }
            
        }
        
        return true;
 
        
    }
};