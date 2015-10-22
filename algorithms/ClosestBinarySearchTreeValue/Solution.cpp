/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <math.h>
#include <assert.h>


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if (root == NULL)
        {
            return 0;
        }

        int closest = root->val;
        double gap = interval(root, target);
        return closestValue_i(root,target,gap,closest);
    }


private:
    int closestValue_i(TreeNode *root,double target, double gap,int closest)
    {
    	//std::cout<<"gap -> "<<gap <<"closest ->"<<closest<<std::endl;
        if (root == NULL)
        {
            return closest;
        }
        

        // update if possible
        if (interval(root,target)<gap)
        {
            gap = interval(root,target);
            closest = root->val;
        }

        int left_closest = closestValue_i(root->left,target,gap,closest);
        int right_closet = closestValue_i(root->right,target,gap,closest);

        if (fabs(left_closest-target)<fabs(right_closet-target))
        {
        	return left_closest;
        }
        else
        {
        	return right_closet;
        }
    }
        

private:
    double interval(TreeNode* node, double target)
    {
        return fabs(node->val - target);
    }
};


TreeNode* insert(TreeNode* root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return root;
    }

    if (val < root->val)
    {
        root->left =  insert(root->left,val);
    }
    else
    if ( val > root->val)
    {
        root->right = insert(root->right,val);
    }
    else
    {
        return root;
    }

    return root;
}

TreeNode* constructBST()
{
    //TreeNode *tree = new TreeNode(1);
    //tree->left = new TreeNode(0);
    //tree->right = new TreeNode(2);

    TreeNode *bst=NULL; 
    while(!std::cin.eof())
    {
        int val;
        std::cout<<"input bst node value ->";
        std::cin>>val;
        bst = insert(bst,val);
        // TreeNode *bst = insert(NULL,1);
        // insert(bst,2);
        // insert(bst,3);
        // insert(bst,4);
        // insert(bst,5);
        // insert(bst,6);
    }
    
    return bst;
}

void dump(TreeNode* tree)
{
    if (tree)
    {
            std::cout<<" "<<tree->val;
            dump(tree->left);
            dump(tree->right);
    }
}

void test()
{
    float number;
    std::cout<<"input the target number :"<<std::endl;
    std::cin>>number;
    std::cout<<" the target number is "<<number<<std::endl;
 
 	
    TreeNode *bst = constructBST();
    std::cout<<"-----------------------------"<<std::endl;
    dump(bst);
    std::cout<<std::endl<<"-----------------------------"<<std::endl;


    Solution solution;
   
    int closest = solution.closestValue(bst,number);
    std::cout<<"closet is "<<closest<<std::endl;
}


int main(int ,char**)
{
    test();
    return 0;
}
