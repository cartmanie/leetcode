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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result ;
        
        if (root == NULL)
        {
            return result;
        }
        
        // the intermedia result
        vector<vector<TreeNode*> > resultNodes;
        
        // level tranversal
        vector<TreeNode*> q1;
        vector<TreeNode*> q2;
        
        // init 
        q1.push_back(root);
        
        // init 
        vector<TreeNode*> t;
        t.push_back(root);
        resultNodes.push_back(t);
        
        while(q1.size() >0)
        {
            q2.push_back(*(q1.begin()));
            q1.erase(q1.begin());

            if (q1.size() == 0)
            {
  
                vector<TreeNode*>::iterator it;
                for (it = q2.begin(); it!=q2.end(); it++)
                {
                    if ((*it)->left)
                    {
                        q1.push_back((*it)->left);
                    }
                    
                    if ((*it)->right)
                    {
                        q1.push_back((*it)->right);
                    }
                }
                
                q2.clear();
                
                // bottom -> up
                if (q1.size() >0 )
                {
                   resultNodes.insert(resultNodes.begin(),q1); 
                }
             }
         }
        
        result = constructVectorFromNodes(resultNodes);
        return result;
    }
    
    private:
    vector<vector<int> > constructVectorFromNodes(vector<vector<TreeNode*> > resultNodes)
    {
        vector<vector<int> > result;
        int size = resultNodes.size();
        for (int i =0;i<size;i++)
        {
            vector<TreeNode*> vec = resultNodes[i];
            vector<int> singleVec;
            vector<TreeNode*>::iterator it;
            for (it = vec.begin(); it!=vec.end();it++)
            {
                int val = (*it)->val;
                singleVec.push_back(val);
            }
            
            result.push_back(singleVec);
        }
        return result;
    }
};
