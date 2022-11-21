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
    int ans = 0;
    void dfs(TreeNode* root, map<int,int>&m)
    {
        if(root->left == nullptr && root->right==nullptr)
        {
            m[root->val]++;
            int c = 0;
            for(auto it : m)
            c+=it.second%2;
            if(m.size()==1 || c <= 1)
                ans++;
            m[root->val]--;
        }
        
        m[root->val]++;
        if(root->left) dfs(root->left,m);
        if(root->right) dfs(root->right,m);
        m[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int> m;
        dfs(root,m);
        return ans;
    }
};