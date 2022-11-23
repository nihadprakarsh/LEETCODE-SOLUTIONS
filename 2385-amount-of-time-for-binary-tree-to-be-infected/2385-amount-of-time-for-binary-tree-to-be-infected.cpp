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
    void getAdj(TreeNode* root, vector<int> adj[])
    {
        if(root->left)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            getAdj(root->left, adj);
        }
        if(root->right)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            getAdj(root->right,adj);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        vector<int> adj[100001];
        getAdj(root, adj);
        vector<int> vis(100001,0);
        
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        int ans = -1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int node = q.front();
                q.pop();
                for(auto nodes : adj[node])
                {
                    if(!vis[nodes]){
                    vis[nodes] = 1;
                    q.push(nodes);
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};