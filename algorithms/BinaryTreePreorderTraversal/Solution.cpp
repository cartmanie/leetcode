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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        
        if (root == NULL)
        {
            return result;
        }
        
        vector<TreeNode*> resultNodes;

        stack<TreeNode*> leftS;
        stack<TreeNode*> rightS;
        
        resultNodes.push_back(root);
        if (root->left)
        {
            leftS.push(root->left);
        }
        if (root->right)
        {
            rightS.push(root->right);
        }
        

loop:
        while(!leftS.empty())
        {
            TreeNode* t = leftS.top();
            if (isLeaf(t))
            {
                resultNodes.push_back(t);
                leftS.pop();
            }
            else
            if (hasSingleChild(t))
            {
                if (t->left)
                {
                    resultNodes.push_back(t);
                    leftS.pop();
                    leftS.push(t->left);
                }
                
                if (t->right)
                {
                    resultNodes.push_back(t);
                    leftS.pop();
                    rightS.push(t->right);
                }
            }
            else
            {
                resultNodes.push_back(t);
                leftS.pop();
                leftS.push(t->left);
                rightS.push(t->right);
            }
        }
        
        while(!rightS.empty())
        {
            TreeNode* t = rightS.top();
            if (isLeaf(t))
            {
                resultNodes.push_back(t);
                rightS.pop();
            }
            else
            if (hasSingleChild(t))
            {
                if (t->left)
                {
                    resultNodes.push_back(t);
                    rightS.pop();
                    leftS.push(t->left);
                    goto loop;
                }
              
                if (t->right)
                {
                    resultNodes.push_back(t);
                    rightS.pop();
                    rightS.push(t->right);
                } 
            }
            else 
            {
                resultNodes.push_back(t);
                rightS.pop();
                leftS.push(t->left);
                rightS.push(t->right);
                goto loop;
            }
        }
        

        for (int i = 0;i<resultNodes.size(); i++)   
        {
            result.push_back(resultNodes[i]->val);
        }

  
    }
    
private:
    bool isLeaf(TreeNode* node)
    {
        return !node->left && !node->right;
    }
    
    bool hasSingleChild(TreeNode* node)
    {
        return (node->left && !node->right)
            || (!node->left && node->right);
    }
};
