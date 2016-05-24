
#include "assert.h"

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
    vector<int> r;
public:
    vector<int> inorderTraversal(TreeNode* root) {
      if (!root)
      {
          return r;
      }
      
      
      TreeNode* leftTree = root->left;
      TreeNode* rightTree = root->right;

      // 0 root
      // 1 left
      // 2 right
      int state = 1;
      visitChildTree(leftTree);

      state=0;
      visitRoot(root);

      state=2;
      visitChildTree(rightTree);

      //assert(r.size() == 7);
      return r;
    }


  void visitRoot(TreeNode* root)
  {
    r.push_back(root->val);
  }


  void visitChildTree(TreeNode* childTree)
  {
    if (!childTree)  
    {
        return;
    }
    
    int state  = 1;
    std::vector<TreeNode*> visited_root_vec;
    TreeNode* cur = childTree;

  State1:  
    while(cur->left)
    {
        visited_root_vec.push_back(cur);     
        cur = cur->left;
    }
   

    //assert(0);
    //
    
    if (cur->right)
    { 
      visited_root_vec.push_back(cur);
    }
    else
    {
       r.push_back(cur->val);
    }

  State0:
    state = 0;

    TreeNode* recentParent = NULL;
    if (visited_root_vec.size()>0)
    {
         recentParent =  visited_root_vec.back();
         
         r.push_back(recentParent->val);
         visited_root_vec.pop_back();
    }
    else
    {
      recentParent = cur;
      cur = NULL;
    }
 

    
    if (r.size() == 0)
    {
      return;
    }

    state =2;
    //assert(0);
    if (!recentParent)
    {
      return;
    }

    if(recentParent->right)
    {
      
      cur = recentParent->right;
      //assert(0);
      if (!cur->left && !cur->right)
      {
        //assert(0);
        state = 2;
        r.push_back(cur->val);
        state = 0;
        goto State0;
      }
      else
      {

          #ifdef Debug_State
          std::cout<<"1";
          #endif
          state = 1;
          goto State1;    
      }

    }
    else
    {
      state = 0;
#ifdef Debug_State
      std::cout<<"0";
#endif      
      goto State0;
    }
  }
};


TreeNode* constructTree1()
{
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6); 
    root->right->right = new TreeNode(7);


    return root;

}


TreeNode* constructTree2()
{
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(1);
    

    
    root->left->right = new TreeNode(2);
    


    return root;

}


TreeNode* constructTree3()
{
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(1);
    

    
    root->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    


    return root;

}


int main(int argc, char const *argv[])
{

  {
    Solution solution;
    TreeNode* tree = constructTree1();
    std::vector<int> result = solution.inorderTraversal(tree);
    std::cout<<std::endl;
    for (int i = 0; i < result.size(); ++i)
    {
        /* code */
        std::cout<<" "<<result[i]<<" ";
    }
    std::cout<<std::endl;
  }


  {
    Solution solution;
    TreeNode* tree = constructTree2();
    std::vector<int> result = solution.inorderTraversal(tree);
    std::cout<<std::endl;
    for (int i = 0; i < result.size(); ++i)
    {
        /* code */
        std::cout<<" "<<result[i]<<" ";
    }
    std::cout<<std::endl;
  }


  {
    Solution solution;
    TreeNode* tree = constructTree3();
    std::vector<int> result = solution.inorderTraversal(tree);
    std::cout<<std::endl;
    for (int i = 0; i < result.size(); ++i)
    {
        /* code */
        std::cout<<" "<<result[i]<<" ";
    }
    std::cout<<std::endl;
  }
    
    

    return 0;
}

