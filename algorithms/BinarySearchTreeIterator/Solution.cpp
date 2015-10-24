/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include "assert.h"
using std::cout;

struct TreeNode
{
    /* data */
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL) {}
};


class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        ordered_vec_.clear();
        traversal(root,ordered_vec_);
        iterator_ = ordered_vec_.begin();
    }

    void traversal(TreeNode* root,std::vector<TreeNode*> &result)
    {
        if (!root)
        {
            return;
        }
        
        if (!root->left && !root->right)
        {
            result.push_back(root);
            return;
        }

        if (root->left)
        {
            traversal(root->left,result);
        }

        result.push_back(root);

        if (root->right)
        {
            traversal(root->right,result);
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return iterator_ != ordered_vec_.end();   
    }

    /** @return the next smallest number */
    int next() {
        return (*(iterator_++))->val;
    }

private:
    std::vector<TreeNode*> ordered_vec_;
    std::vector<TreeNode*>::iterator iterator_;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

 TreeNode *insert(TreeNode* root,int val)
 {
    if (root == NULL)
    {
        root = new TreeNode(val);
        return root;
    }

    if (val < root->val)
    {
        root->left = insert(root->left,val);
    }
    else if (val > root->val)
    {
        root->right = insert(root->right,val);
    }
    else
    {
        return root;
    }

    return root;
 }

 void dump(TreeNode* root)
 {
    std::cout<<" "<<root->val<<" ";
    if (root->left)
        dump(root->left);
    if (root->right)
        dump(root->right);
 }

 
std::vector<TreeNode *> constructBST()
{
    std::vector<TreeNode*> v;

        
    // testcase 1
    {
        TreeNode* root=NULL;
        for (int i =0;i<100;i++)
        {
            root = insert(root,i);
        }
        v.push_back(root);
    }
    

    // testcase 2
    {
        TreeNode* root=NULL;
        int a[] = {50,90,100,80,70,60};
        for (int i =0;i<sizeof(a)/sizeof(a[0]);i++)
        {
            root = insert(root,a[i]);
        } 
        v.push_back(root);

    }


    // testcase 3
    {
        TreeNode* root=NULL;
        int a[] = {1,0,3,2,4};
        for (int i =0;i<sizeof(a)/sizeof(a[0]);i++)
        {
            root = insert(root,a[i]);
        } 
        v.push_back(root);

    }


    // testcase 4
    {
        TreeNode* root=NULL;
        int a[] = {3,1,4,2};
        for (int i =0;i<sizeof(a)/sizeof(a[0]);i++)
        {
            root = insert(root,a[i]);
        } 
        v.push_back(root);

    }
    
    return v;
}


void test1()
 {
    std::vector<TreeNode *> v = constructBST();
    std::vector<TreeNode*>::iterator it;
    for (it  = v.begin(); it!= v.end(); it++)
    {
        TreeNode* root = (*it);
        std::cout<<"---------------------"<<std::endl;
        dump(root);
        std::cout<<std::endl<<"---------------------"<<std::endl;

        BSTIterator i(root);
        while (i.hasNext())
        {
            cout << i.next();
            cout<<" ";
        } 
        std::cout<<std::endl;
    }
    
 }


 int main(int ,char**)
 {
  
    test1();

    return 0;
 }
