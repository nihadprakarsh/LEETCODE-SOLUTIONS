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
    TreeNode* ans = nullptr;
    int find(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root) return 0;
        int flg1 = root==p||root==q?1:0;
        int flg2 = find(root->left,p,q);
        int flg3 = find(root->right,p,q);
        int c = flg1+flg2+flg3;
        // cout<<c<<endl;
        if(c>=2 && ans == nullptr) swap(ans,root);
        return c;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find(root,p,q);
        return ans;
    }
};