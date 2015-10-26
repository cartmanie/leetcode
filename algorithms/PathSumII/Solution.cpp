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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        
        if (root == NULL)
        {
            return result;
        }
        
        vector<vector<TreeNode*> > resultNodesVec;
        vector<vector<TreeNode*> > visitedNodesVec;
        vector<int> visitedSumVec;
        
        // init 
        resultNodesVec.clear();
        
        vector<TreeNode*> t;
        t.push_back(root);
        visitedNodesVec.push_back(t);
        
        visitedSumVec.push_back(root->val);
        
        // traversal
        traversal(resultNodesVec,visitedNodesVec,visitedSumVec,sum);
        
        for (int i = 0;i<resultNodesVec.size();i++)
        {
            vector<TreeNode*> v = resultNodesVec[i];
            vector<int> vj;
            for (int j = 0;j<v.size(); j++)
            {
                vj.push_back(v[j]->val);
            }
            result.push_back(vj);
        }
        
        return result;
    }
    
    
    private:
    void traversal(vector<vector<TreeNode* > > &result,vector<vector<TreeNode*> > visitedNodesVec,vector<int> sumVec,int sum)
    {
        vector<vector<TreeNode*> >  visitedNodesVec_copy;
        vector<int> sumVec_copy;
        
        int  visited_all_node_counter = 0;
        int size = visitedNodesVec.size();
        
        for (int i =0;i<size;i++)
        {
            int visitedSum = sumVec[i];
            vector<TreeNode*> visitedPath = visitedNodesVec[i];
            TreeNode* last = *(visitedPath.end()-1);
            if (isLeaf(last))
            {
                visited_all_node_counter++;
                
                if (visitedSum == sum)
                {
                    result.push_back(visitedPath);   
                    continue;
                }
            }
            else if (hasSingleChilde(last))
            {
                if (last->left)
                {
                   visitedSum += last->left->val;
                   visitedPath.push_back(last->left); 
                   
                   
                   visitedNodesVec_copy.push_back(visitedPath);
                   sumVec_copy.push_back(visitedSum);
                }
                else
                if (last->right)
                {
                    visitedSum += last->right->val;
                    visitedPath.push_back(last->right); 
                    
                   visitedNodesVec_copy.push_back(visitedPath);
                   sumVec_copy.push_back(visitedSum);
                }

            }
            else
            {
                int visitedSum_left = visitedSum+last->left->val;
                int visitedSum_right = visitedSum+last->right->val;
                
                vector<TreeNode*> visitedPath_left = visitedPath;
                vector<TreeNode*> visitedPath_right = visitedPath;
                visitedPath_left.push_back(last->left);
                visitedPath_right.push_back(last->right);
                
                visitedNodesVec_copy.push_back(visitedPath_left);
                visitedNodesVec_copy.push_back(visitedPath_right);               
                
                sumVec_copy.push_back(visitedSum_left);
                sumVec_copy.push_back(visitedSum_right);
            }
        }
        
        if (visited_all_node_counter == size)
        {
            // stop the recursion
            return;
        }
        
        traversal(result,visitedNodesVec_copy,sumVec_copy,sum);
    }

    bool isLeaf(TreeNode* node)    
    {
        return !node->left && !node->right;
    }
    
    bool hasSingleChilde(TreeNode* node)
    {
        return (node->left && !node->right)
            || (!node->left && node->right);
    }
    
    
};
