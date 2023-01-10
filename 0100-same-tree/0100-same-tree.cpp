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
    bool find(TreeNode* p, TreeNode* q)
    {
        if((!p && q) || (!q && p)) return false;
        if(!p && !q) return true;
        if(p->val != q->val) return false;
        return find(p->left,q->left) && find(p->right,q->right);
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return find(p,q);
    }
};