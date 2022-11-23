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
    vector<int> ans;
    void getAdj(TreeNode* root, vector<int> adj[])
    {
        if(root->left)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            getAdj(root->left,adj);
        }
        if(root->right)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            getAdj(root->right,adj);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target->val};
        vector<int> adj[501];
        vector<int> vis(501,0);
        getAdj(root,adj);
        
        queue<pair<int,int>> q;
        q.push({target->val,0});
        vis[target->val] = 1;
        
        while(!q.empty())
        {
            auto node = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(node != target->val && steps == k)
            ans.push_back(node);
            for(auto nodes : adj[node])
            {
                if(!vis[nodes]){
                vis[nodes] = 1;
                q.push({nodes,steps+1});
                }
            }
        }
        return ans;
    }
};