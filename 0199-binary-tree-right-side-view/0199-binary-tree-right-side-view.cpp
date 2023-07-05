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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<int> v;
        q.push(root);
        while(!q.empty()){
            int c=0;
            int sz = q.size();
            while(sz--){
                auto node = q.front();
                q.pop();
                if(c==0) v.push_back(node->val),c=1;
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }
        return v;
    }
};