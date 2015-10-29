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
#include "assert.h"
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

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
        
        
        
loop:        
        // init resultNodes_copy
        resultNodes_copy.clear();

        int size = resultNodes.size();
        int leaf_nodes_counter = 0;
        for (int i=0;i<size ;i++)
        {
            vector<TreeNode*> t = resultNodes[i];
            TreeNode* last = *(t.end()-1);
            if (isLeaf(last))
            {
                leaf_nodes_counter++;
                resultNodes_copy.push_back(t);
                continue;
            }
            else if (hasSingleChild(last))
            {
                if (last->left)
                {
                    t.push_back(last->left);
                    resultNodes_copy.push_back(t);
                }
                
                if (last->right)
                {
                    t.push_back(last->right);
                    resultNodes_copy.push_back(t);
                }
                
            }
            else
            {
                vector<TreeNode*> left = t;
                vector<TreeNode*> right = t;
                left.push_back(last->left);
                right.push_back(last->right);
                
                resultNodes_copy.push_back(left);
                resultNodes_copy.push_back(right);
                //cout<<endl<<"debug ----- "<<" resultNodes_copy .size " << resultNodes_copy.size()<<endl;
                //cout<<endl<<"---------------------------------debug  begin";
                //debug(resultNodes_copy);
                //cout<<endl<<"---------------------------------debug  end";
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

private:
    void debug(vector<vector<TreeNode*> > v)
    {
        int size  = v.size();
        for (int i = 0; i < size; ++i)
        {
            /* code */
            std::vector<TreeNode*> vi = v[i];
            cout<<endl;
            for (int j = 0; j < vi.size(); ++j)
            {
                /* code */
                TreeNode* node = vi[j];
                if (j!=vi.size()-1)
                {
                    cout<<node->val<<"->";
                }
                else
                {
                    cout<<node->val<<" ";
                }
                
            }
        }
    }
};




TreeNode *insert(TreeNode* node,int val)
{
    if (node == NULL)
    {
        node = new TreeNode(val);
        return node;
    }

    if (val <node->val)
    {
        node->left = insert(node->left,val);
    }
    else 
    if (val>node->val)
    {
        node->right = insert(node->right,val);
    }
    else
    {
        return node;
    }

    return node;
}

TreeNode *constructBST()
{
    // TreeNode* root = NULL;
    // for (int i = 0; i <=50; i++)
    // {
    //     /* code */
    //     root = insert(root,50+i);
    //     root = insert(root,50-i);

    // }
    // return root;


    TreeNode* root = new TreeNode(1);

    root->left  = new TreeNode(2);
    root->right  = new TreeNode(3);

    root->left->left  = new TreeNode(4);
    root->left->right  = new TreeNode(5);
    root->right->left  = new TreeNode(6);
    root->right->right  = new TreeNode(7);


    root->left->left->left  = new TreeNode(8);
    root->left->left->right  = new TreeNode(9);
    root->left->right->left  = new TreeNode(10);
    root->left->right->right  = new TreeNode(11);
    root->right->left->left  = new TreeNode(12);
    root->right->left->right  = new TreeNode(13);
    root->right->right->left  = new TreeNode(14);
    root->right->right->right  = new TreeNode(15);

    return root;
}

void dump(TreeNode *root)
{
    if (root)
    {
        std::cout<<" "<<root->val<<" ";
    }

    if (root&&root->left)
        dump(root->left);

    if (root&&root->right)
        dump(root->right);
}

void dumpResult(vector<string > result)
{
    int size = result.size();
    for (int i = 0; i < size; ++i)
    {
        cout<<"-------------------"<<endl;
        cout<<" "<<result[i]<<" ";
        cout<<"-------------------"<<endl;
    }
}

void test1()
{
    TreeNode *tree = constructBST();
    dump(tree);
    Solution solution;
    vector<string >  result = solution.binaryTreePaths(tree);
    dumpResult(result);
    cout<<endl;
}


int  main(int argc, char const *argv[])
{
    test1();
    return 0;
}
