/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        v.push_back({root->val});
        while(!q.empty())
        {
            vector<int> temp;
            int sz = q.size();
            while(sz--)
            {
                auto node = q.front();
                q.pop();
                if(node->left){ temp.push_back(node->left->val); q.push(node->left);}
                else temp.push_back(-1);
                if(node->right){ temp.push_back(node->right->val); q.push(node->right);}
                else temp.push_back(-1);
            }
            v.push_back(temp);
        }
        v.pop_back();
        
        int n = v.size();
        bool flag= true;
        for(auto vec : v)
        {
            
            if(n>1)
            {
                for(int i =vec.size()-1; i>=0; --i)
                if(vec[i] == -1) return false;
            }
            
            else
            {
                for(int i=vec.size()-1; i >=0; --i)
                {
                    if(vec[i] != -1) flag = false;
                    else if(vec[i] == -1 && flag == false) return false;
                }
            }
            n--;
        }
        return true;
    }
};