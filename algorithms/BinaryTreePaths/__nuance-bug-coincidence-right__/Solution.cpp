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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<vector<TreeNode*> > resultNodes;
        vector<vector<TreeNode*> > resultNodes_copy;
        
        if (root == NULL)
        {
            return result;
        }
        
        // init resultNodes
        vector<TreeNode*> t;
        t.push_back(root);
        resultNodes.push_back(t);
        
        // init resultNodes_copy
        resultNodes_copy = resultNodes;
        
loop:        
        int size = resultNodes.size();
        int leaf_nodes_counter = 0;
        for (int i=0;i<size ;i++)
        {
            vector<TreeNode*> t = resultNodes[i];
            TreeNode* last = *(t.end()-1);
            if (isLeaf(last))
            {
                leaf_nodes_counter++;
                continue;
            }
            else if (hasSingleChild(last))
            {
                if (last->left)
                {
                    t.push_back(last->left);
                    resultNodes[i] = t;
                }
                
                if (last->right)
                {
                    t.push_back(last->right);
                    resultNodes[i] = t;
                }
                
                resultNodes_copy = resultNodes;
            }
            else
            {
                vector<TreeNode*> left = t;
                vector<TreeNode*> right = t;
                left.push_back(last->left);
                right.push_back(last->right);
                
                resultNodes_copy = resultNodes;
                resultNodes_copy[i] = left;
                resultNodes_copy.insert(resultNodes_copy.begin() + i+1, right);
            }
                            
        }
        
        if (leaf_nodes_counter == size)
        {
             result = constructStringFromNodesVector(resultNodes_copy);
             return result;     
        }
        else
        {
            resultNodes = resultNodes_copy;
            leaf_nodes_counter = 0;
            goto loop;
        }
    }
    
    private:
    bool isLeaf(TreeNode* node)
    {
        return !node->left && !node->right;
    }
    
    bool hasSingleChild(TreeNode* node)
    {
        return  (node->left && !node->right)
            ||  (!node->left && node->right);
    }
    
    vector<string> constructStringFromNodesVector(vector<vector<TreeNode*> > resultNodes ) 
    {
        vector<string> result;
        for (int i = 0;i<resultNodes.size(); i++)
        {
            std::string s;
            vector<TreeNode*> t = resultNodes[i];
            for (int j = 0;j<t.size(); j++)
            {
                TreeNode* p = t[j];
                char buf[8] = {0};
                if (j==t.size()-1)
                {
                   sprintf(buf,"%d",p->val); 
                }
                else
                {
                    sprintf(buf,"%d->",p->val);    
                }
                s.append(buf);
            }
            
            result.push_back(s);
        }
        
        return result;
    }
};
