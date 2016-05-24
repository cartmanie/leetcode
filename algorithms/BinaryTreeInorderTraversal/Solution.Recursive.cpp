


#include <iostream>
#include <vector>
using namespace std;

struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };




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
    vector<int> result;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL)
        {
            return result;
        }
        
        // if (!root->left && !root->right)
        // {
        //     result.push_back(root->val);
        // }
        
        // s1 visit left
        if (root->left)
        {
            inorderTraversal(root->left);    
        }
        
        // s2 visit root
        result.push_back(root->val);
        
        // s3 visit right
        if (root->right)
        {
            inorderTraversal(root->right);      
        }
        
        return result;
    }
};


TreeNode* constructTree()
{
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);  
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(7);


    return root;

}


int main(int argc, char const *argv[])
{
    Solution solution;
    TreeNode* tree = constructTree();
    std::vector<int> result = solution.inorderTraversal(tree);
    for (int i = 0; i < result.size(); ++i)
    {
        /* code */
        std::cout<<" "<<result[i]<<" ";
    }
    std::cout<<std::endl;

    return 0;
}

