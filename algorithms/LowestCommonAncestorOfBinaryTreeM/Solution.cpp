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
#include <vector>
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// class Solution {
//     vector<TreeNode*> ancestors;
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         // special case
//         if (root == NULL)
//         {
//             if (ancestors.size() >0)
//             {
//                 return ancestors.back();    
//             }
//             else
//             {
//                 return NULL;
//             }
//         }
        
//         if (p == NULL || q == NULL)
//         {
//             if (ancestors.size() >0)
//             {
//                 return ancestors.back();    
//             }
//             else
//             {
//                 return NULL;
//             }
//         }
        


        
        
//         TreeNode* cur = root;
//         TreeNode* r0 = commonAncestor_i(cur,p,q);
//         if (r0 != NULL)
//         {
//            ancestors.push_back(r0);   
//         }
//         else
//         {
//             return NULL;
//         }
        
//         while(cur)
//         {
//             TreeNode* r1 = commonAncestor_i(cur->left,p,q);
//             TreeNode* r2 = commonAncestor_i(cur->right,p,q);
         
//             if (r1 != NULL)
//             {
//                 ancestors.push_back(r1);  
//                 cur = r1;
//                 continue;
//             }
//             else  if (r2 != NULL)
//             {
//                 ancestors.push_back(r2);  
//                 cur = r2;
//                 continue;
//             }
//             else
//             {
//                 break;
//             }
//         }
        
//         if (ancestors.size() >0)
//         {
//             return ancestors.back();    
//         }
//         else
//         {
//             return NULL;
//         }
//     }
    
//     private:
//     bool isAncestor(TreeNode* p1,TreeNode* p2)
//     {
//         if (!p1 || !p2)
//         {
//             return false;
//         }
        
//         bool direct =  (p1->left == p2 || p1->right == p2);
//         if (direct)
//         {
//             return true;
//         }
//         else
//         {
//             return isAncestor( p1->left,p2) || isAncestor( p1->right,p2);
//         }
//     }
    
    
//     TreeNode* commonAncestor_i(TreeNode* root, TreeNode* p, TreeNode* q) {
//         // special case
//         if (root == NULL)
//         {
            
//             return NULL;
//         }
        
//         if (p == NULL || q == NULL)
//         {
           
//             return NULL;
//         }
        
//         if (isAncestor(p,q))
//         {
//             return p;
//         }
        
//         if (isAncestor(q,p))
//         {
//             return q;
//         }
        
//         if (isAncestor(root,p) && isAncestor(root,q))
//         {
//             return root;
//         }
        
//         return NULL;
//     }
// };


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> ancestors;
        if (root != NULL)
        {
            ancestors.push_back(root);    
        }
        
        if (isAncestor(p,q))
        {
            return p;
        }
        
        if (isAncestor(q,p))
        {
            return q;
        }
        
        TreeNode* cur = root;
        while(cur)
        {
            if (isRootAncestor(cur->left,p,q))
            {
                ancestors.push_back(cur->left);
                cur = cur->left;
            }
            else if (isRootAncestor(cur->right,p,q))
            {
                ancestors.push_back(cur->right);
                cur = cur->right;
            }
            else
            {
                break;
            }
        }
        
        if (ancestors.size() >0)
        {
            return ancestors.back();
        }
        else
        {
            return NULL;
        }
       
        
    }
    
    private:
    bool isRootAncestor(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if (root == NULL)
        {
            return false;
        }
        
        if (p == NULL || q == NULL)
        {
            return false;
        }
        
        return isAncestor(root,p) && isAncestor(root,q); 
    }
    
    bool isAncestor(TreeNode* p1,TreeNode* p2)
    {
        if (!p1 || !p2)
        {
            return false;
        }
        
        bool direct =  (p1 == p2 ||p1->left == p2 || p1->right == p2);
        if (direct)
        {
            return true;
        }
        else
        {
            return isAncestor( p1->left,p2) || isAncestor( p1->right,p2);
        }
    }
};
TreeNode *constructTree()
{
    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    
    root->right->right->left = new TreeNode(8);
    root->right->right->left->right = new TreeNode(9);
    root->right->right->left->left = new TreeNode(10);


    return root;
}

int main(int argc,char** argv)
{
    Solution solution;
    TreeNode *root = constructTree();
    {
        TreeNode* lowest = solution.lowestCommonAncestor(root,root->left,root->right);
        std::cout<<"lowestCommonAncestor is "<<lowest->val<<std::endl;
    }

    {
        TreeNode* lowest = solution.lowestCommonAncestor(root,root->right,root->left->right);
        std::cout<<"lowestCommonAncestor is "<<lowest->val<<std::endl;
    }

    {
        TreeNode* lowest = solution.lowestCommonAncestor(root,root->left,root->left->right);
        std::cout<<"lowestCommonAncestor is "<<lowest->val<<std::endl;
    }

    {
        TreeNode* lowest = solution.lowestCommonAncestor(root,root->left,root->right->right);
        std::cout<<"lowestCommonAncestor is "<<lowest->val<<std::endl;
    }


    
    return 0;
}

