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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return NULL;
        }
        
        
        int size = nums.size();
        int rootVal = nums[size/2];
        
        TreeNode* root = new TreeNode(rootVal);
        
        vector<int> leftVector(nums.begin(),nums.begin()+size/2); //nums.range(0,size/2-1);
        vector<int> rightVector(nums.begin()+size/2+1,nums.end()) ;//nums.range(size/2+1,size-1);
        root->left = sortedArrayToBST(leftVector);
        root->right = sortedArrayToBST(rightVector);
        
        return root;
    }
};
